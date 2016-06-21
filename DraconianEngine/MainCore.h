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
		LogManager *m_LogManager;
		Window *m_Window;
		RenderingState currentState;

	public:
		FileManager *m_FileManager;
};

}