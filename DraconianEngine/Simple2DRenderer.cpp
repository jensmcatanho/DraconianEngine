#include "Simple2DRenderer.h"

namespace Draconian {

void Simple2DRenderer::submit(const Renderable2D *renderable) {
	m_RenderQueue.push_back(renderable);
}

void Simple2DRenderer::flush() {
	while (!m_RenderQueue.empty()) {
		const Renderable2D *renderable = m_RenderQueue.front();
	
		renderable->getVAO()->bind();
		renderable->getIBO()->bind();
		glDrawElements(GL_TRIANGLES, renderable->getIBO()->getCount(), GL_UNSIGNED_INT, nullptr);

#if 0
		renderable->getIBO()->unbind();
		renderable=>getVAO()->unbind();
#endif

		m_RenderQueue.pop_front();
	}
}

}