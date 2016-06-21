#pragma once

#include "Prerequisites.h"
#include "VertexBufferObject.h"

namespace Draconian {

class VertexArrayObject {
	public:
		VertexArrayObject();
		~VertexArrayObject();

		inline void bind() const;
		inline void unbind() const;

		void addBuffer(VertexBufferObject *, GLuint);

	private:
		GLuint m_ID;
		std::vector<VertexBufferObject *> m_Buffers;
};

inline void VertexArrayObject::bind() const {
	for (VertexBufferObject *vbo : m_Buffers)
		vbo->bind();

	glBindVertexArray(m_ID);
}

inline void VertexArrayObject::unbind() const {
	for (VertexBufferObject *vbo : m_Buffers)
		vbo->unbind();

	glBindVertexArray(0);
}

}