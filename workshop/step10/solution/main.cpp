#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <vector>
#include <utility>
#include <cmath>
#include <cstddef>

const sf::Vector2f resolution{800.f, 600.f};

class Game
{
private:
    const float ballSpeed{6.f};
    const float playerSpeed{12.f};
    const sf::Vector2f brickSize{50.f, 24.f};

    sf::CircleShape ball;
    sf::Vector2f ballVelocity;

    sf::RectangleShape player;
    sf::Vector2f playerVelocity;

    std::vector<sf::RectangleShape> bricks;

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

    void initializeBall()
    {
        const float ballRadius{12.f};

        ball.setRadius(ballRadius);
        ball.setOrigin({ballRadius / 2.f, ballRadius / 2.f});
        ball.setFillColor(sf::Color::White);
        ball.setPosition(resolution / 2.f);
    }

    void initializePlayer()
    {
        const sf::Vector2f playerSize{128.f, 24.f};

        player.setSize(playerSize);
        player.setOrigin(playerSize / 2.f);
        player.setFillColor(sf::Color::White);
        player.setPosition(
            {resolution.x / 2.f, resolution.y - playerSize.y * 2});
    }

    void initializeBrick(
        sf::RectangleShape& brick, const sf::Vector2f& position)
    {
        brick.setSize(brickSize);
        brick.setOrigin(brickSize / 2.f);
        brick.setFillColor(sf::Color::White);
        brick.setPosition(position);
    }

    void createBrickGrid()
    {
        const float offsetX = 50.f;
        const float offsetY = 50.f;

        const std::size_t nBricksPerRow = 13;
        const std::size_t nRows = 4;

        const float spacing = 50.f / 14.f;

        float nextX = 0.f;
        float nextY = 0.f;

        for (std::size_t y = 0; y < nRows; ++y)
        {
            for (std::size_t x = 0; x <= nBricksPerRow; ++x)
            {
                sf::RectangleShape& brick = bricks.emplace_back();
                initializeBrick(brick, {offsetX + nextX, offsetY + nextY});

                nextX += spacing + brickSize.x;
            }

            nextX = 0;
            nextY += spacing + brickSize.y;
        }
    }

    bool testIntersectionBetweenBallAndRectangle(const sf::RectangleShape& rect)
    {
        const float ballLeft = ball.getPosition().x - ball.getRadius();
        const float ballRight = ball.getPosition().x + ball.getRadius();
        const float ballTop = ball.getPosition().y - ball.getRadius();
        const float ballBottom = ball.getPosition().y + ball.getRadius();

        const float rectHalfWidth = rect.getSize().x / 2.f;
        const float rectHalfHeight = rect.getSize().y / 2.f;
        const float rectLeft = rect.getPosition().x - rectHalfWidth;
        const float rectRight = rect.getPosition().x + rectHalfWidth;
        const float rectTop = rect.getPosition().y - rectHalfHeight;
        const float rectBottom = rect.getPosition().y + rectHalfHeight;

        const bool ballIsLeftOfRect = ballRight < rectLeft;
        const bool ballIsRightOfRect = ballLeft > rectRight;
        const bool ballIsAboveRect = ballBottom < rectTop;
        const bool ballIsBelowRect = ballTop > rectBottom;

        const bool anyIntersection = !ballIsLeftOfRect &&  //
                                     !ballIsRightOfRect && //
                                     !ballIsAboveRect &&   //
                                     !ballIsBelowRect;
        return anyIntersection;
    }

