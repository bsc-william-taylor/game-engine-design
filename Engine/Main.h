
/* ------------------------------------------------

	@File		: Main.h
	@Date		: 08/11/2013
	@Purpose	:

		A common header file for all other
		files, to simplify how i include 
		multiple headers and librarys

 ------------------------------------------------ */

#pragma once

#if _DEBUG
	// Enables console if in debug mode
	#pragma comment(linker, "/subsystem:\"console\" /entry:\"WinMainCRTStartup\"")
#endif

#include <Windows.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <SDL_ttf.h>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <SDL.h>

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2_ttf.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "SDL2.lib")
#pragma warning(disable : 4800)

typedef const char * cstring;

using std::ofstream;
using std::fstream;
using std::vector;
using std::string;
using std::ios;

using std::to_string;
using std::cerr;
using std::cout;
using std::cin;

// Simple Gobal Round up function
int RoundUp(float);
