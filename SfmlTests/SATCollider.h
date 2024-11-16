#pragma once
#include "Vector2d.h"
#include <vector>

using namespace std;

class SATCollider
{
public:
	Vector2d position;
	vector<Vector2d> points;
	Vector2d velocity;
	void updatePosition(Vector2d position);

	bool checkCollision(SATCollider other);
	vector<Vector2d> getNormals();
	Vector2d projectShape(Vector2d axis);
};

