#include "Textures.h"



Textures::Textures()
{
    int i = 0;
    for (int j = 0; j < 12; j++)
    {
        textures[j] = new sf::Texture;
    }
    if (!textures[i++]->loadFromFile("assets/AND.png"))
    {
        std::cout << "Failed to load asset: AND.png" << std::endl;
    }
    if (!textures[i++]->loadFromFile("assets/OR.png"))
    {
        std::cout << "Failed to load asset: OR.png" << std::endl;
    }
    if (!textures[i++]->loadFromFile("assets/XOR.png"))
    {
        std::cout << "Failed to load asset: XOR.png" << std::endl;
    }
    if (!textures[i++]->loadFromFile("assets/NOT.png"))
    {
        std::cout << "Failed to load asset: NOT.png" << std::endl;
    }
    if (!textures[i++]->loadFromFile("assets/DFF.png"))
    {
        std::cout << "Failed to load asset: DFF.png" << std::endl;
    }
    if (!textures[i++]->loadFromFile("assets/GND.png"))
    {
        std::cout << "Failed to load asset: GND.png" << std::endl;
    }
    if (!textures[i++]->loadFromFile("assets/VDD.png"))
    {
        std::cout << "Failed to load asset: VDD.png" << std::endl;
    }
    if (!textures[i++]->loadFromFile("assets/CLOCK.png"))
    {
        std::cout << "Failed to load asset: CLOCK.png" << std::endl;
    }
    if (!textures[i++]->loadFromFile("assets/LEDOFF.png"))
    {
        std::cout << "Failed to load asset: LEDOFF.png" << std::endl;
    }
    if (!textures[i++]->loadFromFile("assets/LEDON.png"))
    {
        std::cout << "Failed to load asset: LEDON.png" << std::endl;
    }
    if (!textures[i++]->loadFromFile("assets/PLAY.png"))
    {
        std::cout << "Failed to load asset: PLAY.png" << std::endl;
    }
    if (!textures[i++]->loadFromFile("assets/STOP.png"))
    {
        std::cout << "Failed to load asset: STOP.png" << std::endl;
    }
}