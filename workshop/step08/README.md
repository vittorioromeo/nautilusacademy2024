# 8. Gestire collisioni tra giocatore e pallina

## Descrizione

In questo step faremo rimbalzare la pallina sul giocatore.

## Obiettivi

1. [ ] Far rimbalzare la pallina sul giocatore.

## Obiettivi bonus

1. [ ] Variare l'angolo della pallina in base a dove viene colpito il giocatore.

    - Questo obiettivo è un pò laborioso. L'idea è che se il giocatore viene colpito vicino ai bordi, la pallina dovrebbe rimbalzare con un angolo più acuto, mentre se il giocatore viene colpito vicino al centro, la pallina dovrebbe rimbalzare quasi verticalmente. Per ottenere questo risultato, ci vuole un pò di trigonometria base tramite `std::sin` e `std::cos`. La soluzione fornita non implementa questo obiettivo.

## Svolgimento

### Obiettivo 1

Il risultato sarà molto simile al rimbalzo della pallina contro i bordi della finestra, ma questa volta contro il giocatore. Tuttavia, l'implementazione è diversa -- bisogna capire come gestire la collisione contro il giocatore e verificare come far rimbalzare la pallina in base al lato del giocatore colpito.

Dovrete calcolare l'intersezione tra le due forme, e gestirne il risultato. Per semplicità, potete far finta che la pallina sia un quadrato, invece che un cerchio. Le risorse sottostanti vi aiuteranno.

## Risorse

- Collisione AABB contro AABB in 2D: https://kishimotostudios.com/articles/aabb_collision/

- Intersezione AABB contro AABB più dettagliata: http://noonat.github.io/intersect/#aabb-vs-aabb

- Documentazione `sf::RectangleShape`: https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1RectangleShape.php

- Documentazione `sf::Vector2<T>`: https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1Vector2.php

- CppReference (documentazione C++): http://en.cppreference.com/
