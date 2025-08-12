#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "food.h"
#include "main.h"

class Snake {
public:
	std::vector<Vector2> body; // Vector of positions of each body part
	Vector2 dir = Vector2(1, 0);
	bool grow = false; // Flag for adding length to snake

	Snake(Vector2 startingPos, Vector2 dir);
	Snake(Vector2 startingPos);
	
	bool update(int width, int height, Vector2 dir, std::vector<Food> food);
	void handleFood(std::vector<Food> &food);
	void addHead();
};

#endif SNAKE_H
