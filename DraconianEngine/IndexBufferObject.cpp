#include "IndexBufferObject.h"

namespace Draconian {

IndexBufferObject::IndexBufferObject(GLuint *data, GLsizei dataSize, GLuint count, GLenum usage) :
	Buffer(),
	m_Count(count) {

	glGenBuffers(1, &m_ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, dataSize, data, usage);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}


IndexBufferObject::~IndexBufferObject() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &m_ID);

}

}