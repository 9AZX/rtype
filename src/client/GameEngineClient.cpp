/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GameEngineClient
*/

#include "GameEngineClient.hpp"

GameEngineClient::GameEngineClient()
{
}

GameEngineClient::~GameEngineClient()
{
}

void GameEngineClient::TreatmentEvent(sf::Event event, std::shared_ptr<Network> network)
{
    sf::Packet packet;
    switch (event.key.code)
    {
        case sf::Keyboard::W:
            std::cout << "UP" << std::endl;
            packet << 1 << 0 << 4;
            network->sendData(packet);
            break;
        case sf::Keyboard::S:
            std::cout << "Down" << std::endl;
            packet << 1 << 2 << 4;
            network->sendData(packet);
            break;
        case sf::Keyboard::A:
            packet << 1 << 3 << 4;
            network->sendData(packet);
            std::cout << "Left" << std::endl;
            break;
        case sf::Keyboard::D:
            std::cout << "Right" << std::endl;
            packet << 1 << 1 << 4;
            network->sendData(packet);
            break;
        case sf::Keyboard::Escape:
            std::cout << "Pause" << std::endl;
            break;
        case sf::Keyboard::Space:
            std::cout << "Space" << std::endl;
            break;
        case sf::Keyboard::I:
            this->songLevel(false);
            break;
        case sf::Keyboard::O:
            this->songLevel(true);
            break;
        case sf::Keyboard::P:
            this->songPause();
            break;
        default:
            break;
    }
}

void GameEngineClient::playSong()
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

void GameEngineClient::songLevel(bool level)
{
    if (level && _volumeSong < 100)
        _volumeSong += 10;
    else if (!level && _volumeSong > 0)
        _volumeSong -= 10;
    this->_music.setVolume(_volumeSong);
}

void GameEngineClient::songPause()
{
    if (this->_songStatus)
    {
        this->_music.pause();
        this->_songStatus = false;
    }
    else
    {
        this->_music.play();
        this->_songStatus = true;
    }
}