#pragma once
#include <GLFW/glfw3.h>
#include "Game.h"

class Window
{
public:
	Window();
	~Window();
	void InitWindow();
	Game gm;
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

	static void key_callback_static(GLFWwindow* window, int key, int scancode, int action, int mods);
	
	
	float i = 0;
};

