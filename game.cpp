#include "game.h"

void printAt(Vector2 pos, char ch) {
	std::cout << "\033[?25l"; // Hides cursor
	std::cout << "\033[" << (pos.y + 1) << ";" << (pos.x + 1) << "H" << ch;
}

void clearScreen() {
	system("cls");
	//std::cout << "\033[2J\033[H"; // Clears screen
}

void renderScreen(int width, int height, int ticks, Snake snake, std::vector<Food> food) {
	if (ticks == 0) {
		renderBackground(width, height);
	}

	for (int k = 0; k < snake.body.size(); k++) {
		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				if (i == 0 && j == 0) continue;
				Vector2 newPos = snake.body[k] - Vector2(j, i);

				if (newPos.x > width - 1  || newPos.x < 0) continue;
				if (newPos.y > height - 1 || newPos.y < 0) continue;

				printAt(newPos, '.');
			}
		}
	}

	for (int i = 0; i < food.size(); i++) {
		printAt(food[i].pos, '@');
	}

	for (int i = 0; i < snake.body.size(); i++) {
		printAt(snake.body[i], '#');
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
