#define GLEW_STATIC
#define VERTEX_PATH "vertex.glsl"
#define FRAG_PATH "frag.glsl"

#include "Draconian.h"

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

	GLfloat vertices[] = {
		0.0f, 0.5f,
		0.5f, -0.5f,
		-0.5f, -0.5f
	};

	// Create Vertex Array Object
	Draconian::VertexArrayObject vao;
	vao.bind();
	std::cout << "VAO created and binded." << std::endl;

	//Vertex Buffer Object
	Draconian::VertexBufferObject vbo(sizeof(vertices), vertices);
	std::cout << "VBO created and binded." << std::endl;

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

	// Specify the layout of the vertex data
	GLint posAttrib = glGetAttribLocation(shaderProgram.getID(), "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
	std::cout << "Layout of the vertex data specified." << std::endl;

	while (!glfwWindowShouldClose(window)) {
		glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Prepare to close the application
	glfwTerminate();

	return EXIT_SUCCESS;
}
