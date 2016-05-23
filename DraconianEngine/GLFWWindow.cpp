#include "GLFWWindow.h"

namespace Draconian {

GLFWWindow::GLFWWindow() {

}


GLFWWindow::~GLFWWindow() {

}

void GLFWWindow::initialize(const std::string name, int width, int height, bool fullscreen) {
	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW." << std::endl;

	}

	mScreen = glfwCreateWindow(width, height, "OpenGL", nullptr, nullptr);
	glfwMakeContextCurrent(mScreen);

}

void GLFWWindow::destroy() {

}

}