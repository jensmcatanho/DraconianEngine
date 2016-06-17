#pragma once

#include "Buffer.h"

namespace Draconian {

class IndexBufferObject : public Buffer {
	public:
		IndexBufferObject(GLuint *, GLsizei, GLuint, GLenum);
		virtual ~IndexBufferObject();

		inline void bind() const override;
		inline void unbind() const override;

		inline GLuint getCount() const;

	private:
		GLuint m_Count;
};

inline void IndexBufferObject::bind() const {
	 glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}

inline void IndexBufferObject::unbind() const {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

inline GLuint IndexBufferObject::getCount() const {
	return m_Count;
}

}