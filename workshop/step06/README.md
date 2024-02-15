# 6. Gestire la velocità di simulazione del gioco

## Descrizione

In questo step limiteremo la velocità di simulazione del gioco.

## Obiettivi

1. [ ] Limitare la velocità di simulazione del gioco.

## Obiettivi bonus

1. [ ] Pensare ai lati negativi della limitazione di FPS.

2. [ ] Informarsi su varie metodologie di gestire il loop di simulazione.

    - [Getting The Game Loop Right - Vittorio Romeo](https://www.youtube.com/watch?v=lW6ZtvQVzyg)

    - [Fix Your Timestep! - Gaffer On Games](https://gafferongames.com/post/fix_your_timestep/)

3. [ ] Pulire un pò il codice (refactoring) per evitare duplicazione.

## Svolgimento

### Obiettivo 1

La nostra implementazione corrente cerca di eseguire più frame possibili, senza porre alcun limite alla velocità di simulazione di gioco. Ciò significa che, in base alla macchina dove il gioco viene eseguito, la simulazione sara più o meno veloce. Ci sono tanti modi di risolvere questo problema, ma SFML fornisce una comoda funzione [`sf::RenderWindow::setFramerateLimit`](https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1Window.php#af4322d315baf93405bf0d5087ad5e784) che ci permette di settare un limite di FPS (frames per second).

## Risorse

- Documentazione `sf::CircleShape`: https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1CircleShape.php

- Documentazione `sf::Vector2<T>`: https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1Vector2.php

- CppReference (documentazione C++): http://en.cppreference.com/
