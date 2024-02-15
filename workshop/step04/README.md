# 4. Far muovere la pallina

## Descrizione

In questo step faremo muovere la pallina in una direzione costante e velocità costante.

## Obiettivi

1. [ ] Far muovere la pallina.

## Svolgimento

### Obiettivo 1

Per far muovere gli oggetti del nostro gioco, inclusa la pallina, utilizzeremo la semplice formula fisica `spazio = velocità * tempo`. Integrando tale formula sullo spazio, vedremo che ogni frame dovremmo eseguire questa operazione: `posizione_pallina = posizione_pallina + velocità_pallina`.

La classe `sf::CircleShape` gestisce già la variabile della posizione, come vettore bidimensionale (`sf::Vector2f`). E' possibile modificare o ottenenere la posizione tramite `sf::CircleShape::setPosition` o `sf::CircleShape::getPosition`.

Creiamo quindi un oggetto di tipo `sf::Vector2f` per rappresentare la velocità della pallina, e aggiungiamone il valore alla posizione della pallina ogni frame.

## Risorse

- Documentazione `sf::CircleShape`: https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1CircleShape.php

- Documentazione `sf::Vector2<T>`: https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1Vector2.php

- CppReference (documentazione C++): http://en.cppreference.com/
