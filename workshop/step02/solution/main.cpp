#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Arkanoid");

    // Teniamo la finestra in vita fino alla fine del programma.
    while (window.isOpen())
    {
        // Gestiamo tutti gli eventi generati dalla finestra.
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Gestiamo l'evento di chiusura della finestra.
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
    }

    return 0;
}
