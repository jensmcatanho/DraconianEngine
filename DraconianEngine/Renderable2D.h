#pragma once

#include <GL/glew.h>

#include <glm/glm.hpp>

#include "ShaderProgram.h"
#include "IndexBufferObject.h"
#include "VertexArrayObject.h"
#include "VertexBufferObject.h"

namespace Draconian {

class Renderable2D {
	public:
		Renderable2D(glm::vec3, glm::vec2, glm::vec4, ShaderProgram &);
		virtual ~Renderable2D();

		inline const glm::vec3 &getPosition() const;
		inline const glm::vec2 &getSize() const;
		inline const glm::vec4 &getColor() const;

		inline const VertexArrayObject *getVAO() const;
		inline const IndexBufferObject *getIBO() const;
		inline ShaderProgram &getShaderProgram() const;
		
	protected:
		glm::vec3 m_Position;
		glm::vec2 m_Size;
		glm::vec4 m_Color;

		VertexArrayObject *m_VertexArray;
		//VertexBufferObject *m_VertexBuffer;
		//VertexBufferObject *m_ColorBuffer;
		IndexBufferObject *m_IndexBuffer;

		ShaderProgram &m_ShaderProgram;
};

inline const glm::vec3 &Renderable2D::getPosition() const {
	return m_Position;
}

inline const glm::vec2 &Renderable2D::getSize() const {
	return m_Size;
}

inline const glm::vec4 &Renderable2D::getColor() const {
	return m_Color;
}

inline const VertexArrayObject *Renderable2D::getVAO() const {
	return m_VertexArray;
}

inline const IndexBufferObject *Renderable2D::getIBO() const {
	return m_IndexBuffer;
}

inline ShaderProgram &Renderable2D::getShaderProgram() const {
	return m_ShaderProgram;
}
}