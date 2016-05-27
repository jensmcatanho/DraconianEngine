#include "Shader.h"

namespace Draconian {

Shader::Shader(const GLchar* p, GLenum t) :
	mPath(p),
	mType(t)
{}

Shader::~Shader() {
	glDeleteShader(mID);

}

void Shader::initialize() {
	std::string shaderString;
	std::ifstream shaderFile;
	std::stringstream shaderStream;

	shaderFile.exceptions(std::ifstream::badbit);

	try {
		shaderFile.open(mPath);
		shaderStream << shaderFile.rdbuf();
		shaderFile.close();
		shaderString = shaderStream.str();

	} catch (std::ifstream::failure e) {
		std::cout << "Error while reading the file. (Does the file exist?)" << std::endl;

	}

	mCode = const_cast<const GLchar*>(shaderString.c_str());
	mCodeLength = shaderString.length();
	mID = glCreateShader(mType);

	glShaderSource(mID, 1, &mCode, &mCodeLength);

}

GLint Shader::compile() {
	//Compiles the shader and returns GL_TRUE if successful or GL_FALSE otherwise
	GLint status;

	glCompileShader(mID);
	glGetShaderiv(mID, GL_COMPILE_STATUS, &status);
	glGetShaderInfoLog(mID, 512, NULL, mLog);

	return status;
}

}