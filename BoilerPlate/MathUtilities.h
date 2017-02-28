#pragma once
#ifndef _MATHUTILITIES_H_
#define _MATHUTILITIES_H_

#include <random>

namespace Engine
{
	namespace Math
	{
		float DegreesToRadians(float angleInRadians);
		float RadiansToDegrees(float angleInDegrees);
		
			template<typename T>
			T RandomInRange(T min, T max)
			{
						//the random device that will seed the generator
			std::random_device seeder;
			
							//then make a mersenne twister engine
				std::mt19937 engine(seeder());
			
							//then the easy part... the distribution
				std::uniform_int_distribution<int> dist(static_cast<int>(min), static_cast<int>(max));
			
				return static_cast<T>(dist(engine));
			}
		
			inline int DieRoll()
			{
						// Seed with a real random value, if available
				std::random_device r;
			
							// Choose a random mean between 1 and 6
				std::default_random_engine e1(r());
			std::uniform_int_distribution<int> uniform_dist(1, 6);
			int mean = uniform_dist(e1);
			
							// Generate a normal distribution around that mean
				std::seed_seq seed2{ r(), r(), r(), r(), r(), r(), r(), r() };
			std::mt19937 e2(seed2);
			std::normal_distribution<> normal_dist(mean, 2);
			
				return static_cast<int>(normal_dist(e2));
			}
		}
	}

#endif