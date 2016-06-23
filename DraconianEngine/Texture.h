#pragma once

#include "Prerequisites.h"

namespace Draconian {

class Texture {
	public:
		Texture(const std::string &, GLenum);
		~Texture();

		void initialize();

		inline void bind() const;
		inline void unbind() const;
		
		inline void setTexParameter(GLenum, GLenum, GLint) const;
		inline void setTexParameter(GLenum, GLenum, GLfloat) const;
		inline void setTexParameter(GLenum, GLenum, GLint *) const;
		inline void setTexParameter(GLenum, GLenum, GLfloat *) const;

		// TODO: Declare these methods
		inline void getTexParameter(GLenum, GLenum, GLint *) const;
		inline void getTexParameter(GLenum, GLenum, GLfloat *) const;

		inline GLuint getID() const;
		inline unsigned int getWidth() const;
		inline unsigned int getHeight() const;

	private:
		GLuint m_ID;
		GLenum m_Type;
		std::string m_Path;
		unsigned int m_Width;
		unsigned int m_Height;
};

inline void Texture::bind() const {
	glBindTexture(m_Type, m_ID);
}

inline void Texture::unbind() const {
	glBindTexture(m_Type, 0);
}

// Encapsulation of glTexParameteri/iv/f/fv 
inline void Texture::setTexParameter(GLenum target, GLenum pname, GLint param) const {
	glTexParameteri(target, pname, param);
}

inline void Texture::setTexParameter(GLenum target, GLenum pname, GLfloat param) const {
	glTexParameterf(target, pname, param);
}

inline void Texture::setTexParameter(GLenum target, GLenum pname, GLint *param) const {
	glTexParameteriv(target, pname, param);
}

inline void Texture::setTexParameter(GLenum target, GLenum pname, GLfloat *param) const {
	glTexParameterfv(target, pname, param);
}

inline GLuint Texture::getID() const {
	return m_ID;
}

inline unsigned int Texture::getWidth() const {
	return m_Width;
}

inline unsigned int Texture::getHeight() const {
	return m_Height;
}

}