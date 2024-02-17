# 3. Visualizzare una pallina sulla finestra

## Descrizione

In questo step visualizzeremo una pallina statica sulla finestra.

## Obiettivi

1. [ ] "Pulire" la finestra e mandare il buffer corrente al sistema di rendering.

2. [ ] Creare e renderizzare un cerchio statico.

## Obiettivi bonus

1. [ ] Abilitare l'antialiasing per la finestra.

## Svolgimento

### Obiettivo 1

`sf::RenderWindow` deve essere pulita tramite [`sf::RenderWindow::clear`](https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1RenderTarget.php#a6bb6f0ba348f2b1e2f46114aeaf60f26) all'inizio di ogni frame di rendering. Dopo tale operazione, si possono iniziare a renderizzare vari elementi sulla finestra. Dopo aver finito, bisogna comunicare alla finestra di visualizzare tutto ciò che è stato renderizzato tramite [`sf::RenderWindow::display`](https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1Window.php#adabf839cb103ac96cfc82f781638772a):

```cpp
// ...

while (window.isOpen())
{
    // ...

    window.clear();
    // ...renderizziamo roba...
    window.display();

    // ...
}

// ...
```

### Obiettivo 2

SFML fornisce varie classi per la creazione di forme e immagini. Per creare un cerchio, possiamo usare [`sf::CircleShape`](https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1CircleShape.php). Dopo averne creato un'istanza, bisogna sistemare alcune proprietà come il raggio ed il colore -- date un'occhiata alla documentazione per vedere come fare.

Dopo aver creato un oggetto di tipo `sf::CircleShape`, settatene il raggio, l'origine, e il colore. Poi usate `sf::RenderWindow::draw`, passando la pallina come argomento della funzione, per disegnarla sullo schermo. Ricordate di posizionare la chiamata a `sf::RenderWindow::draw` tra quella a `sf::RenderWindow::clear` e quella a `sf::RenderWindow::display`.

## Risorse

- Tutorial SFML su come renderizzare in 2D: https://www.sfml-dev.org/tutorials/2.6/graphics-draw.php

- Tutorial SFML sulle forme: https://www.sfml-dev.org/tutorials/2.6/graphics-shape.php

- Documentazione `sf::RenderWindow`: https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1RenderWindow.php

- Documentazione `sf::CircleShape`: https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1CircleShape.php

- CppReference (documentazione C++): http://en.cppreference.com/
