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
    case sf::Keyboard::O:
        this->songLevel(false);
        break;
    case sf::Keyboard::P:
        this->songLevel(true);
        break;
    default:
        break;
    }
}

void GameEngine::playSong()
{
    if (!this->_isSong)
    {
        if (!this->_music.openFromFile(SONG))
            return;
        this->_music.play();
        this->_isSong = true;
        this->_music.setLoop(true);
    }
}

void GameEngine::songLevel(bool level)
{
    if (level && _volumeSong < 100)
        _volumeSong += 10;
    else if (!level && _volumeSong > 0)
        _volumeSong -= 10;
    this->_music.setVolume(_volumeSong);
}