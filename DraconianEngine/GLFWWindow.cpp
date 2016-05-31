#include "GLFWWindow.h"

namespace Draconian {

GLFWWindow::GLFWWindow(char *title, int width, int height) :
	Window(title, width, height) {

}

GLFWWindow::~GLFWWindow() {
	glfwTerminate();
}

bool GLFWWindow::initialize() {
	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW." << std::endl;
		return false;
	}

	if (!(m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, nullptr, nullptr))) {
		std::cerr << "Failed to create GLFW window." << std::endl;
		return false;
	}

	glfwMakeContextCurrent(m_Window);
	glfwSetWindowUserPointer(m_Window, this);
	glfwSetWindowSizeCallback(m_Window, resize_window);
	glfwSetKeyCallback(m_Window, key_callback);
	glfwSetMouseButtonCallback(m_Window, mouse_callback);
	glfwSetCursorPosCallback(m_Window, cursor_position_callback);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cerr << "Failed to initialize GLEW." << std::endl;
		return false;

	}
	
	std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;
}

void GLFWWindow::clear() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GLFWWindow::update() {
	glfwPollEvents();
	glfwSwapBuffers(m_Window);
}

bool GLFWWindow::closed() {
	return glfwWindowShouldClose(m_Window) == 1;
}

// GLFW Callbacks
void resize_window(GLFWwindow *w, int width, int height) {
	glViewport(0, 0, width, height);
}

void key_callback(GLFWwindow *w, int key, int scanCode, int action, int mods) {
	GLFWWindow *window = (GLFWWindow *)glfwGetWindowUserPointer(w);
	window->m_Keys[key] = action != GLFW_RELEASE;
}

void mouse_callback(GLFWwindow *w, int button, int action, int mods) {
	GLFWWindow *window = (GLFWWindow *)glfwGetWindowUserPointer(w);
	window->m_MouseButtons[button] = action != GLFW_RELEASE;
}

void cursor_position_callback(GLFWwindow *w, double x, double y) {
	GLFWWindow *window = (GLFWWindow *)glfwGetWindowUserPointer(w);
	window->m_MouseX = x;
	window->m_MouseY = y;
}

}