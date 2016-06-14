#include "MainCore.h"

#include "Window.h"
#include "SDLWindow.h"
#include "GLFWWindow.h"

namespace Draconian {

template<> MainCore *Singleton<MainCore>::m_Instance = nullptr;

MainCore &MainCore::getSingleton() {
	return *m_Instance;
}

MainCore *MainCore::getSingletonPtr() {
	return m_Instance;
}

MainCore::MainCore() :
	m_Window(nullptr),
	currentState(RenderingState::RUNNING) {

	initSystems();
}


MainCore::~MainCore() {
	delete m_Window;

}

void MainCore::initSystems() {
	m_Window = new GLFWWindow("OpenGL", 800, 600);
	//m_Window = new SDLWindow("OpenGL", 800, 600);
	
	if (!m_Window->create()) {
		// Later will print in the log system
		std::cerr << "Failed to initialize window" << std::endl;
	}

	// More to come..
}

void MainCore::mainLoop() {
	while (currentState != RenderingState::EXIT) {
		m_Window->clear();

		startRendering();

		m_Window->swapBuffers();
		m_Window->processInput();
	}

}

void MainCore::startRendering() {

}

}