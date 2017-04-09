
#pragma once

#if _DEBUG
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
