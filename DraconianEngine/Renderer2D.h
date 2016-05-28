#pragma once

#include "Renderable2D.h"

namespace Draconian {

class Renderer2D {
	public:
		Renderer2D();
		virtual ~Renderer2D();

	protected:
		virtual void submit(const Renderable2D *) = 0;
		virtual void flush() = 0;
};

}