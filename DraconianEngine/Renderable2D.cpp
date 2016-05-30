#include "Renderable2D.h"

namespace Draconian {

Renderable2D::Renderable2D(glm::vec3 pos, glm::vec2 size, glm::vec4 color) :
	m_Position(pos),
	m_Size(size),
	m_Color(color)
{}

Renderable2D::~Renderable2D() {

}

}