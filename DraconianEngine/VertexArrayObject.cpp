#include "VertexArrayObject.h"

namespace Draconian {

VertexArrayObject::VertexArrayObject()
	: mVAO(0),
	  mInitilised(false) {

	glGenVertexArrays(1, &mVAO);

}


VertexArrayObject::~VertexArrayObject() {
	if (mVAO) {
		glDeleteVertexArrays(1, &mVAO);
		mVAO = 0;

	}
}

void VertexArrayObject::bind() {
	if (mVAO) {
		glBindVertexArray(mVAO);

	}
}

}