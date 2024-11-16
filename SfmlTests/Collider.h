#pragma once
#include "Vector2d.h"
#include <iostream>

using namespace std;
class Collider
{
public :
	float r;
	Vector2d center;

	bool checkCollision(Collider other)
	{
		cout << (other.center - center).getMagnitude()<<" " << (other.r + r)<< endl;
		return (other.center - center).getMagnitude() < (other.r + r);
	}
	//bool checkCollision(Collider other) {
	//	float distance = (other.center - center).getMagnitude();
	//	float radiusSum = other.r + r;
	//	cout << "Distance: " << distance << ", Radius Sum: " << radiusSum << endl; // Debugging output
	//	return distance < radiusSum;
	//}
};

