#ifndef GAME_H
#define GAME_H

#include "snake.h"

void printAt(Vector2 pos, char ch);
void clearScreen();
void renderScreen(int width, int height, Snake snake, std::vector<Food> food);

#endif GAME_H