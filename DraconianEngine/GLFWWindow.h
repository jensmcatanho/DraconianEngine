#pragma once

#include "RenderWindow.h"

namespace Draconian {

class GLFWWindow : public RenderWindow {
	public:
		GLFWWindow();
		virtual ~GLFWWindow();

		void initialize(const std::string, int, int, bool);
		void destroy();
		inline void swapBuffers();

	private:
		GLFWwindow* mScreen;

};

inline void GLFWWindow::swapBuffers() {
	glfwSwapBuffers(mScreen);
}

}