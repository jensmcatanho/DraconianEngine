#pragma once

#include <glm/glm.hpp>

#include "Renderer2D.h"

const unsigned int MAX_SPRITES = 10000;
const unsigned int VERTEX_SIZE = sizeof(Draconian::VertexData);
const unsigned int SPRITE_SIZE = VERTEX_SIZE * 4;
const unsigned int BUFFER_SIZE = MAX_SPRITES * SPRITE_SIZE;
const unsigned int INDICES_SIZE = MAX_SPRITES * 6;

namespace Draconian {

class Batch2DRenderer : Renderer2D {
	public:
		Batch2DRenderer();
		~Batch2DRenderer();

		void begin();
		void end();
		void submit(const Renderable2D *) override;
		void flush() override;
		void initialize();

	public:
		VertexArrayObject *m_VAO;
		VertexBufferObject *m_VBO;
		IndexBufferObject *m_IBO;
		VertexData *m_Buffer;
		GLsizei m_IndexCount;

};

}