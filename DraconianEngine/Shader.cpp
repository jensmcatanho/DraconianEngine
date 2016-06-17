#include "Shader.h"

#include "FileManager.h"
#include "MainCore.h"

namespace Draconian {

Shader::Shader(const GLchar* path, GLenum type) :
	m_Path(path),
	m_Type(type) {

	initialize();
}

Shader::~Shader() {
	if (m_ID)
		glDeleteShader(m_ID);

}

void Shader::initialize() {
	std::string shaderString;

	shaderString = FileManager::getSingleton().getStringStream(m_Path).str();
	m_Code = const_cast<const GLchar*>(shaderString.c_str());
	m_CodeLength = shaderString.length();
	m_ID = glCreateShader(m_Type);

	glShaderSource(m_ID, 1, &m_Code, &m_CodeLength);

}

GLint Shader::compile() {
	//Compiles the shader and returns GL_TRUE if successful or GL_FALSE otherwise
	GLint status;

	glCompileShader(m_ID);
	glGetShaderiv(m_ID, GL_COMPILE_STATUS, &status);
	glGetShaderInfoLog(m_ID, 512, NULL, m_Log);

	return status;
}

}