/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GameEngine
*/

#include "GameEngine.hpp"

GameEngine::GameEngine()
{
}

GameEngine::~GameEngine()
{
}

void GameEngine::TreatmentEvent(sf::Event event)
{
    std::cout << "hol" << std::endl;
    switch (event.key.code)
    {
    case sf::Keyboard::W:
        std::cout << "UP" << std::endl;
        break;
    case sf::Keyboard::S:
        std::cout << "Down" << std::endl;
        break;
    case sf::Keyboard::A:
        std::cout << "Left" << std::endl;
        break;
    case sf::Keyboard::D:
        std::cout << "Right" << std::endl;
        break;
    case sf::Keyboard::Escape:
        std::cout << "Pause" << std::endl;
        break;
    case sf::Keyboard::Space:
        std::cout << "Space" << std::endl;
        break;
    default:
        break;
    }
}