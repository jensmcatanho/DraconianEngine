#pragma once

#include "Prerequisites.h"
#include "Singleton.h"

namespace Draconian {

// Defines how detailed the log is going to be.
enum LogDetail { LD_LOW, LD_NORMAL, LD_DETAILED };

// Defines how important the log is.
enum LogRelevance { LR_TRIVIAL, LR_NORMAL, LR_IMPORTANT };

// Defines the log type.
enum LogType { LT_DEBUG, LT_ERROR, LT_INFO };

class LogManager : public Singleton<LogManager> {
	public:
		LogManager();
		~LogManager();

		static LogManager &getSingleton();
		static LogManager *getSingletonPtr();
};

}