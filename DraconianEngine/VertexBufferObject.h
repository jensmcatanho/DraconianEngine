#pragma once

#include "Draconian.h"

namespace Draconian {

class VertexBufferObject : Buffer {
	public:
		VertexBufferObject(GLfloat *, GLsizei, GLuint);
		~VertexBufferObject();

		inline void bind() const;
		inline void unbind() const;
		
		inline GLuint getComponentCount() const;

	private:
		GLuint m_ComponentCount;

};

inline void VertexBufferObject::bind() const {
	glBindBuffer(GL_VERTEX_ARRAY, m_ID);
}

inline void VertexBufferObject::unbind() const {
	glBindBuffer(GL_VERTEX_ARRAY, 0);
}

inline GLuint VertexBufferObject::getComponentCount() const {
	return m_ComponentCount;
}

}