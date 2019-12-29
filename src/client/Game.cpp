/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Game
*/

#include "Game.hpp"

Game::Game() : _window(std::make_shared<sf::RenderWindow>(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "R-Type"))
{
    this->_gameEngine = std::make_shared<GameEngineClient>();
    this->_window->setFramerateLimit(FRAMERATE_LIMIT);
    this->_menu = std::make_unique<Menu>(this->_window, this->_isMenu);
}

Game::~Game()
{
}

std::shared_ptr<GameEngineClient> Game::getGameEngine() const
{
    return this->_gameEngine;
}

void Game::initNetwork()
{
    this->_network = std::make_unique<Network>();
    this->_network->bindSocket();
}

void Game::unpack()
{
    int type = -1;
    int size = -1;
    int typeEntity = -1;
    int posX;
    int posY;
    int id;
    this->_network->_packet >> type;
    this->_network->_packet >> size;
    for (int i = 0; i < size; i++)
    {
        this->_network->_packet >> typeEntity;
        this->_network->_packet >> id;
        this->_network->_packet >> posX;
        this->_network->_packet >> posY;
        if (!updateEntity(id, posX, posY))
        {
            createEntity(id, Game::entities::MOB1, posX, posY);
        }
    }
    this->_network->_packet >> type;
    this->_network->_packet >> size;
    for (int i = 0; i < size; i++)
    {
        this->_network->_packet >> id;
        this->_network->_packet >> posX;
        this->_network->_packet >> posY;
        if (!updateEntity(id, posX, posY))
        {
            createEntity(id, Game::entities::PLAYER1, posX, posY);
        }
    }
}

void Game::createEntity(int &uniqueId, Game::entities type, int &posX, int &posY)
{
    this->_entities.push_back(std::make_unique<Entity>(type, uniqueId, posX, posY));
    std::cout << "Entity " << uniqueId << " created." << std::endl;
}

bool Game::updateEntity(int &uniqueId, int &posX, int &posY)
{
    for (size_t i = 0; i < this->_entities.size(); i++)
    {
        if (this->_entities[i]->getId() == uniqueId)
        {
            this->_entities[static_cast<int>(i)]->updatePosition(posX, posY);
            return true;
        }
    }
    return false;
}

void Game::deleteEntity(int &uniqueId)
{
    for (size_t i = 0; i < this->_entities.size(); i++)
    {
        if (this->_entities[i]->getId() == uniqueId)
        {
            this->_entities.erase(this->_entities.begin() + static_cast<int>(i));
            std::cout << "Entity " << uniqueId << " deleted." << std::endl;
            i = this->_entities.size();
        }
    }
}

void Game::initSprites()
{
    sf::Texture texture;
    sf::Sprite sprite;
    std::vector<std::string> _paths = {
        PLAYER1_TEXT,
        PLAYER2_TEXT,
        PLAYER3_TEXT,
        PLAYER4_TEXT,
        PLAYER_MISSILE,
        MOB_TEXT,
        MOB_TEXT,
        MOB_TEXT,
        MOB_MISSILE,
    };

    for (int i = 0; i < static_cast<int>(_paths.size()); i++)
    {
        this->_sprites.insert({i, std::make_pair(texture, sprite)});
        if (!this->_sprites[i].first.loadFromFile(_paths[i]))
            return;
        this->_sprites[i].second.setTexture(this->_sprites[i].first);
    }
}

void Game::renderEntities()
{
    int entityId;
    sf::Vector2f pos;

    for (size_t i = 0; i < this->_entities.size(); i++)
    {
        entityId = this->_entities[i]->getEntityId();
        pos = this->_entities[i]->getPosition();
        this->_sprites[entityId].second.setScale(3.0f, 3.0f);
        this->_sprites[entityId].second.setPosition(pos);
        this->_window->draw(this->_sprites[entityId].second);
    }
}

void Game::startLoop()
{
    sf::Event event;
    sf::Packet packet;
    bool isConnected = false;
    unsigned short port = 54000;

    while (this->_window->isOpen())
    {
        if (*(this->_isMenu))
            this->_menu->renderMenu();
        else
        {
            if (!isConnected) {
                this->_network->setServerInfo(this->_menu->getIp(), std::stoi(this->_menu->getPort()));
                packet << 0 << port << 4;
                this->_network->sendData(packet);
                isConnected = true;
            }
            this->_gameEngine->playSong();
            if (this->_network->receiveData())
                this->unpack();
            this->renderEntities();
            while (this->_window->pollEvent(event))
            {
                if (event.type == sf::Event::KeyPressed)
                {
                    this->_gameEngine->TreatmentEvent(event, this->_network);
                }
                if (event.type == sf::Event::Closed)
                {
                    this->_window->close();
                }
            }
        }
        this->_window->display();
        this->_window->clear();
    }
}