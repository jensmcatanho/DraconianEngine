#define VERTEX_PATH "vertex.glsl"
#define FRAG_PATH "frag.glsl"

#include "Draconian.h"

#include "IndexBufferObject.h"
#include "VertexArrayObject.h"
#include "VertexBufferObject.h"

#include "Simple2DRenderer.h"

int main(int argc, char *argv[]) {
	// GLFW initialization
	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW." << std::endl;
		return -1;

	}
	std::cout << "GLFW initialized." << std::endl;

	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	std::cout << "Window and context created." << std::endl;

	// GLEW initialization
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cerr << "Failed to initialize GLEW." << std::endl;
		return -1;

	}
	std::cout << "GLEW initialized." << std::endl;

	glm::vec2 vertices[] = {
		glm::vec2(-0.5f,  0.5f),
		glm::vec2( 0.5f,  0.5f),
		glm::vec2( 0.5f, -0.5f),
		glm::vec2(-0.5f, -0.5f)

	};

	GLuint indices[] = {
		0, 1, 2,
		0, 2, 3
	};

	// Create and compile the vertex shader
	Draconian::Shader vertex(VERTEX_PATH, GL_VERTEX_SHADER);
	vertex.initialize();

	if (!vertex.compile()) {
		vertex.infoLog();
		glfwTerminate();

		return EXIT_FAILURE;
	}

	std::cout << "Vertex shader created and compiled." << std::endl;

	// Create and compile the fragment shader
	Draconian::Shader fragment(FRAG_PATH, GL_FRAGMENT_SHADER);
	fragment.initialize();

	if (!fragment.compile()) {
		fragment.infoLog();
		glfwTerminate();

		return EXIT_FAILURE;
	}
	std::cout << "Fragment shader created and compiled." << std::endl;

	// Link the vertex and fragment shader into a shader program
	Draconian::ShaderProgram shaderProgram(vertex.getID(), fragment.getID());

	if (!shaderProgram.initialize()) {
		shaderProgram.infoLog();
		glfwTerminate();

		return EXIT_FAILURE;
	}
	std::cout << "Shaders linked." << std::endl;

	Draconian::Renderable2D sprite(glm::vec3(-0.5, 0, 0), glm::vec2(0.5, 0.5), glm::vec4(0, 0, 0, 0), shaderProgram);
	Draconian::Renderable2D sprite2(glm::vec3(0.5, 0, 0), glm::vec2(0.5, 0.5), glm::vec4(0, 0, 0, 0), shaderProgram);
	Draconian::Simple2DRenderer renderer;

	glUniform2f(glGetUniformLocation(shaderProgram.getID(), "light_pos"), 1.0f, 0.5f);

	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		renderer.submit(&sprite);
		renderer.submit(&sprite2);
		renderer.flush();
		

		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	return EXIT_SUCCESS;
}
