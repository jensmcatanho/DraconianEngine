#include "FileManager.h"

namespace Draconian {

template<> FileManager *Singleton<FileManager>::m_Instance = nullptr;

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

BYTE *FileManager::loadImage(const char *name, size_t *width, size_t *height) const {
	FREE_IMAGE_FORMAT imageFormat = FIF_UNKNOWN;
	FIBITMAP *dib = nullptr;

	imageFormat = FreeImage_GetFileType(name, 0);
	
	if (imageFormat == FIF_UNKNOWN)
		imageFormat = FreeImage_GetFIFFromFilename(name);

	if (imageFormat == FIF_UNKNOWN)
		return nullptr;

	if (FreeImage_FIFSupportsReading(imageFormat))
		dib = FreeImage_Load(imageFormat, name);

	if (!dib)
		return nullptr;

	BYTE *result = FreeImage_GetBits(dib);
	*width = FreeImage_GetWidth(dib);
	*height = FreeImage_GetHeight(dib);

	return result;
}

FileManager &FileManager::getSingleton() {
	return *m_Instance;
}

FileManager *FileManager::getSingletonPtr() {
	return m_Instance;
}


}