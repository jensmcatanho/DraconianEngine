#pragma once

#include "Buffer.h"

namespace Draconian {

class IndexBufferObject : public Buffer {
	public:
		IndexBufferObject(GLuint *, GLsizei, GLuint, GLenum);
		~IndexBufferObject();

		void bind() override;
		void unbind() override;

		inline GLuint getCount() const;

	private:
		GLuint m_Count;
};

inline GLuint IndexBufferObject::getCount() const {
	return m_Count;
}

}