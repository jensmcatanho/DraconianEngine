#include "Layer.h"

#include "ShaderProgram.h"
#include "Renderable2D.h"
#include "Renderer2D.h"

namespace Draconian {

Layer::Layer()
{
}


Layer::~Layer() {
	delete m_ShaderProgram;
	delete m_Renderer;

	for (uint i = 0; i < m_Renderables.size(); i++)
		delete m_Renderables[i];

}

void Layer::add(Renderable2D *renderable) {
	m_Renderables.push_back(renderable);
}

}