#include "VertexBufferObject.h"

namespace Draconian {

VertexBufferObject::VertexBufferObject(GLfloat *data, GLsizei dataSize, GLuint componentCount, GLenum usage) :
	Buffer(),
	m_ComponentCount(componentCount) {

	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	glBufferData(GL_ARRAY_BUFFER, dataSize, data, usage);
#if 0
	glBindBuffer(GL_ARRAY_BUFFER, 0);
#endif
}

VertexBufferObject::VertexBufferObject(glm::vec2 *data, GLsizei dataSize, GLuint componentCount, GLenum usage) :
	Buffer(),
	m_ComponentCount(componentCount) {

	glGenBuffers(1, &m_ID);
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	glBufferData(GL_ARRAY_BUFFER, dataSize, data, usage);
#if 0
	glBindBuffer(GL_ARRAY_BUFFER, 0);
#endif
}

VertexBufferObject::VertexBufferObject(glm::vec3 *data, GLsizei dataSize, GLuint componentCount, GLenum usage) :
	Buffer(),
	m_ComponentCount(componentCount) {

	glGenBuffers(1, &m_ID);
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	glBufferData(GL_ARRAY_BUFFER, dataSize, data, usage);
#if 0
	glBindBuffer(GL_ARRAY_BUFFER, 0);
#endif
}

VertexBufferObject::VertexBufferObject(glm::vec4 *data, GLsizei dataSize, GLuint componentCount, GLenum usage) :
	Buffer(),
	m_ComponentCount(componentCount) {

	glGenBuffers(1, &m_ID);
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	glBufferData(GL_ARRAY_BUFFER, dataSize, data, usage);
#if 0
	glBindBuffer(GL_ARRAY_BUFFER, 0);
#endif
}

VertexBufferObject::~VertexBufferObject() {
#if 0
	glBindBuffer(GL_ARRAY_BUFFER, 0);
#endif
	glDeleteBuffers(1, &m_ID);
}

void VertexBufferObject::setLayout(GLuint index, GLint size, GLenum type, GLsizei stride) {
	// Needs revision
	glEnableVertexAttribArray(index);
	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, 3, GL_FLOAT, GL_FALSE, stride, (const GLvoid *)0);
	glVertexAttribPointer(index, 4, GL_FLOAT, GL_FALSE, stride, (const GLvoid *)(3 * sizeof(GLfloat)));

}

}