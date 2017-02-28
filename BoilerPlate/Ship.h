#pragma once
#ifndef _SHIP_H_
#define _SHIP_H_

//
#include <vector>

//
#include "Vector2.h"
#include "Entity.h"

namespace Asteroids
{
	namespace Entities
	{
		class Ship : public Entity
		{
		public:
			/*
			* CONS
			*/
			Ship(const std::vector<Engine::Math::Vector2> points);

			/*
			* FUNCTIONS
			*/
			void MoveUp();
			void Draw();
		private:
			std::vector<Engine::Math::Vector2> m_points;
		};
	}
}

#endif // !_SHIP_H_

