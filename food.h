#ifndef FOOD_H
#define FOOD_H

#include "main.h"

class Food {
public:
	Vector2 pos = Vector2();
	char ch = '@';

	Food(Vector2 pos);
};

#endif // FOOD_H