#include "LogManager.h"

namespace Draconian {

template<> LogManager *Singleton<LogManager>::m_Instance = nullptr;

LogManager::LogManager() {

}


LogManager::~LogManager() {

}

LogManager &LogManager::getSingleton() {
	return *m_Instance;
}

LogManager *LogManager::getSingletonPtr() {
	return m_Instance;
}

}