#include "Utilities.hpp"

// stdlib
#include <Windows.h>
#include <sstream>

namespace Engine
{
	namespace FileSystem
	{
		std::string Utilities::GetExeFileName()
		{
			wchar_t buffer[MAX_PATH];
			GetModuleFileName(NULL, buffer, MAX_PATH);
			std::wstring w_buff(buffer);
			return std::string(w_buff.begin(), w_buff.end());
		}

		std::string Utilities::GetExePath()
		{
			std::string f = GetExeFileName();
			return f.substr(0, f.find_last_of("\\/"));
		}

		std::string Utilities::GetLocalPathExpr(std::string dir)
		{
			std::string current = GetExePath() + "\\" + dir;
			std::wstring s(current.begin(), current.end());
			std::wstring file = s + L"\\*.*";
			return std::string(file.begin(), file.end());
		}

		std::string Utilities::GetLocalPathExpr(std::string dir, std::string wildcard)
		{
			std::string current = GetExePath() + "\\" + dir + "\\" + wildcard;
			return current;
		}

		std::string Utilities::BuildPath(std::string prefix, std::string sufix)
		{
			std::stringstream path;

			path << prefix;
			path << "\\";
			path << sufix;

			return path.str();
		}

		std::vector<std::string> Utilities::ListFiles(std::string dir, std::string wildcard)
		{
			// Build the local path
			std::string path = GetLocalPathExpr(dir, wildcard);

			// Transform
			std::wstring w_path(path.begin(), path.end());

			WIN32_FIND_DATA FindFileData;

			std::vector<std::string> files;


			HANDLE hFind;
			hFind = FindFirstFile(w_path.c_str(), &FindFileData);
			if (hFind != INVALID_HANDLE_VALUE)
			{
				do {
					std::wstring fname(FindFileData.cFileName);
					if (fname == L"." || fname == L"..")
						continue;

					files.push_back(
						std::string(fname.begin(), fname.end())
						);
				} while (FindNextFile(hFind, &FindFileData));
				FindClose(hFind);
			}

			return files;
		}
	}
}