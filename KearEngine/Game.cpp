#include <iostream>
#include "Game.h"
#include "Window.h"
#include <vector>
#include <memory>
#include "Rectangle.h"
#include "Triangle.h"
#include "Transform.h"
#include <GLFW/glfw3.h>
#include "Vec3.h"
#include <math.h>
#include <time.h>
#include "SoundManager.h"

Game::Game()
{
	recNum = 50;
	borderLimit = 1.0f;
}


Game::~Game()
{
}

void Game::startGame()
{

	sm.playSound();

	auto tri1 = std::make_shared<Triangle>();
	tri1->transform = Transform(Vec3<float>(0.0f, 0.0f, 0.0f), Vec3<float>(0, 1, 0), Vec3<float>(0.025f, 0.025f, 0.025f), Vec3<float>(0.0f, 1.0f, 0), 0.0f);
	triStore.push_back(tri1);


	for (int i = 0; i < recNum; i++)
	{
		auto rec1 = std::make_shared<Rectangle>();	
		recStore.push_back(rec1);
		float randnum = Rand(-1, 1);
		recStore[i]->transform = Transform(Vec3<float>(randnum, 1.0f, 0.0f), Vec3<float>(0, 1, 0), Vec3<float>(0.05f, 0.05f, 0.05f), Vec3<float>(1.0f, 0.0f, 0), 0.0f);	
		recStore[i]->randomSpd = Rand(ranMin, ranMax);
	}




}

void Game::inGameLoop()
{
	triStore[0]->drawPlane();	
	for (int i = 0; i < recNum; i++)
	{
		recStore[i]->draw();
		if (recStore[i]->transform.t.y < -borderLimit)
		{
			recStore[i]->setnewMove();
			playerScore++;
		}		
		if (triStore[0]->transform.t.distance(recStore[i]->transform.t) < 0.05f)
		{
			gameOver = true;
			std::cout << std::endl;
			std::cout << " Score : " << playerScore;
		}
	}
	
	if (gameOver == true)
	{
		sm.stopSound();
	}

}

float Game::Rand(float Min, float Max)
{
	return ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
}
