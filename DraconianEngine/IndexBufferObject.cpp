#include "IndexBufferObject.h"

namespace Draconian {

IndexBufferObject::IndexBufferObject(GLuint *data, GLsizei dataSize, GLuint count, GLenum usage) :
	Buffer(),
	m_Count(count) {

	glGenBuffers(1, &m_ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, dataSize, data, usage);
#if 0
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
#endif
}


IndexBufferObject::~IndexBufferObject() {
#if 0
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
#endif
	glDeleteBuffers(1, &m_ID);

}

}