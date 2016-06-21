#include "VertexArrayObject.h"
#include "VertexBufferObject.h"

namespace Draconian {

VertexArrayObject::VertexArrayObject()
	: m_ID(0) {

	glGenVertexArrays(1, &m_ID);

}


VertexArrayObject::~VertexArrayObject() {
	for (uint i = 0; i < m_Buffers.size(); i++)
		delete m_Buffers[i];

	if (m_ID) {
		glDeleteVertexArrays(1, &m_ID);
		m_ID = 0;

	}
}

void VertexArrayObject::addBuffer(VertexBufferObject *buffer, GLuint index) {
	bind();
	buffer->bind();

	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);
	m_Buffers.push_back(buffer);

	unbind();
	buffer->unbind();
}

}