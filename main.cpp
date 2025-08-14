#include "main.h"
#include "snake.h"
#include "game.h"

#define HEIGHT 20
#define WIDTH 40

enum GameState {
	PLAYING,
	WON,
	LOST
};

// Handling input and stuff
Vector2 getDir(Snake snake) {
	if (!_kbhit()) return Vector2(0, 0);

	switch (_getch()) {
	case 'w':
		if (snake.body.size() == 1 || snake.dir != Vector2(0, 1))
			return Vector2(0, -1);
		break;

	case 's':
		if (snake.body.size() == 1 || snake.dir != Vector2(0, -1))
			return Vector2(0, 1);
		break;

	case 'a':
		if (snake.body.size() == 1 || snake.dir != Vector2(1, 0))
			return Vector2(-1, 0);
		break;

	case 'd':
		if (snake.body.size() == 1 || snake.dir != Vector2(-1, 0))
			return Vector2(1, 0);
		break;

	case 'x': return Vector2(-1, -1);
	}
	return Vector2(0, 0);
}

int main(void) {
	bool gameRunning = true;
	GameState state = PLAYING;
	const int desiredFPS = 10;
	int FPS = 1000 / desiredFPS;
	int ticks = 0;

	Vector2 direction = Vector2();
	bool death = false;
	bool ateFood = false;
	int score = -1;

	Snake * snake = new Snake(Vector2(WIDTH / 2, HEIGHT / 2), Vector2(1, 0));
	std::vector<Food> food;

	srand(time(NULL));
	while (gameRunning) {
		switch (state) {
		case PLAYING:
			direction = getDir(*snake);

			if (direction == Vector2(-1, -1)) {
				state = LOST;
				break;
			}

			if (food.empty()) {
				// Gather all the 'pixels' that the food can go to
				std::vector<Vector2> possiblePositions;
				for (int i = 0; i < HEIGHT; i++) {
					for (int j = 0; j < WIDTH; j++) {
						possiblePositions.push_back(Vector2(j, i));
					}
				}

				// Loops through all the snakes parts and removes
				// the positions of the snake parts from possiblePositions
				// so that the food cannot spawn on the snakes body.
				for (const auto& segment : snake->body) {
					possiblePositions.erase(
						std::remove(possiblePositions.begin(), possiblePositions.end(), segment),
						possiblePositions.end()
					);
				}

				// If there's still spots available after the removal process,
				// then pick a random position from the vector
				if (possiblePositions.empty()) {
					state = WON;
					break;
				}
				else {
					int idx = rand() % possiblePositions.size();
					food.insert(food.begin(), Food(possiblePositions[idx]));
					score++;
				}
			}

			snake->handleFood(food);
			death = !snake->update(WIDTH, HEIGHT, direction, food);
			renderScreen(WIDTH, HEIGHT, ticks, *snake, food);
			printAt(Vector2(0, HEIGHT), 'S');
			std::cout << "core: " << score << std::endl;

			if (death) state = LOST;

			// Slow down the thread to match the desired frame rate
			// (kinda jank)
			std::this_thread::sleep_for(std::chrono::milliseconds(FPS));
			break;

		case WON:
			printAt(Vector2(0, HEIGHT + 1), 'Y');
			std::cout << "ou won!" << std::endl;
			break;

		case LOST:
			printAt(Vector2(0, HEIGHT + 1), 'Y');
			std::cout << "ou lost!" << std::endl;
			gameRunning = false;
			break;
		}

		ticks++;
	}

	return 0;
}

