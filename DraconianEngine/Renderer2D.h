#pragma once

#include "Prerequisites.h"

namespace Draconian {

class Renderer2D {
	public:
		Renderer2D();
		virtual ~Renderer2D();

	protected:
		virtual void submit(Renderable2D *) = 0;
		virtual void flush() = 0;
};

}