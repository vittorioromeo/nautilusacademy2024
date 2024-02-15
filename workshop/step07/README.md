# 7. Visualizzare e far muovere il giocatore

## Descrizione

In questo step creeremo un rettangolo per il giocatore, e lo faremo muovere tramite l'uso della tastiera.

## Obiettivi

1. [ ] Creare un rettangolo statico che rappresenti il giocatore.

2. [ ] Far muovere il giocatore in una direzione fissa.

3. [ ] Far muovere il giocatore in base all'input della tastiera.

## Obiettivi bonus

1. [ ] Gestire la collisione tra il giocatore e i bordi della finestra.

## Svolgimento

### Obiettivo 1

Molto simile alla creazione della pallina, ma questa volta useremo [`sf::RectangleShape`](https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1RectangleShape.php).

### Obiettivo 2

Come la pallina, avremo bisogno di una variable che controlli la velocità del giocatore.

### Obiettivo 3

Utilizziamo la classe statica [`sf::Keyboard`](https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1Keyboard.php) e la funzione booleana [`sf::Keyboard::isKeyPressed`](https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1Keyboard.php#a80a04b2f53005886957f49eee3531599) per reagire in tempo reale allo stato della tastiera.

I vari controlli dovranno essere eseguiti dentro il game loop.

## Risorse

- Tutorial sugli input SFML: https://www.sfml-dev.org/tutorials/2.6/window-inputs.php

- Documentazione `sf::Keyboard`: https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1Keyboard.php

- Documentazione `sf::RectangleShape`: https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1RectangleShape.php

- Documentazione `sf::Vector2<T>`: https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1Vector2.php

- CppReference (documentazione C++): http://en.cppreference.com/
