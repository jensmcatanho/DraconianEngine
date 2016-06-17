#include "GLFWWindow.h"

namespace Draconian {

GLFWWindow::GLFWWindow(std::string title, uint width, uint height) :
	Window(title, width, height),
	m_Window(nullptr) {

}

GLFWWindow::~GLFWWindow() {
	glfwTerminate();
}

bool GLFWWindow::create() {
	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW." << std::endl;
		return false;
	}

	if (!(m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr))) {
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

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	return true;
}

void GLFWWindow::swapBuffers() {
	glfwSwapBuffers(m_Window);
}

void GLFWWindow::processInput() {
	std::stringstream title;
	title << "OpenGL " << glGetString(GL_VERSION) << " " << "x: " << m_MouseX << " " << "y: " << m_MouseY;
	m_Title = title.str();

	glfwSetWindowTitle(m_Window, m_Title.c_str());

	if (glfwWindowShouldClose(m_Window))
		changeState(RenderingState::EXIT);

	glfwPollEvents();
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