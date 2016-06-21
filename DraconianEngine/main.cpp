#define VERTEX_PATH "vertex.glsl"
#define FRAG_PATH "frag.glsl"

#include "IndexBufferObject.h"
#include "VertexArrayObject.h"
#include "VertexBufferObject.h"

#include "Simple2DRenderer.h"
#include "Batch2DRenderer.h"
#include "StaticSprite.h"
#include "Sprite.h"
#include "Timer.h"

#include "MainCore.h"
#include "GLFWWindow.h"
#include "SDLWindow.h"

#include <time.h>

#include "Shader.h"
#include "ShaderProgram.h"

#define BATCH_RENDERER 0

#if 1
int main(int argc, char *argv[]) {
	Draconian::MainCore m;
	Draconian::GLFWWindow w("OpenGL", 800, 600);

	if (!w.create())
		return -1;

	// Create and compile the vertex shader
	Draconian::Shader vertex(VERTEX_PATH, GL_VERTEX_SHADER);
	if (!vertex.compile()) {
		std::cout << vertex.infoLog() << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << "Vertex shader created and compiled." << std::endl;

	// Create and compile the fragment shader
	Draconian::Shader fragment(FRAG_PATH, GL_FRAGMENT_SHADER);
	if (!fragment.compile()) {
		std::cout << fragment.infoLog() << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << "Fragment shader created and compiled." << std::endl;

	// Link the vertex and fragment shader into a shader program
	Draconian::ShaderProgram shaderProgram(vertex.getID(), fragment.getID());

	if (!shaderProgram.initialize()) {
		std::cout << shaderProgram.infoLog() << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << "Shaders linked." << std::endl;

#if BATCH_RENDERER
	Draconian::Sprite sprite(-0.5, -0.5, 1.0, 1.0, glm::vec4(0, 0, 0, 0));
	//Draconian::Sprite sprite2(0.5, 0, 0.5, 0.5, glm::vec4(0, 0, 0, 0));
	Draconian::Batch2DRenderer renderer;
	//renderer.m_VBO->setLayout(;
#else
	Draconian::StaticSprite sprite(-0.5, -0.5, 1.0, 1.0, glm::vec4(0, 0, 0, 0), shaderProgram);
	//Draconian::StaticSprite sprite2(0.5, 0, 0.5, 0.5, glm::vec4(0, 0, 0, 0), shaderProgram);
	Draconian::Simple2DRenderer renderer;
#endif
	glUniform2f(glGetUniformLocation(shaderProgram.getID(), "light_pos"), 1.0f, 0.5f);

	std::cout << "Position: " << glGetAttribLocation(shaderProgram.getID(), "position") << std::endl;
	std::cout << "Color: " << glGetAttribLocation(shaderProgram.getID(), "color") << std::endl;

	/*Draconian::Timer time;
	float timer = 0.0f;
	unsigned int frames = 0;
	*/
	while (m.getCurrentState() != Draconian::RenderingState::EXIT) {
		w.clear();

#if BATCH_RENDERER
		renderer.begin();
#endif
		renderer.submit(&sprite);
		//renderer.submit(&sprite2);
#if BATCH_RENDERER
		renderer.end();
#endif
		renderer.flush();	

		//if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		//	glfwSetWindowShouldClose(window, GL_TRUE);
		
		w.swapBuffers();
		w.processInput();

		float x, y;
		w.getMousePosition(x, y);
		glUniform2f(glGetUniformLocation(shaderProgram.getID(), "light_pos"), (float)(x * 16.0f / 800.0f), (float)(9.0f - y * 9.0f / 600.0f));
		/*frames++;
		if (time.elapsed() - timer > 1.0f) {
			timer += 1.0f;
			std::cout << frames << " FPS" << std::endl;
			frames = 0;
		}*/
	}

	return EXIT_SUCCESS;
}
#endif
#if 0
int main(int argc, char *argv[]) {
	Draconian::MainCore m;
	m.mainLoop();

	return 0;
}
#endif