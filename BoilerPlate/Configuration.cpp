#include "Configuration.hpp"

// stdlib
#include <string>
#include <fstream>
#include <sstream>
/* MOVE OUT ! */

// Engine
//
#include "Utilities.hpp"
#include "Vector2.hpp"
#include "Constants.h"
#include "MathUtilities.h"
#include <iostream>

namespace Asteroids
{
	namespace Utilities
	{
		std::string const models_dir = "models";

		std::vector<Entities::Ship*> Configuration::LoadModels()
		{
			Engine::FileSystem::Utilities util;

			// Retrieve the files from the models directory
			//
			auto models = util.ListFiles(models_dir);

			std::vector<Entities::Ship*> ships;

			for (auto model : models)
			{
				// Load file
				//
				std::ifstream ifstream(util.BuildPath(models_dir, model));

				//
				std::string content;

				std::vector<Engine::Math::Vector2> points;
				while (ifstream >> content)
				{
					// Read components
					//
					std::stringstream lineStream(content);
					std::string cell;
					std::vector<float> components;
					while(std::getline(lineStream, cell, ','))
					{
						components.push_back(std::stof(cell));
					}

					// Add vector
					//
					points.push_back(
						Engine::Math::Vector2(components[0], components[1])
						);					
				}

				// Adding ship to array
				//
				ships.push_back(new Asteroids::Entities::Ship(points));
			}

			return ships;
		}
		const int NUM_POINTS = 16;
		const float MIN_SIZE = 25.0f;
		const float MAX_SIZE = 45.0f;
		const float ROTATION_SPEED = 120.0f;
		//CREATE ASTEROID
		//
			std::vector<Entities::Asteroid*> Configuration::CreateAsteroid()
			{
			std::vector<Entities::Asteroid*> asteroid;
			std::vector<Engine::Math::Vector2> ast_points;
			
			float min = MIN_SIZE / m_sizeFactor;
			float max = MAX_SIZE / m_sizeFactor;
			
			// Randomly generate points for asteroid
			//
				for (int idx = 0; idx < NUM_POINTS; ++idx)
				{
				const float radians = (idx / static_cast<float>(NUM_POINTS)) * 2.0f * Engine::Math::PI;
				const float randDist = Engine::Math::RandomInRange<float>(min, max);
				
					ast_points.push_back(Engine::Math::Vector2(sinf(radians) * randDist, cosf(radians) * randDist));
				}
			
				std::cout << "There are " << ast_points.size() << " points"
				 << std::endl;
			asteroid.push_back(new Asteroids::Entities::Asteroid(ast_points));
			
				return asteroid;
			}

	}
}