    // Collisione tra pallina e mattoncino
    bool performBallBrickCollisionResolution(const sf::RectangleShape& brick)
    {
        if (!testIntersectionBetweenBallAndRectangle(brick))
        {
            // Nessuna collisione, usciamo.
            return false;
        }

        const float ballLeft = ball.getPosition().x - ball.getRadius();
        const float ballRight = ball.getPosition().x + ball.getRadius();
        const float ballTop = ball.getPosition().y - ball.getRadius();
        const float ballBottom = ball.getPosition().y + ball.getRadius();

        const float brickHalfWidth = brick.getSize().x / 2.f;
        const float brickHalfHeight = brick.getSize().y / 2.f;
        const float brickLeft = brick.getPosition().x - brickHalfWidth;
        const float brickRight = brick.getPosition().x + brickHalfWidth;
        const float brickTop = brick.getPosition().y - brickHalfHeight;
        const float brickBottom = brick.getPosition().y + brickHalfHeight;

        // Calcoliamo l'intersezione da ogni direzione.
        const float overlapLeft{ballRight - brickLeft};
        const float overlapRight{brickRight - ballLeft};
        const float overlapTop{ballBottom - brickTop};
        const float overlapBottom{brickBottom - ballTop};

        // Se la magnitudine dell'intersezione da sinistra è minore di quella da
        // destra, possiamo concludere che il mattoncino è stato colpito da
        // sinistra.
        const bool ballFromLeft(std::abs(overlapLeft) < std::abs(overlapRight));

        // Stessa idea per sopra/sotto.
        const bool ballFromTop(std::abs(overlapTop) < std::abs(overlapBottom));

        // Conserviamo l'intersezione minima per asse.
        const float minOverlapX{ballFromLeft ? overlapLeft : overlapRight};
        const float minOverlapY{ballFromTop ? overlapTop : overlapBottom};

        // Se la magnitudine dell'intersezione sull'asse X è minore di quella
        // sull'asse Y, possiamo concludere che la pallina ha colpito il
        // mattoncino orizzontalmente, altrimenti verticalmente.

        // In base alla nostra conclusione, possiamo decidere se far rimbalzare
        // la pallina orizzontalmente o verticalmente, creando un rimbalzo
        // "realistico".
        if (std::abs(minOverlapX) < std::abs(minOverlapY))
        {
            ballVelocity.x = ballFromLeft ? -ballSpeed : ballSpeed;
        }
        else
        {
            ballVelocity.y = ballFromTop ? -ballSpeed : ballSpeed;
        }

        // Collisione!
        return true;
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

    void updateBallCollisionsAgainstPlayer()
    {
        if (!testIntersectionBetweenBallAndRectangle(player))
        {
            return;
        }

        ballVelocity.y = -ballSpeed;

        if (ball.getPosition().x < player.getPosition().x)
        {
            ballVelocity.x = -ballSpeed;
        }
        else
        {
            ballVelocity.x = ballSpeed;
        }
    }

    // Gestiamo tutte le collisioni tra pallina e mattoncini.
    void updateBallCollisionsAgainstBricks()
    {
        // Iteriamo su tutti i mattoncini...
        for (auto it = bricks.begin(); it != bricks.end(); ++it)
        {
            // Se c'è una collisione, swappiamo il mattoncino con quello alla
            // fine del `vector`, e chiamiamo `pop_back`.
            if (performBallBrickCollisionResolution(*it))
            {
                std::swap(*it, bricks.back());
                bricks.pop_back();
            }
        }
    }

    void updatePlayerInput()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            playerVelocity.x = -playerSpeed;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            playerVelocity.x = playerSpeed;
        }
        else
        {
            playerVelocity.x = 0;
        }
    }

    void updatePlayerMovement()
    {
        player.setPosition(player.getPosition() + playerVelocity);
    }

    void updatePlayerCollisionsAgainstBoundaries()
    {
        const float playerHalfWidth = player.getSize().x / 2.f;
        const float playerLeft = player.getPosition().x - playerHalfWidth;
        const float playerRight = player.getPosition().x + playerHalfWidth;

        const float boundaryLeft = 0.f;
        const float boundaryRight = resolution.x;

        const auto setPlayerX = [this](const float x)
        {
            sf::Vector2f newPosition = player.getPosition();
            newPosition.x = x;
            player.setPosition(newPosition);
        };

        if (playerLeft < boundaryLeft)
        {
            setPlayerX(boundaryLeft + playerHalfWidth);
        }
        else if (playerRight > boundaryRight)
        {
            setPlayerX(boundaryRight - playerHalfWidth);
        }
    }

public:
    Game() : ballVelocity{ballSpeed, ballSpeed}, playerVelocity{0.f, 0.f}
    {
        initializeBall();
        initializePlayer();

        createBrickGrid();
    }

    void update()
    {
        updateBallMovement();
        updateBallCollisionsAgainstBoundaries();
        updateBallCollisionsAgainstPlayer();
        updateBallCollisionsAgainstBricks();

        updatePlayerInput();
        updatePlayerMovement();
        updatePlayerCollisionsAgainstBoundaries();
    }

    void draw(sf::RenderTarget& renderTarget)
    {
        renderTarget.draw(ball);
        renderTarget.draw(player);

        for (const sf::RectangleShape& brick : bricks)
        {
            renderTarget.draw(brick);
        }
    }
};

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y),
        "Arkanoid", sf::Style::Default, settings);

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
