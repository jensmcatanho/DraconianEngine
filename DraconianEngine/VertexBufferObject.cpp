#include "VertexBufferObject.h"

namespace Draconian {

VertexBufferObject::VertexBufferObject(GLfloat *data, GLsizei dataSize, GLuint componentCount, GLenum usage)
	: m_ComponentCount(componentCount) {

	glGenBuffers(1, &m_ID);
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	glBufferData(GL_ARRAY_BUFFER, dataSize, data, usage);
#if 0
	glBindBuffer(GL_ARRAY_BUFFER, 0);
#endif
}

VertexBufferObject::VertexBufferObject(glm::vec2 *data, GLsizei dataSize, GLuint componentCount)
	: m_ComponentCount(componentCount) {

	glGenBuffers(1, &m_ID);
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	glBufferData(GL_ARRAY_BUFFER, dataSize, data, GL_STATIC_DRAW);
#if 0
	glBindBuffer(GL_ARRAY_BUFFER, 0);
#endif
}

VertexBufferObject::VertexBufferObject(glm::vec3 *data, GLsizei dataSize, GLuint componentCount)
	: m_ComponentCount(componentCount) {

	glGenBuffers(1, &m_ID);
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	glBufferData(GL_ARRAY_BUFFER, dataSize, data, GL_STATIC_DRAW);
#if 0
	glBindBuffer(GL_ARRAY_BUFFER, 0);
#endif
}

VertexBufferObject::VertexBufferObject(glm::vec4 *data, GLsizei dataSize, GLuint componentCount)
	: m_ComponentCount(componentCount) {

	glGenBuffers(1, &m_ID);
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	glBufferData(GL_ARRAY_BUFFER, dataSize, data, GL_STATIC_DRAW);
#if 0
	glBindBuffer(GL_ARRAY_BUFFER, 0);
#endif
}

VertexBufferObject::~VertexBufferObject() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &m_ID);
}

}