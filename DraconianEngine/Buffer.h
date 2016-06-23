#pragma once

#include "Prerequisites.h"

namespace Draconian {

class Buffer {
	public:
		Buffer();
		virtual ~Buffer();

		virtual void bind() = 0;
		virtual void unbind() = 0;

	protected:
		GLuint m_ID;
		GLboolean m_IsBound;
};

}