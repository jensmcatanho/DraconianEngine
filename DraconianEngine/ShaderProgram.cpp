#include "ShaderProgram.h"

namespace Draconian {

ShaderProgram::ShaderProgram(GLuint vId, GLuint fId) :
	mVertexID(vId),
	mFragmentID(fId),
	mGeometryID(0),
	mIsValid(GL_FALSE)
{}

ShaderProgram::ShaderProgram(GLuint vId, GLuint fId, GLuint gId) :
	mVertexID(vId),
	mFragmentID(fId),
	mGeometryID(gId),
	mIsValid(GL_FALSE)
{}

ShaderProgram::~ShaderProgram() {
	glDetachShader(mID, mVertexID);
	glDetachShader(mID, mFragmentID);
	
	if (mGeometryID) 
		glDetachShader(mID, mVertexID);
	
	glDeleteProgram(mID);
}

GLint ShaderProgram::initialize() {
	GLint status;

	mID = glCreateProgram();

	glAttachShader(mID, mVertexID);
	glAttachShader(mID, mFragmentID);
	
	glLinkProgram(mID);
	glValidateProgram(mID);
	glUseProgram(mID);
	
	glGetProgramiv(mID, GL_LINK_STATUS, &status);
	glGetProgramiv(mID, GL_VALIDATE_STATUS, &mIsValid);
	glGetProgramInfoLog(mID, 512, NULL, mLog);
	
	return status;
}

}