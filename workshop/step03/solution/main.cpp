#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

int main()
{
    // Aggiungiamo una variabile per la risoluzione per convenienza.
    const sf::Vector2f resolution{800.f, 600.f};

    // Settaggi del contesto di rendering, incluso antialiasing.
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y),
        "Arkanoid", sf::Style::Default, settings);

    // Raggio della pallina.
    const float radius = 12.f;

    // Creiamo un oggetto di tipo `sf::CircleShape` che rappresenta la pallina.
    sf::CircleShape ball;

    // Settiamo raggio, origine, e colore.
    ball.setRadius(radius);
    ball.setOrigin({radius / 2.f, radius / 2.f});
    ball.setFillColor(sf::Color::White);

    // Posizioniamo la pallina al centro dello schermo.
    ball.setPosition(resolution / 2.f);

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

        // Puliamo la finestra.
        window.clear();

        // Renderizziamo la pallina sulla finestra.
        window.draw(ball);

        // Mostriamo il buffer sullo schermo.
        window.display();
    }

    return 0;
}
