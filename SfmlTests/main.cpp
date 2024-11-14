#include <SFML/Graphics.hpp>
#include "Renderer.h"
#include "PhysicsWorld.h"
#include "Particle.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Circle");
    window.setFramerateLimit(60);

    Renderer renderer;
    PhysicsWorld physicsWorld;

    sf::CircleShape circle(20.f);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(400.f, 100.f);

    Particle particle(Vector2d(400.f, 100.f), 1.0f);
    physicsWorld.addParticle(&particle);

    renderer.AddDrawable(&circle);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = 10.0f / 60.0f;
        physicsWorld.Update(deltaTime);

        circle.setPosition(particle.postion.x, particle.postion.y);

        renderer.Render(&window);
    }

    return 0;
}