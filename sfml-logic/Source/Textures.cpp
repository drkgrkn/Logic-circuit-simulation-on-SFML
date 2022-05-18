#include "Textures.h"

Textures::Textures()
{
  /*0-AND
    1 -OR
    2 -XOR
    3 -NOT
    4 -DFF
    5 -GND
    6 -VDD
    7 -CLOCK
    8 -LEDOFF
    9 -LEDON
    10-PLAY
    11-STOP*/

    if (!textures[0].loadFromFile("assets/AND.png"))
    {
        std::cout << "Failed to load asset: AND.png" << std::endl;
    }
    if (!textures[1].loadFromFile("assets/OR.png"))
    {
        std::cout << "Failed to load asset: OR.png" << std::endl;
    }
    if (!textures[2].loadFromFile("assets/XOR.png"))
    {
        std::cout << "Failed to load asset: XOR.png" << std::endl;
    }
    if (!textures[3].loadFromFile("assets/NOT.png"))
    {
        std::cout << "Failed to load asset: NOT.png" << std::endl;
    }
    if (!textures[4].loadFromFile("assets/DFF.png"))
    {
        std::cout << "Failed to load asset: DFF.png" << std::endl;
    }
    if (!textures[5].loadFromFile("assets/GND.png"))
    {
        std::cout << "Failed to load asset: GND.png" << std::endl;
    }
    if (!textures[6].loadFromFile("assets/VDD.png"))
    {
        std::cout << "Failed to load asset: VDD.png" << std::endl;
    }
    if (!textures[7].loadFromFile("assets/CLOCK.png"))
    {
        std::cout << "Failed to load asset: CLOCK.png" << std::endl;
    }
    if (!textures[8].loadFromFile("assets/LEDOFF.png"))
    {
        std::cout << "Failed to load asset: LEDOFF.png" << std::endl;
    }
    if (!textures[9].loadFromFile("assets/LEDON.png"))
    {
        std::cout << "Failed to load asset: LEDON.png" << std::endl;
    }
    if (!textures[10].loadFromFile("assets/PLAY.png"))
    {
        std::cout << "Failed to load asset: PLAY.png" << std::endl;
    }
    if (!textures[11].loadFromFile("assets/STOP.png"))
    {
        std::cout << "Failed to load asset: STOP.png" << std::endl;
    }

}
