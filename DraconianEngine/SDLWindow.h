#pragma once

#include <SDL.h>
#include "Window.h"

namespace Draconian {

class SDLWindow : public Window {
	public:
		SDLWindow(std::string, int, int);
		~SDLWindow();

		bool create() override;
		void swapBuffers() override;
		void processInput() override;

	private:
		SDL_Window *m_Window;
};

}