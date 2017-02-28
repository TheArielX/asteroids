#pragma once
#ifndef _SHIP_H_
#define _SHIP_H_

//
#include <vector>

//
#include "Vector2.hpp"
#include "Entity.hpp"


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
			void MoveDown();
			void MoveLeft();
			void Update(float delta);
			void MoveRight();
			void Draw();
		private:
			std::vector<Engine::Math::Vector2> m_points;
			Engine::Math::Vector2 m_velocity;
			float m_mass;
		};
	}
}

#endif // !_SHIP_H_
