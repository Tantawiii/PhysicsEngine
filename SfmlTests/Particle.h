#pragma once
#include "Vector2d.h"
#include "Collider.h"
#include "AABBCollider.h"
#include "SATCollider.h"

class Particle
{
public:
	Vector2d postion;
	Vector2d velocity;
	Vector2d acceleration;
	Vector2d forces;
	string type;
	Collider collider;
	AABBCollider squareCollider;
	SATCollider satSquareCollider;
	float mass;
	float drag;

	
	
	Particle(Vector2d postion,float mass = 1, float drag = 0.3f, string type = " ");
	void Update(float dt);
	void addForce(Vector2d force);
};

