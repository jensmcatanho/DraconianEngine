#include "Simple2DRenderer.h"

#include "IndexBufferObject.h"
#include "StaticSprite.h"
#include "VertexArrayObject.h"
#include "VertexBufferObject.h"

namespace Draconian {

void Simple2DRenderer::submit(const Renderable2D *renderable) {
	m_RenderQueue.push_back((StaticSprite *)renderable);
}

void Simple2DRenderer::flush() {
	while (!m_RenderQueue.empty()) {
		const StaticSprite *sprite = m_RenderQueue.front();
	
		sprite->getVAO()->bind();
		sprite->getIBO()->bind();
		
		glDrawElements(GL_TRIANGLES, sprite->getIBO()->getCount(), GL_UNSIGNED_INT, nullptr);

		sprite->getIBO()->unbind();
		sprite->getVAO()->unbind();

		m_RenderQueue.pop_front();
	}
}

}