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

template <typename T>
void ShaderProgram::setUniform(const GLchar *name, T value) {
	// TODO: Check for a good solution for testing which GL function to call based on T's type
}

GLint ShaderProgram::getUniformLocation(const GLchar *name) {
	return glGetUniformLocation(m_ID, name);

}

}