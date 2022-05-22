#include "Textures.h"

Textures::Textures()
{
    int i = 0;
    for (int j = 0; j < 13; j++)
    {
        textures[j] = new sf::Texture;
    }
    if (!textures[i++]->loadFromFile("assets/AND.png"))     // 0
    {
        std::cout << "Failed to load asset: AND.png" << std::endl;
    }
    if (!textures[i++]->loadFromFile("assets/OR.png"))     // 1
    {
        std::cout << "Failed to load asset: OR.png" << std::endl;
    }
    if (!textures[i++]->loadFromFile("assets/XOR.png"))     // 2
    {
        std::cout << "Failed to load asset: XOR.png" << std::endl;
    }
    if (!textures[i++]->loadFromFile("assets/NOT.png"))     // 3
    {
        std::cout << "Failed to load asset: NOT.png" << std::endl;
    }
    if (!textures[i++]->loadFromFile("assets/DFF.png"))     // 4
    {
        std::cout << "Failed to load asset: DFF.png" << std::endl;
    }
    if (!textures[i++]->loadFromFile("assets/GND.png"))     // 5
    {
        std::cout << "Failed to load asset: GND.png" << std::endl;
    }
    if (!textures[i++]->loadFromFile("assets/VDD.png"))     // 6
    {
        std::cout << "Failed to load asset: VDD.png" << std::endl;
    }
    if (!textures[i++]->loadFromFile("assets/CLOCK.png"))     // 7
    {
        std::cout << "Failed to load asset: CLOCK.png" << std::endl;
    }
    if (!textures[i++]->loadFromFile("assets/LEDOFF.png"))     // 8
    {
        std::cout << "Failed to load asset: LEDOFF.png" << std::endl;
    }
    if (!textures[i++]->loadFromFile("assets/LEDON.png"))     // 9
    {
        std::cout << "Failed to load asset: LEDON.png" << std::endl;
    }
    if (!textures[i++]->loadFromFile("assets/TRASH.png"))     // 10
    {
        std::cout << "Failed to load asset: TRASH.png" << std::endl;
    }
    if (!textures[i++]->loadFromFile("assets/PLAY.png"))     // 11
    {
        std::cout << "Failed to load asset: PLAY.png" << std::endl;
    }
    if (!textures[i++]->loadFromFile("assets/STOP.png"))     // 12
    {
        std::cout << "Failed to load asset: STOP.png" << std::endl;
    }
}