#include "Batch2DRenderer.h"

#include "IndexBufferObject.h"
#include "Renderable2D.h"
#include "VertexArrayObject.h"
#include "VertexBufferObject.h"

namespace Draconian {

Batch2DRenderer::Batch2DRenderer() :
	m_IndexCount(0) {

	initialize();
}

Batch2DRenderer::~Batch2DRenderer() {
	delete m_VAO;
	delete m_VBO;
	delete m_IBO;

}

void Batch2DRenderer::initialize() {
	GLuint indices[INDICES_SIZE];

	m_VAO = new VertexArrayObject();
	m_VBO = new VertexBufferObject((GLfloat *)nullptr, BUFFER_SIZE, 0, GL_DYNAMIC_DRAW);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, VERTEX_SIZE, (const GLvoid *)0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, VERTEX_SIZE, (const GLvoid *)(3 * sizeof(GLfloat)));

	for (int i = 0, offset = 0; i < INDICES_SIZE; i += 6, offset += 4) {
		indices[  i  ] = offset + 0;
		indices[i + 1] = offset + 1;
		indices[i + 2] = offset + 2;

		indices[i + 3] = offset + 0;
		indices[i + 4] = offset + 2;
		indices[i + 5] = offset + 3;
	}

	m_IBO = new IndexBufferObject(indices, sizeof(indices), INDICES_SIZE, GL_STATIC_DRAW);

	m_VAO->unbind();
}

void Batch2DRenderer::submit(const Renderable2D *renderable) {
	const glm::vec3 &position = renderable->getPosition();
	const glm::vec2 &size = renderable->getSize();
	const glm::vec4 &color = renderable->getColor();

	m_Buffer->vertex = position;
	m_Buffer->color = color;
	m_Buffer++;

	m_Buffer->vertex = glm::vec3(position.x, position.y + size.y, position.z);
	m_Buffer->color = color;
	m_Buffer++;

	m_Buffer->vertex = glm::vec3(position.x + size.x, position.y + size.y, position.z);
	m_Buffer->color = color;
	m_Buffer++;

	m_Buffer->vertex = glm::vec3(position.x + size.x, position.y, position.z);
	m_Buffer->color = color;
	m_Buffer++;

	m_IndexCount += 6;
}

void Batch2DRenderer::begin() {
	m_VBO->bind();
	m_Buffer = (VertexData *)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);

}

void Batch2DRenderer::end() {
	glUnmapBuffer(GL_ARRAY_BUFFER);
#if 0
	m_VBO->unbind();
#endif
}

void Batch2DRenderer::flush() {
	m_VAO->bind();
	m_IBO->bind();

	glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_INT, NULL);

#if 0
	m_VAO->unbind();
	m_IBO->unbind();
#endif

	m_IndexCount = 0;
}


}