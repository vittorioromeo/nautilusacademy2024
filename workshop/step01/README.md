# 1. Avere un ambiente di sviluppo funzionante

## Descrizione

Questo step preliminare ci permetterà di verificare che tutti abbiano un ambiente di sviluppo funzionante con la libreria SFML.

## Obiettivi

1. [ ] Compilare un semplice programma che *non* usa SFML.

2. [ ] Compilare un semplice programma che usa SFML.

## Svolgimento

### Obiettivo 1

Per prima cosa assicuratevi di avere un ambiente di sviluppo dove poter compilare un programma in C++ senza alcuna dipendenza. Personalmente io uso [MSYS2/MinGW](https://www.msys2.org/) su Windows 10, ma va bene qualsiasi cosa (e.g. Visual Studio, WSL2, una distribuzione Linux con `gcc` o `clang`, etc).

Per esempio, il seguente programma (vedi [`code/main_without_sfml.cpp`](./code/main_without_sfml.cpp))

```cpp
#include <iostream>

int main()
{
    auto greeting = "Hello world!"; // `auto` richiede C++11
    std::cout << greeting << '\n';
}
```

dovrebbe funzionare con qualsiasi compilatore che supporti C++11 -- assicuratevene per completare l'obiettivo (1). Per compilarlo da linea di comando, assumendo che il codice sia in `main_without_sfml.cpp`, potete usare questi comandi su una shell Linux, WSL, o MSYS2/MinGW:

```bash
# compilazione con warning abilitati e modalità C++17
g++ -Wall -Wextra -Wpedantic -std=c++17 ./main_without_sfml.cpp -o ./main_without_sfml.exe

# esecuzione del programma
./main_without_sfml.exe
```

Se invece usate Visual Studio, dovrebbe essere sufficiente usare l'interfaccia grafica per compilare ed eseguire il programma.

### Obiettivo 2

Ecco un programma che usa SFML (vedi [`code/main_with_sfml.cpp`](./code/main_with_sfml.cpp)):

```cpp
#include <SFML/Graphics/Color.hpp>
#include <iostream>

int main()
{
    auto color = sf::Color::Red;
    std::cout << "r, g, b={" << static_cast<int>(color.r) << ", "
              << static_cast<int>(color.g) << ", " << static_cast<int>(color.b)
              << "}\n";
}
```

Per compilare tale programma bisogna agguingere la cartella `SFML/include` tra le "include paths", e linkare le librerie `sfml-graphics`, `sfml-window`, e `sfml-system`. Da linea di comando:

```bash
g++ -Wall -Wextra -Wpedantic -std=c++17 \
    -I<DIRECTORY_DI_SFML>/include \
    -L<DIRECTORY_DI_SFML>/lib \
    -lsfml-graphics -lsfml-window -lsfml-system \
    ./main_with_sfml.cpp -o ./main_with_sfml.exe

./main_with_sfml.exe
```

Se invece usate Visual Studio, dovete seguire [**queste istruzioni**](https://www.sfml-dev.org/tutorials/2.6/start-vc.php) per includere e linkare SFML.

## Risorse

- Pagina download SFML: https://www.sfml-dev.org/download.php

- Come installare SFML su Visual Studio: https://www.sfml-dev.org/tutorials/2.6/start-vc.php

- Come installare SFML su altre piattaforme: https://www.sfml-dev.org/tutorials/2.6/

- CppReference (documentazione C++): http://en.cppreference.com/
