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
                handleElasticCollision(p1, p2);
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
                handleElasticCollision(p1, p2);
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

void PhysicsWorld::handleElasticCollision(Particle* p1, Particle* p2) {
    Vector2d v1 = p1->velocity;
    float m1 = p1->mass;
    Vector2d x1 = p1->postion;

    Vector2d v2 = p2->velocity;
    float m2 = p2->mass;
    Vector2d x2 = p2->postion;

    Vector2d normal1 = x1 - x2;
    float dot1 = (v1 - v2).Dot(normal1);

    float normalMag = normal1.getMagnitude();
    dot1 /= normalMag;

    Vector2d normal2 = x2 - x1;
    float dot2 = (v2 - v1).Dot(normal2);

    normalMag = normal2.getMagnitude();
    dot2 /= normalMag;

    v1 = v1 - normal1 *  (dot1 * ((2 * m2) / (m1 + m2)));
    v2 = v2 - normal2 * (dot2 * ((2 * m1) / (m1 + m2)));

    p1->velocity = v1;
    p2->velocity = v2;

    p1->postion += normal1.getNormalized() * 5;
    p2->postion += normal2.getNormalized() * 5;

    std::cout << "Elastic collision handled: Velocities updated!" << std::endl;
}