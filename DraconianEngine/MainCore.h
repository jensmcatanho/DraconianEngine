#pragma once

#include <GL/glew.h>
#include "Singleton.h"

namespace Draconian {

class Window;

enum class RenderingState {RUNNING, EXIT};

class MainCore : public Singleton<MainCore> {
	friend class Window;

	public:
		MainCore();
		~MainCore();

		void initSystems();
		void mainLoop();
		void startRendering();

		static MainCore &getSingleton();
		static MainCore *getSingletonPtr();

	private:
		Window *m_Window;
		RenderingState currentState;
};

}