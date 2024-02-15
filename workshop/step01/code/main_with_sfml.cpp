#include <SFML/Graphics/Color.hpp>
#include <iostream>

int main()
{
    auto color = sf::Color::Red;
    std::cout << "r, g, b={" << static_cast<int>(color.r) << ", "
              << static_cast<int>(color.g) << ", " << static_cast<int>(color.b)
              << "}\n";
}
