#include "Window.h"

namespace Draconian {

Window::Window(char *title, int width, int height) : 
	m_Title(title),
	m_Width(width),
	m_Height(height) {

	std::fill(m_Keys, m_Keys + sizeof(m_Keys), false);
	std::fill(m_MouseButtons, m_MouseButtons + sizeof(m_MouseButtons), false);
}

Window::~Window() {

}

bool Window::isKeyPressed(unsigned int keyCode) {
	assert(keyCode < MAX_KEYS);

	return m_Keys[keyCode];
}

bool Window::isMouseButtonPressed(unsigned int keyCode) {
	assert(keyCode < MAX_BUTTONS);

	return m_MouseButtons[keyCode];
}

void Window::getMousePosition(float &x, float &y) {
	m_MouseX = x;
	m_MouseY = y;
}

}