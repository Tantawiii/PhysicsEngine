#pragma once
#include "Particle.h"
#include "AABBCollider.h"
#include "Collider.h"
#include "SATCollider.h"
#include <list>

using namespace std;

class PhysicsWorld
{
private:
	list<Particle*> particles;
	list<SATCollider*> satColliders;
	bool circleFlag = false;
	bool squareFlag = false;
	bool satSquareFlag = false;
	void handleElasticCollision(Particle* p1, Particle* p2);
public:
	void addParticle(Particle* particle);
	//void addSATCollider(SATCollider* collider);
	void Update(float deltaTime);
	void checkTwoCircleCollision();
	void checkAABBCollision();
	void checkSATCollision();
	static const Vector2d gravity;
};

