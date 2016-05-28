#include "Buffer.h"

namespace Draconian {

Buffer::Buffer() {
	glGenBuffers(1, &m_ID);

}


Buffer::~Buffer() {
	glDeleteBuffers(1, &m_ID);

}

}