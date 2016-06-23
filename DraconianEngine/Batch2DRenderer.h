#pragma once

#include "Prerequisites.h"
#include "Renderer2D.h"

namespace Draconian {

#define MAX_SPRITES    10000
#define VERTEX_SIZE    sizeof(VertexData)
#define SPRITE_SIZE    VERTEX_SIZE * 4
#define BUFFER_SIZE    MAX_SPRITES * SPRITE_SIZE
#define INDICES_SIZE   MAX_SPRITES * 6

class Batch2DRenderer : public Renderer2D {
	public:
		Batch2DRenderer();
		~Batch2DRenderer();

		void begin();
		void end();
		void submit(Renderable2D *) override;
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