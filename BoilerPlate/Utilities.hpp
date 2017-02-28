#pragma once
#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <string>
#include <vector>

namespace Engine
{
	namespace FileSystem
	{
		class Utilities
		{
		public:
			/*
			* PUBLIC FUNCTIONS
			*/
			std::string BuildPath(std::string prefix, std::string sufix);
			std::vector<std::string> ListFiles(std::string dir, std::string wildcard = "*.*");
		private:
			/*
			 * PRIVATE FUNCTIONS
			 */
			std::string GetExeFileName();
			std::string GetExePath();
			std::string GetLocalPathExpr(std::string dir);
			std::string GetLocalPathExpr(std::string dir, std::string wildcard);
		};
	}
}

#endif // !_UTILITIES_H_
