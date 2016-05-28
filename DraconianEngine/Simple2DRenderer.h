#pragma once

#include <deque>

#include "Renderer2D.h"

namespace Draconian {

class Simple2DRenderer : public Renderer2D {
	public:
		void submit(const Renderable2D *) override;
		void flush() override;

	private:
		std::deque<const Renderable2D *> m_RenderQueue;
};

}