#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

int main()
{
    const sf::Vector2f resolution{800.f, 600.f};

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y),
        "Arkanoid", sf::Style::Default, settings);

    // ------------------------------------------------------------------------

    const float radius = 12.f;

    sf::CircleShape ball;
    ball.setRadius(radius);
    ball.setOrigin({radius / 2.f, radius / 2.f});
    ball.setFillColor(sf::Color::White);
    ball.setPosition(resolution / 2.f);

    // ------------------------------------------------------------------------

    // Creiamo una variable per gestire il moto della pallina.
    const sf::Vector2f ballVelocity{0.1f, 0.1f};

    // ------------------------------------------------------------------------

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Aggiungiamo la velocità alla posizione ogni frame.
        ball.setPosition(ball.getPosition() + ballVelocity);

        window.clear();
        window.draw(ball);
        window.display();
    }

    // ------------------------------------------------------------------------

    return 0;
}
