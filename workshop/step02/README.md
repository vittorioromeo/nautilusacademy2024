# 2. Creare una finestra di rendering

## Descrizione

In questo step apriremo una finestra di rendering tramite SFML, che sarà poi usata per renderizzare gli elementi di gioco.

## Obiettivi

1. [ ] Far apparire una finestra di rendering.

2. [ ] Gestire l'evento di chiusura della finestra, permettendo l'uscita dal programma.

## Svolgimento

### Obiettivo 1

La classe SFML che rappresenta una finestra è [`sf::RenderWindow`](https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1RenderWindow.php). Per crearne una, basta usare il costruttore:

```cpp
#include <SFML/Graphics/RenderWindow.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Arkanoid");
}
```

Noterete che con il codice mostrato sopra, la finestra non sopravvive per molto tempo. Date un'occhiata al [tutorial sulle finestre di SFML](https://www.sfml-dev.org/tutorials/2.6/window-window.php) -- come è possibile mantenerla in vita?

### Obiettivo 2

Se siete riusciti a mantenere la finestra in vita (per esempio con un loop), noterete che la finestra non risponde ai nostri comandi. SFML usa un sistema ad eventi per gestire la comunicazione tra la finestra e l'utente. Chiamando il metodo [`sf::RenderWindow::pollEvent`](https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1Window.php#a338e996585faf82e93069858e3b531b7) all'interno del loop di gioco, è possibile attivare questo canale di comunicazione.

Per chiudere il programma quando si preme il pulsante `[X]` della finestra, bisogna gestire l'evento `sf::Event::Closed`.

## Risorse

- Tutorial SFML sulle finestre: https://www.sfml-dev.org/tutorials/2.6/window-window.php

- Documentazione `sf::RenderWindow`: https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1RenderWindow.php

- Documentazione `sf::Event`: https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1Event.php

- CppReference (documentazione C++): http://en.cppreference.com/
