#pragma once

#include "Prerequisites.h"

namespace Draconian {

struct VertexData {
	glm::vec3 vertex;
	glm::vec4 color;
};

class Renderable2D {
	public:
		Renderable2D(glm::vec3, glm::vec2, glm::vec4);
		~Renderable2D();

		inline const glm::vec3 &getPosition() const;
		inline const glm::vec2 &getSize() const;
		inline const glm::vec4 &getColor() const;
		
	protected:
		glm::vec3 m_Position;
		glm::vec2 m_Size;
		glm::vec4 m_Color;

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

}