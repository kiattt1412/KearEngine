#pragma once
#include <vector>
#include <memory>
#include "Transform.h"
#include "Triangle.h"
#include <GLFW/glfw3.h>
#include "Vec3.h"
#include "Rectangle.h"
#include "SoundManager.h"

class Game
{
public:
	Game();
	~Game();
	void startGame();
	void inGameLoop();
	int recNum;
	float borderLimit;
	float ranMin = 0.00005f;
	float ranMax = 0.0005f;
	int playerScore = 0;
	bool gameOver = false;
	std::vector<std::shared_ptr<Rectangle>> recStore;
	std::vector<std::shared_ptr<Triangle>> triStore;
	
	float Game::Rand(float Min, float Max);
	SoundManager sm;
};

