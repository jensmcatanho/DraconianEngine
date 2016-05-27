#pragma once

#include "Draconian.h"
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
	glBindVertexArray(m_ID);
}

inline void VertexArrayObject::unbind() const {
	glBindVertexArray(0);
}

}