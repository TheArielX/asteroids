#pragma once

#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Vector2.hpp"
#include "Drawable2D.hpp"

namespace Asteroids
{
	namespace Entities
	{
		class Entity : public Engine::Graphics::Drawable2D
		{
			protected:
				float m_angleInRads;
				
		};
	}
}

#endif // !_ENTITY_H_
