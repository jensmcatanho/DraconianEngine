#pragma once

#include "Prerequisites.h"
#include "Singleton.h"

namespace Draconian {

class MainCore : public Singleton<MainCore> {
	friend class Window;

	public:
		MainCore();
		~MainCore();

		void initSystems();
		void mainLoop();
		void startRendering();

		inline RenderingState getCurrentState() const { return currentState; }

		static MainCore &getSingleton();
		static MainCore *getSingletonPtr();

	private:
		RenderingState currentState;

		// Singletons
		FileManager *m_FileManager;
		LogManager *m_LogManager;
		Timer *m_Timer;
		Window *m_Window;
};

}