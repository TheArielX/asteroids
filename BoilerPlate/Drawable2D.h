#pragma once
#ifndef _DRAWABLE2D_H_
#define _DRAWABLE2D_H_

// STDLIB
#include <vector>

// ENGINE
#include "Vector2.h"

namespace Engine
{
	namespace Graphics
	{
		class Drawable2D
		{
		public:
			virtual void Translate(Math::Vector2 position);
			virtual void Draw(unsigned int mode, std::vector<Math::Vector2> points);
		protected:
			Engine::Math::Vector2 m_position;
		};
	}
}

#endif // !_DRAWABLE_H_

