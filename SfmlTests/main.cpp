#include <SFML/Graphics.hpp>
#include "Renderer.h"
#include "PhysicsWorld.h"
#include "Particle.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Physics");
    window.setFramerateLimit(60);

    Renderer renderer;
    PhysicsWorld physicsWorld;

    sf::CircleShape circle(20.f);
    sf::CircleShape circle2(20.f);
    circle.setFillColor(sf::Color::Green);
    circle2.setFillColor(sf::Color::Red);
    circle.setPosition(400.f, 300.f);
    circle2.setPosition(600.f, 300.f);

    Particle particle(Vector2d(400.f, 300.f), 100.0f, 0.01f, "Circle");
    Particle particle2(Vector2d(600.f, 300.f), 20.0f, 0.0f, "Circle");

    particle.collider.r = 20.0f;
    particle2.collider.r = 20.0f;

    particle.velocity = Vector2d(50.0f, 0.0f);
    particle2.velocity = Vector2d(-50.0f, 0.0f);

    physicsWorld.addParticle(&particle);
    physicsWorld.addParticle(&particle2);

    sf::RectangleShape square(sf::Vector2f(40.f, 40.f));
    sf::RectangleShape square2(sf::Vector2f(40.f, 40.f));
    square.setFillColor(sf::Color::Blue);
    square2.setFillColor(sf::Color::Yellow);
    square.setPosition(400.f, 400.f);
    square2.setPosition(600.f, 400.f);

    Particle squareParticle(Vector2d(400.f, 400.f), 600.0f, 0.0f, "Square");
    Particle squareParticle2(Vector2d(600.f, 400.f), 100.0f, 0.0f, "Square");

    squareParticle.velocity = Vector2d(50.0f, 0.0f);
    squareParticle2.velocity = Vector2d(-50.0f, 0.0f);

    physicsWorld.addParticle(&squareParticle);
    physicsWorld.addParticle(&squareParticle2);

    SATCollider shape1;
    shape1.points = {
        Vector2d(100, 200), Vector2d(350, 250), Vector2d(325, 300),
        Vector2d(275, 300), Vector2d(250, 250)
    };
    shape1.updatePosition(Vector2d(-400, 100));

    SATCollider shape2;
    shape2.points = {
        Vector2d(700, 400), Vector2d(550, 450), Vector2d(525, 500),
        Vector2d(475, 500), Vector2d(450, 450)
    };

    shape2.updatePosition(Vector2d(300, 300));

    sf::ConvexShape convexShape1;
    convexShape1.setPointCount(shape1.points.size());
    convexShape1.setFillColor(sf::Color::Cyan);
    for (size_t i = 0; i < shape1.points.size(); i++) {
        convexShape1.setPoint(i, sf::Vector2f(shape1.points[i].x, shape1.points[i].y));
    }

    sf::ConvexShape convexShape2;
    convexShape2.setPointCount(shape2.points.size());
    convexShape2.setFillColor(sf::Color::Magenta);
    for (size_t i = 0; i < shape2.points.size(); i++) {
        convexShape2.setPoint(i, sf::Vector2f(shape2.points[i].x, shape2.points[i].y));
    }

    shape1.velocity = Vector2d(50.0f, 0.0f);
    shape2.velocity = Vector2d(-50.0f, 0.0f);

    physicsWorld.addSATCollider(&shape1);
    physicsWorld.addSATCollider(&shape2);
    
    renderer.AddDrawable(&circle);
    renderer.AddDrawable(&circle2);
    renderer.AddDrawable(&square);
    renderer.AddDrawable(&square2);
    renderer.AddDrawable(&convexShape1);
    renderer.AddDrawable(&convexShape2);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();

        physicsWorld.Update(deltaTime);
        physicsWorld.checkTwoCircleCollision();
        physicsWorld.checkAABBCollision();
        //physicsWorld.checkSATCollision();
        circle.setPosition(particle.postion.x, particle.postion.y);
        circle2.setPosition(particle2.postion.x, particle.postion.y);
        square.setPosition(squareParticle.postion.x, squareParticle.postion.y);
        square2.setPosition(squareParticle2.postion.x, squareParticle2.postion.y);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D) {
            shape2.updatePosition(shape2.position + Vector2d(100, 0));
        }
        renderer.Render(&window);
    }

    return 0;
}
