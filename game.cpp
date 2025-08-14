#include "game.h"

void printAt(Vector2 pos, char ch) {
	std::cout << "\033[" << (pos.y + 1) << ";" << (pos.x + 1) << "H" << ch;
}

void clearScreen() {
	std::cout << "\033[?25l"; // Hides cursor
	system("cls");
	//std::cout << "\033[2J\033[H"; // Clears screen
}

void renderScreen(int width, int height, int ticks, Snake snake, std::vector<Food> food) {
	if (ticks == 0 || true) {
		clearScreen();
		renderBackground(width, height);
	}

	for (int i = 0; i < snake.body.size(); i++) {
		printAt(snake.body[i], '#');
	}

	for (int i = 0; i < food.size(); i++) {
		printAt(food[i].pos, '@');
	}
}

void renderBackground(int width, int height) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			std::cout << ".";
		}
		std::cout << std::endl;
	}
}
