#pragma once

#include "Draconian.h"

namespace Draconian {

class VertexBufferObject {
	public:
		VertexBufferObject(size_t, GLfloat*);
		~VertexBufferObject();

	private:
		GLuint mVBO;
};

}