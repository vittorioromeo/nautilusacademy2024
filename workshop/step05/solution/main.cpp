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

    sf::Vector2f ballVelocity{0.1f, 0.1f};

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

        ball.setPosition(ball.getPosition() + ballVelocity);

        // Definiamo delle variabili per gli estremi della pallina.
        const float ballLeft = ball.getPosition().x - ball.getRadius();
        const float ballRight = ball.getPosition().x + ball.getRadius();
        const float ballTop = ball.getPosition().y - ball.getRadius();
        const float ballBottom = ball.getPosition().y + ball.getRadius();

        // Definiamo delle variabili per gli estremi della finestra.
        const float boundaryLeft = 0.f;
        const float boundaryRight = resolution.x;
        const float boundaryTop = 0.f;
        const float boundaryBottom = resolution.y;

        // Controlliamo le coordinate...
        if (ballLeft < boundaryLeft)
        {
            // Invertiamo la velocità.
            ballVelocity.x = -ballVelocity.x;

            // Spingiamo la pallina di nuovo dentro la finestra per evitare
            // doppie collisioni.
            sf::Vector2f newPosition = ball.getPosition();
            newPosition.x = boundaryLeft + radius;
            ball.setPosition(newPosition);
        }
        else if (ballRight > boundaryRight)
        {
            ballVelocity.x = -ballVelocity.x;

            sf::Vector2f newPosition = ball.getPosition();
            newPosition.x = boundaryRight - radius;
            ball.setPosition(newPosition);
        }

        if (ballTop < boundaryTop)
        {
            ballVelocity.y = -ballVelocity.y;

            sf::Vector2f newPosition = ball.getPosition();
            newPosition.y = boundaryTop + radius;
            ball.setPosition(newPosition);
        }
        else if (ballBottom > boundaryBottom)
        {
            ballVelocity.y = -ballVelocity.y;

            sf::Vector2f newPosition = ball.getPosition();
            newPosition.y = boundaryBottom - radius;
            ball.setPosition(newPosition);
        }

        window.clear();
        window.draw(ball);
        window.display();
    }

    // ------------------------------------------------------------------------

    return 0;
}
