#pragma once

#include <iostream>
#include <cassert>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Draconian {

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

class Window {
	public:
		Window(char *, int, int);
		virtual ~Window();

		virtual bool initialize() = 0;
		virtual void clear() = 0;
		virtual void update() = 0;
		virtual bool closed() = 0;

		bool isKeyPressed(unsigned int);
		bool isMouseButtonPressed(unsigned int);
		void getMousePosition(float &, float &);

	protected:
		char *m_Title;
		int m_Width;
		int m_Height;

		bool m_Keys[MAX_KEYS];
		bool m_MouseButtons[MAX_BUTTONS];

		double m_MouseX;
		double m_MouseY;

};

}
