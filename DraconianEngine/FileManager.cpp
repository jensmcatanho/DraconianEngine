#include "FileManager.h"

namespace Draconian {

FileManager::FileManager() {

}


FileManager::~FileManager() {

}

std::stringstream FileManager::getStringStream(std::string path) const {
	std::ifstream file;
	std::stringstream string_stream;

	file.exceptions(std::ifstream::badbit);

	try {
		file.open(path);
		string_stream << file.rdbuf();
		file.close();

	} catch (std::ifstream::failure e) {
		std::cerr << "Error while reading the file. (Does the file exist?)" << std::endl;
	}

	return string_stream;
}

}