#pragma once
#include "Vector2d.h"


class Particle
{
public:
	Vector2d postion;
	Vector2d velocity;
	Vector2d acceleration;
	Vector2d forces;
	
	float mass;
	float drag;

	
	
	Particle(Vector2d postion,float mass = 1, float drag = 0.3f);
	void Update(float dt);
	void addForce(Vector2d force);
};

