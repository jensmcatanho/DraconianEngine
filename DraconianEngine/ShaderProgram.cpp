#include "ShaderProgram.h"

namespace Draconian {

ShaderProgram::ShaderProgram(GLuint vId, GLuint fId) :
	mVertexID(vId),
	mFragmentID(fId),
	mGeometryID(0)
{}

ShaderProgram::ShaderProgram(GLuint vId, GLuint fId, GLuint gId) :
	mVertexID(vId),
	mFragmentID(fId),
	mGeometryID(gId)
{}

ShaderProgram::~ShaderProgram() {
	glDeleteProgram(mID);
}

GLint ShaderProgram::initialize() {
	GLint status;

	mID = glCreateProgram();
	glAttachShader(mID, mVertexID);
	glAttachShader(mID, mFragmentID);
	glBindFragDataLocation(mID, 0, "outColor"); // Needs further research
	glLinkProgram(mID);
	glUseProgram(mID);
	glGetProgramiv(mID, GL_LINK_STATUS, &status);
	glGetProgramInfoLog(mID, 512, NULL, mLog);
	
	return status;
}

}