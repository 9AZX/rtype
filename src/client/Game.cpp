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
    float posX;
    float posY;
    int id;
    
    // create entity
    this->_network->_packet >> type;
    this->_network->_packet >> size;
    //create ou update mobs
    for (int i = 0; i < size; i++) {
        this->_network->_packet >> typeEntity;
        this->_network->_packet >> id;
        this->_network->_packet >> posX;
        this->_network->_packet >> posY;
        if (!updateEntity(id, posX, posY)) {
            createEntity(id, Game::entities::MOB1, posX, posY);
        }
        std::cout << "Id: " << id <<
        " posX: " << posX << " posY: " << posY << std::endl;
    }

    // delete entity
}

void Game::createEntity(int &uniqueId, Game::entities type, float &posX, float &posY)
{
    this->_entities.push_back(std::make_unique<Entity>(type, uniqueId, posX, posY));
    std::cout << "Entity " << uniqueId << " created." << std::endl;
}

bool Game::updateEntity(int &uniqueId, float &posX, float &posY)
{
    for (size_t i = 0; i < this->_entities.size(); i++)
    {
        if (this->_entities[i]->getId() == uniqueId)
        {
            this->_entities[static_cast<int>(i)]->updatePosition(posX, posY);
            std::cout << "Entity " << uniqueId << " updated." << std::endl;
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
            i = this->_entities.size(); // stop unecessary loop
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
        PLAYER5_TEXT,
        PLAYER1_TEXT,
        PLAYER1_TEXT,
        PLAYER1_TEXT,
        PLAYER1_TEXT,
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

    std::cout << "Number of entities: " << this->_entities.size() << std::endl;
    for (size_t i = 0; i < this->_entities.size(); i++)
    {
        entityId = this->_entities[i]->getEntityId();
        pos = this->_entities[i]->getPosition();
        this->_sprites[entityId].second.setPosition(pos);
        this->_window->draw(this->_sprites[entityId].second);
    }
}

void Game::startLoop()
{
    std::cout << "Start window" << std::endl;
    sf::Event event;
    sf::Packet packet;
    unsigned short port = 54000;

    packet << 0 << "127.0.0.1" << port << 3;
    this->_network->sendData(packet);
    while (this->_window->isOpen())
    {
        if (*(this->_isMenu))
            this->_menu->renderMenu();
        else
        {
            this->_gameEngine->playSong();
            if (this->_network->receiveData())
                this->unpack();
            this->renderEntities();
            while (this->_window->pollEvent(event))
            {
                if (event.type == sf::Event::KeyPressed)
                {
                    this->_gameEngine->TreatmentEvent(event);
                }
                if (event.type == sf::Event::Closed)
                {
                    this->_window->close();
                }
                // process events...
            }
        }
        // send events to server...
        this->_window->display();
        this->_window->clear();
    }
}