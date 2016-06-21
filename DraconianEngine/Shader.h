#pragma once

#include "Prerequisites.h"

namespace Draconian {

class Shader {
	public:
		Shader(const GLchar*, GLenum);
		~Shader();

		void initialize();
		GLint compile();

		inline GLuint getID() const;
		inline GLenum getType() const;
		inline const GLchar* getCode() const;
		inline int getCodeLength() const;
		inline const GLchar* getPath() const;
		inline std::string infoLog() const;

	private:
		GLuint m_ID;
		GLenum m_Type;
		const GLchar* m_Code;
		int m_CodeLength;
		const GLchar* m_Path;
		char m_Log[512];

};

inline GLuint Shader::getID() const {
	return m_ID;
}

inline GLenum Shader::getType() const {
	return m_Type;
}

inline const GLchar* Shader::getCode() const {
	return m_Code;
}

inline int Shader::getCodeLength() const {
	return m_CodeLength;
}

inline const GLchar* Shader::getPath() const {
	return m_Path;
}

inline std::string Shader::infoLog() const {
	return m_Log;
}

}