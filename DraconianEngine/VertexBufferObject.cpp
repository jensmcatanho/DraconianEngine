#include "VertexBufferObject.h"

namespace Draconian {

VertexBufferObject::VertexBufferObject(GLfloat *data, GLsizei dataSize, GLuint componentCount, GLenum usage) :
	m_ComponentCount(componentCount) {

	bind();
	glBufferData(GL_ARRAY_BUFFER, dataSize, data, usage);
}

VertexBufferObject::VertexBufferObject(glm::vec2 *data, GLsizei dataSize, GLuint componentCount, GLenum usage) :
	m_ComponentCount(componentCount) {

	bind();
	glBufferData(GL_ARRAY_BUFFER, dataSize, data, usage);
}

VertexBufferObject::VertexBufferObject(glm::vec3 *data, GLsizei dataSize, GLuint componentCount, GLenum usage) :
	m_ComponentCount(componentCount) {

	bind();
	glBufferData(GL_ARRAY_BUFFER, dataSize, data, usage);
}

VertexBufferObject::VertexBufferObject(glm::vec4 *data, GLsizei dataSize, GLuint componentCount, GLenum usage) :
	m_ComponentCount(componentCount) {

	bind();
	glBufferData(GL_ARRAY_BUFFER, dataSize, data, usage);
}

VertexBufferObject::~VertexBufferObject() {

}


void VertexBufferObject::bind() {
	m_IsBound = GL_TRUE;
	glBindBuffer(GL_VERTEX_ARRAY, m_ID);
}

void VertexBufferObject::unbind() {
	m_IsBound = GL_FALSE;
	glBindBuffer(GL_VERTEX_ARRAY, 0);
}

void VertexBufferObject::setLayout(GLuint index, GLint size, GLenum type, GLsizei stride) {
	// Needs revision
	glEnableVertexAttribArray(index);
	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, 3, GL_FLOAT, GL_FALSE, stride, (const GLvoid *)0);
	glVertexAttribPointer(index, 4, GL_FLOAT, GL_FALSE, stride, (const GLvoid *)(3 * sizeof(GLfloat)));

}

}