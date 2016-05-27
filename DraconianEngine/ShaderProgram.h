#pragma once

#include "Draconian.h"

namespace Draconian {

class ShaderProgram {
	public:
		ShaderProgram(GLuint, GLuint);
		ShaderProgram(GLuint, GLuint, GLuint);
		~ShaderProgram();
	
		GLint initialize();	
		inline void enable();
		inline void disable();

		template <typename T> 
		void setUniform(const GLchar *, T);

		inline GLuint getID() const;
		inline GLuint getVertexID() const;
		inline GLuint getFragmentID() const;
		inline GLuint getGeometryID() const;
		inline std::string infoLog() const;
		inline GLint isValid() const;

	protected:
		GLint getUniformLocation(const GLchar *);

	private:
		GLuint mID;
		GLuint mVertexID;
		GLuint mFragmentID;
		GLuint mGeometryID;
		char mLog[512];
		GLint mIsValid;

};

inline void ShaderProgram::enable() {
	glUseProgram(mID);
}

inline void ShaderProgram::disable() {
	glUseProgram(0);
}

inline GLuint ShaderProgram::getID() const {
	return mID;
}

inline GLuint ShaderProgram::getVertexID() const {
	return mVertexID;
}

inline GLuint ShaderProgram::getFragmentID() const {
	return mFragmentID;
}

inline GLuint ShaderProgram::getGeometryID() const {
	return mGeometryID;
}

inline std::string ShaderProgram::infoLog() const {
	return mLog;
}

inline GLint ShaderProgram::isValid() const {
	return mIsValid;
}

}