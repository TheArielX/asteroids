#pragma once
#ifndef _CONFIGURATION_H_
#define _CONFIGURATION_H_

//
#include <vector>

//
#include "Ship.h"

namespace Asteroids
{
	namespace Utilities
	{
		class Configuration
		{
		public:
			std::vector<Entities::Ship*> LoadModels();
		};
	}
}

#endif // !_CONFIGURATION_H_