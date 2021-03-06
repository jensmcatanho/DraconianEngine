#pragma once

#include "Renderable2D.h"

namespace Draconian {

class StaticSprite : public Renderable2D {
	public:
		StaticSprite(float, float, float, float, const glm::vec4 &, ShaderProgram &);
		~StaticSprite();

		inline VertexArrayObject *getVAO() const;
		inline IndexBufferObject *getIBO() const;
		inline ShaderProgram &getShaderProgram() const;

	private:
		VertexArrayObject *m_VAO;
		IndexBufferObject *m_IBO;
		ShaderProgram &m_ShaderProgram;
};

inline VertexArrayObject *StaticSprite::getVAO() const {
	return m_VAO;
}

inline IndexBufferObject *StaticSprite::getIBO() const {
	return m_IBO;
}

inline ShaderProgram &StaticSprite::getShaderProgram() const {
	return m_ShaderProgram;
}

}