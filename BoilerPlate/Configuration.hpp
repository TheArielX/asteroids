#pragma once
#ifndef _CONFIGURATION_H_
#define _CONFIGURATION_H_

//
#include <vector>

//
#include "Ship.hpp"
#include "Asteroids.h"

namespace Asteroids
{
	namespace Utilities
	{
		class Configuration
		{
		public:
			std::vector<Entities::Ship*> LoadModels();
			std::vector<Entities::Asteroid*> CreateAsteroid();
			protected:
				int m_sizeFactor = 1;
		};
	}
}

#endif // !_CONFIGURATION_H_
