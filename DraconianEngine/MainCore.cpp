#include "MainCore.h"

#include "FileManager.h"
#include "GLFWWindow.h"
#include "LogManager.h"
#include "SDLWindow.h"
#include "Shader.h"
#include "ShaderProgram.h"
#include "Win32Timer.h"

namespace Draconian {

template<> MainCore *Singleton<MainCore>::m_Instance = nullptr;

MainCore::MainCore() :
	m_Window(nullptr),
	m_FileManager(nullptr),
	currentState(RenderingState::RUNNING) {

	initSystems();
}


MainCore::~MainCore() {
	delete m_FileManager;
	//delete m_Timer;
	delete m_Window;

}

void MainCore::initSystems() {
	m_Window = new GLFWWindow("OpenGL", 800, 600);
	//m_Window = new SDLWindow("OpenGL", 800, 600);
	m_LogManager = new LogManager();
	m_FileManager = new FileManager();
	//m_Timer = new Win32Timer();
	
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

MainCore &MainCore::getSingleton() {
	return *m_Instance;
}

MainCore *MainCore::getSingletonPtr() {
	return m_Instance;
}


}