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

		void bind() override;
		void unbind() override;
		void setLayout(GLuint, GLint, GLenum, GLsizei);

		inline GLuint getComponentCount() const;

	private:
		GLuint m_ComponentCount;

};

inline GLuint VertexBufferObject::getComponentCount() const {
	return m_ComponentCount;
}

}