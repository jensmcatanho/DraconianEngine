#pragma once

#include "Draconian.h"

namespace Draconian {

class RenderWindow {
	public:
		RenderWindow();
		virtual ~RenderWindow();

		virtual void initialize(const std::string, int, int, bool) = 0;
		virtual void destroy() = 0;

	private:
		bool mIsFullscreen;
};

}
