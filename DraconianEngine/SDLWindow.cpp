#include "SDLWindow.h"

namespace Draconian {

SDLWindow::SDLWindow(std::string title, uint width, uint height) :
	Window(title, width, height),
	m_Window(nullptr) {

}


SDLWindow::~SDLWindow() {
	SDL_DestroyWindow(m_Window);
	SDL_Quit();
}

bool SDLWindow::create() {
	SDL_Init(SDL_INIT_EVERYTHING);

	if (!(m_Window = SDL_CreateWindow(m_Title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Width, m_Height, SDL_WINDOW_OPENGL))) {
		std::cerr << "Failed to create SDL window." << std::endl;
		return false;
	}

	SDL_GLContext glContext;

	if (!(glContext = SDL_GL_CreateContext(m_Window))) {
		std::cerr << "Failed to create GL context." << std::endl;
	}

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cerr << "Failed to initialize GLEW." << std::endl;
		return false;

	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;
	return true;
}

void SDLWindow::swapBuffers() {
	SDL_GL_SwapWindow(m_Window);
}

void SDLWindow::processInput() {
	SDL_Event e;

	while (SDL_PollEvent(&e)) {
		switch (e.type) {
			case SDL_QUIT:
				changeState(RenderingState::EXIT);
				break;
			case SDL_MOUSEMOTION:
				m_MouseX = e.motion.x;
				m_MouseY = e.motion.y;
				break;
		}
	}


	std::stringstream title;
	title << "OpenGL " << glGetString(GL_VERSION) << " " << "x: " << m_MouseX << " " << "y: " << m_MouseY;
	m_Title = title.str();

	SDL_SetWindowTitle(m_Window, m_Title.c_str());
}

}