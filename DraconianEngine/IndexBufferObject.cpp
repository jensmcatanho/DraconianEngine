#include "IndexBufferObject.h"

namespace Draconian {

IndexBufferObject::IndexBufferObject(GLuint *data, GLsizei dataSize, GLuint count, GLenum usage) :
	m_Count(count) {

	bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, dataSize, data, usage);
}


IndexBufferObject::~IndexBufferObject() {

}

void IndexBufferObject::bind() {
	m_IsBound = GL_TRUE;
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}

void IndexBufferObject::unbind() {
	m_IsBound = GL_FALSE;
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

}