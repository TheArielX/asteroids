#pragma once
#ifndef _ASTEROID_H_
#define _ASTEROID_H_

#include <vector>

#include "Vector2.hpp"
#include "Entity.hpp"

namespace Asteroids
{
	namespace Entities
	{
		class Asteroid : public Entity
		{
			public:
				
			Asteroid(const std::vector<Engine::Math::Vector2> points);
				
					struct AsteroidSize
					{
					enum Size
					{
						BIG = 0,
							MEDIUM = 1,
							SMALL = 2,
							
							};
					};
					//PUBLIC
					//
					explicit Asteroid(AsteroidSize::Size size);
					void Update(float omegaTime);
					void Draw();
					void ApplyRandomTranslation() const;
				
					//Getter
					AsteroidSize::Size GetSize() const { return m_size; };
				private:
					void Generate();
					void ApplyRandomImpulse() const;
					std::vector<Engine::Math::Vector2> m_points;
					AsteroidSize::Size m_size;
					int m_sizeFactor;
					};
		}
	}
#endif // !_ASTEROID_H_