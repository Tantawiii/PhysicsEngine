#include "PhysicsWorld.h"


const Vector2d PhysicsWorld::gravity = Vector2d(0,0);

void PhysicsWorld::addParticle(Particle* particle) {
    particles.push_back(particle);
}

void PhysicsWorld::addSATCollider(SATCollider* collider) {
    satColliders.push_back(collider);
}

void PhysicsWorld::Update(float deltaTime) {
    for (Particle* particle : particles) {
        particle->addForce(gravity *particle->mass);

        particle->Update(deltaTime);
    }
}

void PhysicsWorld::checkTwoCircleCollision() {
    auto it = particles.begin();
    auto beforeEnd = particles.end();
    beforeEnd--;

    for (; it != beforeEnd; ++it) {
        Particle* p1 = *it;

        if (p1->type != "Circle") continue;

        auto itt = it;
        ++itt;

        for (; itt != particles.end(); ++itt) {
            Particle* p2 = *itt;

            if (p2->type != "Circle") continue;

            if (p1->collider.checkCollision(p2->collider) && !circleFlag) {
                circleFlag = true;
                std::cout << "Circle collision detected!" << std::endl;
            }
        }
    }
}


void PhysicsWorld::checkAABBCollision() {
    auto it = particles.begin();
    auto beforeEnd = particles.end();
    beforeEnd--;

    for (; it != beforeEnd; ++it) {
        Particle* p1 = *it;
        if (p1->type != "Square") continue;

        auto itt = it;
        ++itt;

        for (; itt != particles.end(); ++itt) {
            Particle* p2 = *itt;
            if (p2->type != "Square") continue;

            if (p1->squareCollider.checkCollision(p2->squareCollider) && !squareFlag) {
                squareFlag = true;
                std::cout << "Square collision detected!" << std::endl;
            }
        }
    }
}

void PhysicsWorld::checkSATCollision() {
    auto it = satColliders.begin();
    auto beforeEnd = satColliders.end();
    beforeEnd--;

    for (; it != beforeEnd; ++it) {
        SATCollider* c1 = *it;

        auto itt = it;
        ++itt;

        for (; itt != satColliders.end(); ++itt) {
            SATCollider* c2 = *itt;

            if (c1->checkCollision(*c2)) {
                std::cout << "SAT collision detected between shapes!" << std::endl;
            }
        }
    }
}