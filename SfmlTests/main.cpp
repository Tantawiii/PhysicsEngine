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
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(400.f, 300.f);

    Particle particle(Vector2d(400.f, 300.f), 20.0f, 0.01f);
    //particle.velocity = Vector2d(50.0f, 0.0f);
    physicsWorld.addParticle(&particle);


    renderer.AddDrawable(&circle);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        float deltaTime = clock.restart().asSeconds();
        //particle.addForce(Vector2d(50, 500));
        physicsWorld.Update(deltaTime);

        circle.setPosition(particle.postion.x, particle.postion.y);

        renderer.Render(&window);
    }

    return 0;
}
