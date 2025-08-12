#include "snake.h"

Snake::Snake(Vector2 startingPos, Vector2 dir) {
	this->body.insert(this->body.begin(), startingPos);
	this->dir = dir;
}

Snake::Snake(Vector2 startingPos) {
	this->body.insert(this->body.begin(), startingPos);
}

// Updates the snakes position and direction, checks for death, and grows the snake if food was eaten.
bool Snake::update(int width, int height, Vector2 dir, std::vector<Food> food) {
	if (dir != Vector2(0, 0) && dir != Vector2(-1, -1)) this->dir = dir;

	// Insert a new head at the new position (prevPosition + dir)
	addHead();

	// If the grow flag is false, remove the tail
	if (!grow) this->body.pop_back();
	else	   grow = false;

	// If the head goes out of bounds, then the snake died this turn.
	if (this->body[0].x < 0 or this->body[0].x > width - 1 ||
		this->body[0].y < 0 or this->body[0].y > height - 1) {
		return false;
	}

	// If the head goes inside of it's body, then the snake died this turn.
	for (int i = this->body.size() - 1; i > 0; i--) {
		if (this->body[0] == this->body[i]) {
			return false;
		}
	}

	return true;
}

// Checks if the snake's head is on a food.
void Snake::handleFood(std::vector<Food> &food) {
	// Loop through all the food, if the head
	// is on top of a food, then it's eaten.
	for (int i = 0; i < food.size(); i++) {
		if (food[i].pos == this->body[0]) {
			food.erase(food.begin());
			grow = true;
		}
	}
}

// Adds a new head to the front of the snake.
void Snake::addHead() {
	// New head is current head + direction
	// Then insert the new head to the beginning of the vector.
	Vector2 newHead = this->body[0] + this->dir;
	this->body.insert(this->body.begin(), newHead);
}