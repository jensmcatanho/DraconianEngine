#pragma once

#include "Prerequisites.h"
#include "Singleton.h"
#include <FreeImage.h>

namespace Draconian {

class FileManager : public Singleton<FileManager> {
	public:
		FileManager();
		~FileManager();

		std::stringstream getStringStream(std::string) const;
		BYTE *loadImage(const char *, size_t *, size_t *) const;

		static FileManager &getSingleton();
		static FileManager *getSingletonPtr();

	private:
		std::ifstream m_InputFileStream;
		std::ofstream m_OutputFileStream;
};

}