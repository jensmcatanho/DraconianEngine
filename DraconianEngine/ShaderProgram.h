#pragma once

#include <iostream>

#include <GL/glew.h>

namespace Draconian {

class ShaderProgram {
	public:
		ShaderProgram(GLuint, GLuint);
		ShaderProgram(GLuint, GLuint, GLuint);
		~ShaderProgram();
	
		GLint initialize();	
		inline void enable();
		inline void disable();

		// glUniform(1/2/3/4)f
		inline void setUniform(const GLchar *, GLfloat) const;
		inline void setUniform(const GLchar *, GLfloat, GLfloat) const;
		inline void setUniform(const GLchar *, GLfloat, GLfloat, GLfloat) const;
		inline void setUniform(const GLchar *, GLfloat, GLfloat, GLfloat, GLfloat) const;

		// glUniform(1/2/3/4)fv
		void setUniform(const GLchar *, GLsizei, GLfloat *) const;

		// glUniform(1/2/3/4)i
		inline void setUniform(const GLchar *, GLint) const;
		inline void setUniform(const GLchar *, GLint, GLint) const;
		inline void setUniform(const GLchar *, GLint, GLint, GLint) const;
		inline void setUniform(const GLchar *, GLint, GLint, GLint, GLint) const;

		// glUniform(1/2/3/4)iv
		void setUniform(const GLchar *, GLsizei, GLint *) const;

		// glUniform(1/2/3/4)ui
		inline void setUniform(const GLchar *, GLuint) const;
		inline void setUniform(const GLchar *, GLuint, GLuint) const;
		inline void setUniform(const GLchar *, GLuint, GLuint, GLuint) const;
		inline void setUniform(const GLchar *, GLuint, GLuint, GLuint, GLuint) const;

		// glUniform(1/2/3/4)uiv
		void setUniform(const GLchar *, GLsizei, GLuint *) const;

		// Get methods
		inline GLuint getID() const;
		inline GLuint getVertexID() const;
		inline GLuint getFragmentID() const;
		inline GLuint getGeometryID() const;
		inline std::string infoLog() const;
		inline GLint isValid() const;

	private:
		inline GLint getUniformLocation(const GLchar *) const;

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

// Uniform methods
inline GLint ShaderProgram::getUniformLocation(const GLchar *name) const {
	return glGetUniformLocation(m_ID, name);
}

// glUniform(1/2/3/4)f
inline void ShaderProgram::setUniform(const GLchar *name, GLfloat value0) const {
	return glUniform1f(getUniformLocation(name), value0);
}

inline void ShaderProgram::setUniform(const GLchar *name, GLfloat value0, GLfloat value1) const {
	return glUniform2f(getUniformLocation(name), value0, value1);
}

inline void ShaderProgram::setUniform(const GLchar *name, GLfloat value0, GLfloat value1, GLfloat value2) const {
	return glUniform3f(getUniformLocation(name), value0, value1, value2);
}

inline void ShaderProgram::setUniform(const GLchar *name, GLfloat value0, GLfloat value1, GLfloat value2, GLfloat value3) const {
	return glUniform4f(getUniformLocation(name), value0, value1, value2, value3);
}

// glUniform(1/2/3/4)i
inline void ShaderProgram::setUniform(const GLchar *name, GLint value0) const {
	return glUniform1i(getUniformLocation(name), value0);
}

inline void ShaderProgram::setUniform(const GLchar *name, GLint value0, GLint value1) const {
	return glUniform2i(getUniformLocation(name), value0, value1);
}

inline void ShaderProgram::setUniform(const GLchar *name, GLint value0, GLint value1, GLint value2) const {
	return glUniform3i(getUniformLocation(name), value0, value1, value2);
}

inline void ShaderProgram::setUniform(const GLchar *name, GLint value0, GLint value1, GLint value2, GLint value3) const {
	return glUniform4i(getUniformLocation(name), value0, value1, value2, value3);
}

// glUniform(1/2/3/4)ui
inline void ShaderProgram::setUniform(const GLchar *name, GLuint value0) const {
	return glUniform1ui(getUniformLocation(name), value0);
}

inline void ShaderProgram::setUniform(const GLchar *name, GLuint value0, GLuint value1) const {
	return glUniform2ui(getUniformLocation(name), value0, value1);
}

inline void ShaderProgram::setUniform(const GLchar *name, GLuint value0, GLuint value1, GLuint value2) const {
	return glUniform3ui(getUniformLocation(name), value0, value1, value2);
}

inline void ShaderProgram::setUniform(const GLchar *name, GLuint value0, GLuint value1, GLuint value2, GLuint value3) const {
	return glUniform4ui(getUniformLocation(name), value0, value1, value2, value3);
}

// Get methods

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