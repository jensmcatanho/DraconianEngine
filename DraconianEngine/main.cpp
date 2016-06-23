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

#include "Prerequisites.h"

#define BATCH_RENDERER 0

#if 0
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


using namespace std;

const GLchar* vertexSource =
"#version 130\n"
"in vec2 position;"
"in vec3 color;"
"out vec3 Color;"
"void main() {"
"   Color = color;"
"   gl_Position = vec4(position, 0.0, 1.0);"
"}";

const GLchar* fragmentSource =
"#version 130\n"
"in vec3 Color;"
"out vec4 outColor;"
"void main() {"
"   outColor = vec4(Color, 1.0);"
"}";

#if 1
int main(int argc, char *argv[]) {

	// GLFW initialization
	if (!glfwInit()) {
		cout << "Failed to initialize GLFW." << endl;
		return -1;

	}
	cout << "GLFW initialized." << endl;


	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	printf("OpenGL version: %s\n", glGetString(GL_VERSION));
	cout << glGetString(GL_EXTENSIONS) << endl;
	cout << "Window and context created." << endl;

	// GLEW initialization
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		cout << "Failed to initialize GLEW." << endl;
		return -1;

	}
	cout << "GLEW initialized." << endl;

	GLfloat vertices[] = {
		-0.5f, 0.5f, 1.0f, 0.0f, 0.0f, // Top-left
		0.5f, 0.5f, 0.0f, 1.0f, 0.0f, // Top-right
		0.5f, -0.5f, 0.0f, 0.0f, 1.0f, // Bottom-right
		-0.5f, -0.5f, 1.0f, 1.0f, 1.0f  // Bottom-left
	};

	// Create Vertex Array Object
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	cout << "VAO created and binded." << endl;

	//Vertex Buffer Object
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	cout << "VBO created and binded." << endl;

	// Element Array Buffer
	GLuint elements[] = {
		0, 1, 2,
		2, 3, 0
	};

	GLuint eab;
	glGenBuffers(1, &eab);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eab);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);
	cout << "EAB created and binded." << endl;

	// Create and compile the vertex shader
	GLint status;
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);

	if (!status) {
		// Vertex shader error handling
		char errorLog[512];
		glGetShaderInfoLog(vertexShader, 512, NULL, errorLog);

		cout << errorLog << endl;
		glfwTerminate();
		return -1;
	}
	cout << "Vertex shader created and compiled." << endl;

	// Create and compile the fragment shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);

	if (!status) {
		// Fragment shader error handling
		char errorLog[512];
		glGetShaderInfoLog(fragmentShader, 512, NULL, errorLog);

		cout << errorLog << endl;
		glfwTerminate();
		return -1;
	}
	cout << "Fragment shader created and compiled." << endl;

	// Link the vertex and fragment shader into a shader program
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glBindFragDataLocation(shaderProgram, 0, "outColor");
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);
	cout << "Shaders linked." << endl;

	// Specify the layout of the vertex data
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);

	GLint colAttrib = glGetAttribLocation(shaderProgram, "color");
	glEnableVertexAttribArray(colAttrib);
	glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));
	cout << "Layout of the vertex data specified." << endl;

	// Get the location of the color uniform
	GLint uniColor = glGetUniformLocation(shaderProgram, "Color");

	while (!glfwWindowShouldClose(window)) {
		glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Prepare to close the application
	glDeleteProgram(shaderProgram);
	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &vao);
	glDeleteBuffers(1, &eab);

	return 0;
}
#endif