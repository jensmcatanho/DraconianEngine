#pragma once

#include "Renderer2D.h"

namespace Draconian {

class Simple2DRenderer : public Renderer2D {
	public:
		void submit(Renderable2D *) override;
		void flush() override;

	private:
		std::deque<StaticSprite *> m_RenderQueue;
};

}