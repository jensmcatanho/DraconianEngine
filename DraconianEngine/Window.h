#pragma once

#include "Prerequisites.h"

namespace Draconian {

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

class Window {
	public:
		Window(std::string, uint, uint);
		virtual ~Window();

		void changeState(RenderingState) const;
		void clear();

		// Framework-specific methods
		virtual bool create() = 0;
		virtual void swapBuffers() = 0;
		virtual void processInput() = 0;

		bool isKeyPressed(uint);
		bool isMouseButtonPressed(uint);
		void getMousePosition(float &, float &);

	protected:
		std::string m_Title;
		uint m_Width;
		uint m_Height;
		bool m_Keys[MAX_KEYS];
		bool m_MouseButtons[MAX_BUTTONS];

		double m_MouseX;
		double m_MouseY;

};

}
