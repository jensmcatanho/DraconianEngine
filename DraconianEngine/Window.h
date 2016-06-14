#pragma once

#include <iostream>
#include <sstream>
#include <cassert>

#include <GL/glew.h>

#include "MainCore.h"

namespace Draconian {

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

class Window {
	public:
		Window(std::string, int, int);
		virtual ~Window();

		inline void changeState(RenderingState) const;
		void clear();

		// Framework-specific methods
		virtual bool create() = 0;
		virtual void swapBuffers() = 0;
		virtual bool closed() = 0;
		virtual void processInput() = 0;

		bool isKeyPressed(unsigned int);
		bool isMouseButtonPressed(unsigned int);
		void getMousePosition(float &, float &);

	protected:
		std::string m_Title;
		int m_Width;
		int m_Height;
		bool m_Keys[MAX_KEYS];
		bool m_MouseButtons[MAX_BUTTONS];

		double m_MouseX;
		double m_MouseY;

};

inline void Window::changeState(RenderingState target) const {
	MainCore::getSingleton().currentState = target;
}

}
