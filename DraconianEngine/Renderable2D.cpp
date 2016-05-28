#include "Renderable2D.h"

namespace Draconian {

Renderable2D::Renderable2D(glm::vec3 pos, glm::vec2 size, glm::vec4 color, ShaderProgram &sp) :
	m_Position(pos),
	m_Size(size),
	m_Color(color),
	m_ShaderProgram(sp) {
	
	m_VertexArray = new VertexArrayObject();

	GLfloat vertices[] = {
		           m_Position.x,            m_Position.y, m_Position.z,
		           m_Position.x, m_Position.y + m_Size.y, m_Position.z,
		m_Position.x + m_Size.x, m_Position.y + m_Size.y, m_Position.z,
		m_Position.x + m_Size.x,            m_Position.y, m_Position.z
	};

	GLfloat colors[] = {
		color.x, color.y, color.z, color.w,
		color.x, color.y, color.z, color.w,
		color.x, color.y, color.z, color.w,
		color.x, color.y, color.z, color.w
	};

	m_VertexArray->addBuffer(new VertexBufferObject(vertices, sizeof(vertices), 3), 0);
	m_VertexArray->addBuffer(new VertexBufferObject(colors, sizeof(colors), 4), 1);

	GLuint indices[] = { 0, 1, 2, 0, 2, 3 };

	m_IndexBuffer = new IndexBufferObject(indices, sizeof(indices), 6);

}


Renderable2D::~Renderable2D() {
	delete m_VertexArray;
	delete m_IndexBuffer;
}

}