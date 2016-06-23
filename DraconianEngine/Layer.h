#pragma once

#include "Prerequisites.h"

namespace Draconian {

class Layer {
	public:
		Layer();
		virtual ~Layer();
		virtual void add(Renderable2D *);

	protected:
		Renderer2D *m_Renderer;
		ShaderProgram *m_ShaderProgram;
		std::vector<Renderable2D *> m_Renderables;
		glm::mat4 m_ProjectionMatrix;
};

}