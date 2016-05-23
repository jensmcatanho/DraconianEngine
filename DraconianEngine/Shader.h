#pragma once

#include "Draconian.h"

namespace Draconian{

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
		GLuint mID;
		GLenum mType;
		const GLchar* mCode;
		int mCodeLength;
		const GLchar* mPath;
		char mLog[512];

};

inline GLuint Shader::getID() const {
	return mID;
}

inline GLenum Shader::getType() const {
	return mType;
}

inline const GLchar* Shader::getCode() const {
	return mCode;
}

inline int Shader::getCodeLength() const {
	return mCodeLength;
}

inline const GLchar* Shader::getPath() const {
	return mPath;
}

inline std::string Shader::infoLog() const {
	return mLog;
}

}