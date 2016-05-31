#pragma once

#include "Window.h"

namespace Draconian {

class GLFWWindow : public Window {
	public:
		GLFWWindow(char *, int, int);
		virtual ~GLFWWindow();

		bool initialize() override;
		void clear() override;
		void update() override;
		bool closed() override;

	private:
		GLFWwindow *m_Window;

		friend static void resize_window(GLFWwindow *, int, int);
		friend static void key_callback(GLFWwindow *, int, int, int, int);
		friend static void mouse_callback(GLFWwindow *, int, int, int);
		friend static void cursor_position_callback(GLFWwindow *, double, double);


};

}