#include "ShaderProgram.h"

namespace Draconian {

ShaderProgram::ShaderProgram(GLuint vId, GLuint fId) :
	m_VertexID(vId),
	m_FragmentID(fId),
	m_GeometryID(0),
	m_IsValid(GL_FALSE)
{}

ShaderProgram::ShaderProgram(GLuint vId, GLuint fId, GLuint gId) :
	m_VertexID(vId),
	m_FragmentID(fId),
	m_GeometryID(gId),
	m_IsValid(GL_FALSE)
{}

ShaderProgram::~ShaderProgram() {
	glDetachShader(m_ID, m_VertexID);
	glDetachShader(m_ID, m_FragmentID);
	
	if (m_GeometryID)
		glDetachShader(m_ID, m_VertexID);
	
	glDeleteProgram(m_ID);
}

GLint ShaderProgram::initialize() {
	GLint status;

	m_ID = glCreateProgram();

	glAttachShader(m_ID, m_VertexID);
	glAttachShader(m_ID, m_FragmentID);
	
	glLinkProgram(m_ID);
	glValidateProgram(m_ID);
	glUseProgram(m_ID);
	
	glGetProgramiv(m_ID, GL_LINK_STATUS, &status);
	glGetProgramiv(m_ID, GL_VALIDATE_STATUS, &m_IsValid);
	glGetProgramInfoLog(m_ID, 512, NULL, m_Log);
	
	return status;
}

void ShaderProgram::setUniform(const GLchar *name, GLsizei count, GLfloat *value) const {
	switch (count) {
		case 1:
			glUniform1fv(getUniformLocation(name), count, value);
			break;

		case 2:
			glUniform2fv(getUniformLocation(name), count, value);
			break;

		case 3:
			glUniform3fv(getUniformLocation(name), count, value);
			break;

		case 4:
			glUniform4fv(getUniformLocation(name), count, value);
			break;

		default:
			std::cerr << "Invalid count value." << std::endl;
			break;
	}
}

void ShaderProgram::setUniform(const GLchar *name, GLsizei count, GLint *value) const {
	switch (count) {
	case 1:
		glUniform1iv(getUniformLocation(name), count, value);
		break;

	case 2:
		glUniform2iv(getUniformLocation(name), count, value);
		break;

	case 3:
		glUniform3iv(getUniformLocation(name), count, value);
		break;

	case 4:
		glUniform4iv(getUniformLocation(name), count, value);
		break;

	default:
		std::cerr << "Invalid count value." << std::endl;
		break;
	}
}

void ShaderProgram::setUniform(const GLchar *name, GLsizei count, GLuint *value) const {
	switch (count) {
	case 1:
		glUniform1uiv(getUniformLocation(name), count, value);
		break;

	case 2:
		glUniform2uiv(getUniformLocation(name), count, value);
		break;

	case 3:
		glUniform3uiv(getUniformLocation(name), count, value);
		break;

	case 4:
		glUniform4uiv(getUniformLocation(name), count, value);
		break;

	default:
		std::cerr << "Invalid count value." << std::endl;
		break;
	}
}

}