# 10. Gestire collisioni tra mattoncini e pallina

## Descrizione

In questo step implementeremo le collisioni tra mattoncino e palla.

## Obiettivi

1. [ ] Creare un sistema per distruggere e rimuovere i mattoncini colpiti.

2. [ ] Implementare le collisioni tra mattoncino e palla.

## Svolgimento

### Obiettivo 1

Dato che stiamo gestendo i mattoncini in un `std::vector`, dobbiamo trovare un modo di rimuoverli in maniera efficiente, in quanto uno `std::vector` è praticamente un array dinamico (memoria contigua). Ecco due tecniche per rimuovere un elemento da un vettore in maniera efficiente:

1. Swappare l'elemento colpito con l'ultimo elemento, e poi chiamare `std::vector<T>::pop_back`. Questa operazione è `O(1)`, ma la si deve ripetere per ogni mattoncino colpito. (In questo caso questa tecnica è valida perchè l'ordine dei mattoncini nel vettore non è importante.)

2. Marcare l'elemento colpito con una flag booleana, ed in seguito effettuare uno step di clean-up usando [l'idioma "`erase`-`remove`"](https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom). Con questa tecnica, "marcare" i mattoncini è estremamente efficiente. Lo step di cleanup è `O(N)`, ma lo si deve effettuare solo una volta per frame.

### Obiettivo 2

Simile in principio alle collisioni tra palla e giocatore, ma più complesso in pratica in quanto dobbiamo calcolare la direzione di rimbalzo della pallina in modo convincente, in base alla direzione dalla quale il mattoncino è stato colpito.

Un modo per capire in quale direzione la pallina dovrebbe rimbalzare è quello di calcolare quanto la pallina ha penetrato un mattoncino sull'asse X, e quanto sull'asse Y. Comparando le due penetrazioni, e scegliendo la più piccola, sarà possibile approssimare la direzione dalla quale la pallina ha colpito il mattoncino senza dover mantenere la "vecchia" posizione della pallina in memoria.

## Risorse

- Idioma "`erase`-`remove`": https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom

- Collisione AABB contro AABB in 2D: https://kishimotostudios.com/articles/aabb_collision/

- Intersezione AABB contro AABB più dettagliata: http://noonat.github.io/intersect/#aabb-vs-aabb

- Documentazione `sf::RectangleShape`: https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1RectangleShape.php

- Documentazione `sf::Vector2<T>`: https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1Vector2.php

- CppReference (documentazione C++): http://en.cppreference.com/
