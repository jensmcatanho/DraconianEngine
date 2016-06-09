#pragma once

// NOTE: FileManager will be a Singleton in the future but, for testing purposes, it's not a Singleton yet.

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

namespace Draconian {

class FileManager {
	public:
		FileManager();
		~FileManager();

		std::stringstream getStringStream(std::string) const;
};

}