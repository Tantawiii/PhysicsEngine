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

    Particle particle(Vector2d(400.f, 300.f), 20.0f, 0.01f, "Circle");
    Particle particle2(Vector2d(600.f, 300.f), 1.0f, 0.0f, "Circle");

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

    Particle squareParticle(Vector2d(400.f, 400.f), 1.0f, 0.0f, "Square");
    Particle squareParticle2(Vector2d(600.f, 400.f), 1.0f, 0.0f, "Square");

    squareParticle.velocity = Vector2d(50.0f, 0.0f);
    squareParticle2.velocity = Vector2d(-50.0f, 0.0f);

    physicsWorld.addParticle(&squareParticle);
    physicsWorld.addParticle(&squareParticle2);

    renderer.AddDrawable(&circle);
    renderer.AddDrawable(&circle2);
    renderer.AddDrawable(&square);
    renderer.AddDrawable(&square2);

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
        //physicsWorld.checkAABBCollision();
        circle.setPosition(particle.postion.x, particle.postion.y);
        circle2.setPosition(particle2.postion.x, particle.postion.y);
        square.setPosition(squareParticle.postion.x, squareParticle.postion.y);
        square2.setPosition(squareParticle2.postion.x, squareParticle2.postion.y);

        renderer.Render(&window);
    }

    return 0;
}
