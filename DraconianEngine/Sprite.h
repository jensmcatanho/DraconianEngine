#pragma once

#include "Renderable2D.h"

namespace Draconian {

class Sprite : public Renderable2D {
	public:
		Sprite(float, float, float, float, const glm::vec4 &);
};

}