#include <iostream>
#include <memory>
#include <vector>
#include <GLFW/glfw3.h>
#include "Transform.h"
#include "Triangle.h"
#include "Vec3.h"
#include "Window.h"
#include "Game.h"
#include <time.h>
#include <memory>



#define _CRTDBG_MAP_ALLOC

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand((unsigned int)time(NULL));
	Window wd;
	wd.InitWindow();
	getchar();
	return 0;
}