#include "Asteroids.h"

#include <SDL2/SDL_opengl.h>

#include "Constants.h"
#include "MathUtilities.h"

namespace Asteroids
 {
	namespace Entities
	{
		const int NUM_POINTS = 16;
		const float MIN_SIZE = 25.0f;
		const float MAX_SIZE = 40.0f;
		const float ROTATION_SPEED = 120.0f;
		
			
			Asteroid::Asteroid(const std::vector<Engine::Math::Vector2> points) : m_points(points)
			{
			
			}
		
			void Asteroid::Draw()
			{
				Entity::Draw(GL_LINE_LOOP, m_points);
			}
		
			
			}
}