#include "StaticSprite.h"

namespace Draconian {

StaticSprite::StaticSprite(float x, float y, float width, float height, const glm::vec4 &color, ShaderProgram &sp) :
	Renderable2D(glm::vec3(x, y, 0), glm::vec2(width, height), color),
	m_ShaderProgram(sp) {

	m_VAO = new VertexArrayObject();

	GLfloat vertices[] = {
		        x,          y, 0,
		        x, y + height, 0,
		x + width, y + height, 0,
		x + width,          y, 0
	};

	GLfloat colors[] = {
		color.x, color.y, color.z, color.w,
		color.x, color.y, color.z, color.w,
		color.x, color.y, color.z, color.w,
		color.x, color.y, color.z, color.w
	};

	m_VAO->addBuffer(new VertexBufferObject(vertices, sizeof(vertices), 3, GL_STATIC_DRAW), 0);
	m_VAO->addBuffer(new VertexBufferObject(colors, sizeof(colors), 4, GL_STATIC_DRAW), 1);

	GLuint indices[] = { 0, 1, 2, 0, 2, 3 };

	m_IBO = new IndexBufferObject(indices, sizeof(indices), 6, GL_STATIC_DRAW);

}


StaticSprite::~StaticSprite() {
	delete m_VAO;
	delete m_IBO;
}

}