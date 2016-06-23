#include "Buffer.h"

namespace Draconian {

Buffer::Buffer() :
	m_ID(0) {

	glGenBuffers(1, &m_ID);

}


Buffer::~Buffer() {
	if (m_ID)
		glDeleteBuffers(1, &m_ID);

}

}