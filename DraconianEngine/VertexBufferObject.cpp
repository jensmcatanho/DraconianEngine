#include "VertexBufferObject.h"

namespace Draconian {

VertexBufferObject::VertexBufferObject(size_t vertexSize, GLfloat* vertices) {
	glGenBuffers(1, &mVBO);
	glBindBuffer(GL_ARRAY_BUFFER, mVBO);
	glBufferData(GL_ARRAY_BUFFER, vertexSize, vertices, GL_STATIC_DRAW);

}


VertexBufferObject::~VertexBufferObject() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &mVBO);
}



}