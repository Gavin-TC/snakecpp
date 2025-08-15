#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>
#include <time.h>
#include <cstdlib>

struct Vector2 {
	int x;
	int y;

	Vector2(int x, int y) {
		this->x = x;
		this->y = y;
	}
	Vector2(int xy) {
		this->x = xy;
		this->y = xy;
	}
	Vector2() {
		this->x = 0;
		this->y = 0;
	}
	bool operator==(const Vector2& other) const {
		return x == other.x && y == other.y;
	}
	bool operator!=(const Vector2& other) const {
		return x != other.x || y != other.y;
	}
	bool operator>(const Vector2& other) {
		return x > other.x || y > other.y;
	}
	bool operator<(const Vector2& other) {
		return x < other.x || y < other.y;
	}
	Vector2 operator+(const Vector2& other) const {
		return Vector2{ x + other.x, y + other.y };
	}
	Vector2 operator-(const Vector2& other) const {
		return Vector2{ x - other.x, y - other.y };
	}
	Vector2 operator*(const Vector2& other) {
		return Vector2{ x * other.x, y * other.y };
	}
	Vector2& operator+=(const Vector2& other) {
		x += other.x;
		y += other.y;
		return *this;
	}
};

#endif // MAIN_H