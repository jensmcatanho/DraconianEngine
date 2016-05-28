#pragma once

#include "Draconian.h"

namespace Draconian {

class Buffer {
	public:
		Buffer();
		virtual ~Buffer();

		virtual inline void bind() const = 0;
		virtual inline void unbind() const = 0;

	protected:
		GLuint m_ID;
};

}