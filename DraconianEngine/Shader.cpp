#include "Shader.h"

namespace Draconian {

Shader::Shader(const GLchar* p, GLenum t) :
	m_Path(p),
	m_Type(t)
{}

Shader::~Shader() {
	if (m_ID)
		glDeleteShader(m_ID);

}

void Shader::initialize() {
	std::string shaderString;
	std::ifstream shaderFile;
	std::stringstream shaderStream;

	shaderFile.exceptions(std::ifstream::badbit);

	try {
		shaderFile.open(m_Path);
		shaderStream << shaderFile.rdbuf();
		shaderFile.close();
		shaderString = shaderStream.str();

	} catch (std::ifstream::failure e) {
		std::cerr << "Error while reading the file. (Does the file exist?)" << std::endl;

	}

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