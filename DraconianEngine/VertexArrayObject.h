#pragma once

#include "Prerequisites.h"

namespace Draconian {

class VertexArrayObject {
	public:
		VertexArrayObject();
		~VertexArrayObject();

		void bind();
		void unbind();

		void addBuffer(VertexBufferObject *, GLuint);

	private:
		GLuint m_ID;

		typedef std::vector<VertexBufferObject *> VBOList;
		VBOList m_Buffers;

		GLboolean m_IsBound;
};

}