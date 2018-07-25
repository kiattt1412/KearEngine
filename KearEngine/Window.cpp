#include "Window.h"
#include <iostream>
#include <GLFW/glfw3.h>
#include "Game.h"
#include <vector>
#include <memory>
#include <Windows.h>
#include <MMSystem.h>

Window::Window()
{
}


Window::~Window()
{
	glfwTerminate();
	
}


void Window::InitWindow()
{
	
	GLFWwindow *window = nullptr;
	if (!glfwInit()) {
		glfwTerminate();
		return;
	}
	window = glfwCreateWindow(900,900, "My Game", nullptr, NULL);
	if (!window) {
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(window);
	glfwSetWindowUserPointer(window, this);
	glfwSetKeyCallback(window, key_callback_static);
	//	
	gm.startGame();
	//
	while (!glfwWindowShouldClose(window) && !gm.gameOver == true) {
		glClear(GL_COLOR_BUFFER_BIT); // Render color
		glClearColor(0.5f+i, 0.5f, 0.5f, 1.0f); // change color

		gm.inGameLoop();		
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	
	glfwDestroyWindow(window);
	
}

void Window::key_callback_static(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Window* that = static_cast<Window*>(glfwGetWindowUserPointer(window));
	that->key_callback(window, key, scancode, action, mods);
}


void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_W && action == GLFW_PRESS)
	{
		gm.triStore[0]->transform.t.y += 0.05f;
	}
	if (key == GLFW_KEY_S && action == GLFW_PRESS)
	{
		gm.triStore[0]->transform.t.y -= 0.05f;
	}
	if (key == GLFW_KEY_A && action == GLFW_PRESS)
	{
		gm.triStore[0]->transform.t.x -= 0.05f;
	}
	if (key == GLFW_KEY_D && action == GLFW_PRESS)
	{
		gm.triStore[0]->transform.t.x += 0.05f;
	}
	if (key == GLFW_KEY_Z && action == GLFW_PRESS)
	{
		std::cout << gm.triStore[0]->transform.t.distance(gm.recStore[0]->transform.t);
	}
}
