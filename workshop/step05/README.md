# 5. Far rimbalzare la pallina contro i bordi della finestra

## Descrizione

In questo step faremo rimbalzare la pallina contro i bordi della finestra. Il rimbalzo sarà totalmente elastico -- la magnitudine della velocità rimarrà costante, ma la direzione varierà.

## Obiettivi

1. [ ] Far rimbalzare la pallina contro i bordi della finestra.

## Svolgimento

### Obiettivo 1

Al momento, la pallina scompare della finestra perché non gestiamo nessuna collisione. Fate rimbalzare la pallina ai bordi, ricordandovi che la posizione dove controllare la collisione varia in base alla direzione (e.g. la pallina colpisce il bordo di destra quando l'estremo destro della pallina lo sorpassa).

Ogni frame, controllate la posizione di alcuni punti chiave della pallina rispetto alle coordinate della finestra, e cambiate la velocità di conseguenza. In SFML, il sistema di coordinate inizia con `{0, 0}` in alto a sinistra, e finisce con `{risoluzioneX, risoluzioneY}` in basso a destra.

## Risorse

- Documentazione `sf::CircleShape`: https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1CircleShape.php

- Documentazione `sf::Vector2<T>`: https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1Vector2.php

- CppReference (documentazione C++): http://en.cppreference.com/
