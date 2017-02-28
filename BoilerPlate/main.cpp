#if _MSC_VER && _DEBUG
	#define _CRTDBG_MAP_ALLOC
	#include <crtdbg.h>
#endif

// C++ STL
#include <cassert>
#include <iostream>

// 
#include "App.hpp"
#include "Utilities.hpp"

const int WIDTH = 1136;
const int HEIGHT = 640;

int main(int argc, char* argv[])
{
#if _MSC_VER && _DEBUG
	// https://msdn.microsoft.com/en-us/library/x98tx3cf.aspx
	
	assert(_CrtCheckMemory());
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	
	Engine::App* app = new Engine::App("Boiler Plate!", WIDTH, HEIGHT);

	
	if(!app->Init())
	{
		std::cout << "App Init error!\n";
		return -1;
	}

	
	app->Execute();

	delete app;

	return 0;
}