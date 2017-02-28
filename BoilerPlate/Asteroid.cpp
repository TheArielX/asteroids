#include "Asteroid.hpp"

#include <SDL2/SDL_opengl.h>

#include "Constants.h"


namespace Asteroids
 {
	namespace Entities
		 {
		const int NUM_POINTS = 16;
		const float MIN_SIZE = 25.0f;
		const float MAX_SIZE = 40.0f;
		
			Asteroid::Asteroid(const std::vector<Engine::Math::Vector2> points) : m_points(points)
			 {
			
				}
		
			void Asteroid::Draw()
			 {
			Entity::Draw(GL_LINE_LOOP, m_points);
			}
		
					//void Asteroid::Generate()
					//{
					//	// Min and Max Size of Asteroids
					//	float min = MIN_SIZE / m_sizeFactor;
					//	float max = MAX_SIZE / m_sizeFactor;
			
					//	for (int idx = 0; idx < NUM_POINTS; ++idx)
					//	{
					//		const float radians = (idx / static_cast<float>(NUM_POINTS)) * 2.0f * Engine::Math::PI;
					//		const float randDist = Engine::Math::RandomInRange<float>(min, max);
			
					//		m_points.push_back(Engine::Math::Vector2(sinf(radians) * randDist, cosf(radians) * randDist));
					//	}
			
			
					//}
			}
}