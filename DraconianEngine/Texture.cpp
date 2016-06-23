#include "Texture.h"

#include "FileManager.h"
#include <FreeImage.h>

namespace Draconian {

Texture::Texture(const std::string &path, GLenum type) :
	m_Path(path),
	m_Type(type) {

	initialize();
}


Texture::~Texture() {
	glDeleteTextures(1, &m_ID);
}

void Texture::initialize() {
	BYTE *pixels = FileManager::getSingleton().loadImage(m_Path.c_str(), &m_Width, &m_Height);

	glGenTextures(1, &m_ID);
	glBindTexture(m_Type, m_ID);
	setTexParameter(m_Type, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	setTexParameter(m_Type, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(m_Type, 0, GL_RGB, m_Width, m_Height, 0, GL_BGR, GL_UNSIGNED_BYTE, pixels);
	glBindTexture(m_Type, 0);
}

}