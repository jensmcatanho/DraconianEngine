#pragma once

#include "Buffer.h"

namespace Draconian {

class VertexBufferObject : public Buffer {
	public:
		VertexBufferObject(GLfloat *, GLsizei, GLuint, GLenum);
		VertexBufferObject(glm::vec2 *, GLsizei, GLuint, GLenum);
		VertexBufferObject(glm::vec3 *, GLsizei, GLuint, GLenum);
		VertexBufferObject(glm::vec4 *, GLsizei, GLuint, GLenum);
		~VertexBufferObject();

		inline void bind() const override;
		inline void unbind() const override;
		void setLayout(GLuint, GLint, GLenum, GLsizei);

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