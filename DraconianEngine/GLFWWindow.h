#pragma once

#include "Window.h"

#include <GLFW/glfw3.h>

namespace Draconian {

class GLFWWindow : public Window {
	public:
		GLFWWindow(std::string, int, int);
		~GLFWWindow();

		bool create() override;
		void swapBuffers() override;
		bool closed() override;
		void processInput() override;

	private:
		GLFWwindow *m_Window;

		friend static void resize_window(GLFWwindow *, int, int);
		friend static void key_callback(GLFWwindow *, int, int, int, int);
		friend static void mouse_callback(GLFWwindow *, int, int, int);
		friend static void cursor_position_callback(GLFWwindow *, double, double);


};

}