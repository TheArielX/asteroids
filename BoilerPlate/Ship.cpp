#include "Ship.hpp"
#include "SDL2\SDL_opengl.h"66
#include "Entity.hpp"
#include "Constants.h"
namespace Asteroids
{
	namespace Entities
	{
		inline float wrap(float axis, float min, float max)
		{
			if (axis < min)
			{
				return max - (min - axis);
			}

			if (axis > max)
			{
				return min + (axis - max);
			}

				return axis;
		}
		const float ANGLE_OFFSET = 90.0f;
		const float THRUST = 3.0f;
		const float MAX_SPEED = 350.0f;
		const float DRAG = 0.999f;
		const int WIDTH = 1136;
		const int HEIGHT = 640;
		Ship::Ship(const std::vector<Engine::Math::Vector2> points)
			: m_points(points)
			, m_mass(0.5f)
		{
			m_angle = 0.0f;
		}

		void Ship::MoveUp()
		{
			// Calculate impulse
				//
				if (m_mass > 0)
				{
				float x = (THRUST / m_mass) * std::cosf(m_angleInRads);
				float y = (THRUST / m_mass) * std::sinf(m_angleInRads);
				m_velocity += Engine::Math::Vector2(x, y);
				}
		}
		void Ship::MoveDown()
		{
			// Calculate impulse
			//
			if (m_mass > 0)
			{
				float x = (THRUST / m_mass) * std::cosf(m_angleInRads);
				float y = (THRUST / m_mass) * std::sinf(m_angleInRads);
				m_velocity -= Engine::Math::Vector2(x, y);
			}
		}
		
		void Ship::MoveRight()
		{
			m_angle -= 5.0f;
			m_angleInRads = (m_angle + ANGLE_OFFSET) * (Engine::Math::PI / 180);
		}

		void Ship::MoveLeft()
		{
			m_angle += 5.0f;
			m_angleInRads = (m_angle + ANGLE_OFFSET) * (Engine::Math::PI / 180);

		}

		void Ship::Update(float delta)
		{
			// Clamp speed
			//
			float speed = std::fabs(m_velocity.Length());
			if (speed > MAX_SPEED)
			{
				m_velocity = Engine::Math::Vector2(
					(m_velocity.GetX() / speed) * MAX_SPEED,
					(m_velocity.GetY() / speed) * MAX_SPEED
				);

				speed = std::fabs(m_velocity.Length());
			}

			// Apply drag
			//
			m_velocity = Engine::Math::Vector2(
				m_velocity.GetX() * DRAG,
				m_velocity.GetY() * DRAG
			);
			// New position
			//
				Engine::Math::Vector2 newPos(
					m_position.GetX() + (m_velocity.GetX() * delta),
					m_position.GetY() + (m_velocity.GetY() * delta)
					 );
							/*m_position + m_velocity;*/
				
			float halfWidth = (WIDTH / 2.0f);
			float halfHeight = (HEIGHT / 2.0f);
			
			float worldMinX = -halfWidth;
			float worldMaxX = halfWidth;
			
			float worldMinY = -halfHeight;
			float worldMaxY = halfHeight;
			
			// Shunkan ido! (Wrap)
			float x = wrap(newPos.GetX(), worldMinX, worldMaxX);
			float y = wrap(newPos.GetY(), worldMinY, worldMaxY);
			
				newPos = Engine::Math::Vector2(x, y);
				Entity::Translate(newPos);
		}
		
		void Ship::Draw()
		{
			Entity::Draw(GL_LINE_LOOP, m_points);
		}
	}
}