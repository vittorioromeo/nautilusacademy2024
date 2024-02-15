#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

const sf::Vector2f resolution{800.f, 600.f};

// Refactoring: il nostro gioco ora è una classe con `update` e `draw`.
class Game
{
private:
    sf::CircleShape ball;
    sf::Vector2f ballVelocity;

    void setBallX(const float x)
    {
        sf::Vector2f newPosition = ball.getPosition();
        newPosition.x = x;
        ball.setPosition(newPosition);
    }

    void setBallY(const float y)
    {
        sf::Vector2f newPosition = ball.getPosition();
        newPosition.y = y;
        ball.setPosition(newPosition);
    }

    void updateBallMovement()
    {
        ball.setPosition(ball.getPosition() + ballVelocity);
    }

    void updateBallCollisionsAgainstBoundaries()
    {
        const float ballLeft = ball.getPosition().x - ball.getRadius();
        const float ballRight = ball.getPosition().x + ball.getRadius();
        const float ballTop = ball.getPosition().y - ball.getRadius();
        const float ballBottom = ball.getPosition().y + ball.getRadius();

        const float boundaryLeft = 0.f;
        const float boundaryRight = resolution.x;
        const float boundaryTop = 0.f;
        const float boundaryBottom = resolution.y;

        if (ballLeft < boundaryLeft)
        {
            ballVelocity.x = -ballVelocity.x;
            setBallX(boundaryLeft + ball.getRadius());
        }
        else if (ballRight > boundaryRight)
        {
            ballVelocity.x = -ballVelocity.x;
            setBallX(boundaryRight - ball.getRadius());
        }

        if (ballTop < boundaryTop)
        {
            ballVelocity.y = -ballVelocity.y;
            setBallY(boundaryTop + ball.getRadius());
        }
        else if (ballBottom > boundaryBottom)
        {
            ballVelocity.y = -ballVelocity.y;
            setBallY(boundaryBottom - ball.getRadius());
        }
    }

public:
    Game() : ballVelocity{6.f, 6.f}
    {
        const float ballRadius{12};

        ball.setRadius(ballRadius);
        ball.setOrigin({ballRadius / 2.f, ballRadius / 2.f});
        ball.setFillColor(sf::Color::White);
        ball.setPosition(resolution / 2.f);
    }

    void update()
    {
        updateBallMovement();
        updateBallCollisionsAgainstBoundaries();
    }

    void draw(sf::RenderTarget& renderTarget)
    {
        renderTarget.draw(ball);
    }
};

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y),
        "Arkanoid", sf::Style::Default, settings);

    // Settiamo un limite di FPS.
    window.setFramerateLimit(60);

    // ------------------------------------------------------------------------

    Game game;

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

        game.update();

        window.clear();
        game.draw(window);
        window.display();
    }

    // ------------------------------------------------------------------------

    return 0;
}
