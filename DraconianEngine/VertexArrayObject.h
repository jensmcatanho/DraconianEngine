#pragma once

#include "Draconian.h"

namespace Draconian {

class VertexArrayObject {
	public:
		VertexArrayObject();
		~VertexArrayObject();

		void bind();
		inline bool isInitialised();

	private:
		GLuint mVAO;
		bool mInitilised;
};

inline bool VertexArrayObject::isInitialised() {
	return mInitilised;
}

}