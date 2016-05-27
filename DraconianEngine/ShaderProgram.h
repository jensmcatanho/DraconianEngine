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
		GLuint m_ID;
		GLuint m_VertexID;
		GLuint m_FragmentID;
		GLuint m_GeometryID;
		char m_Log[512];
		GLint m_IsValid;

};

inline void ShaderProgram::enable() {
	glUseProgram(m_ID);
}

inline void ShaderProgram::disable() {
	glUseProgram(0);
}

inline GLuint ShaderProgram::getID() const {
	return m_ID;
}

inline GLuint ShaderProgram::getVertexID() const {
	return m_VertexID;
}

inline GLuint ShaderProgram::getFragmentID() const {
	return m_FragmentID;
}

inline GLuint ShaderProgram::getGeometryID() const {
	return m_GeometryID;
}

inline std::string ShaderProgram::infoLog() const {
	return m_Log;
}

inline GLint ShaderProgram::isValid() const {
	return m_IsValid;
}

}