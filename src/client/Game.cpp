/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Game
*/

#include "Game.hpp"

Game::Game() : _window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "R-Type")
{
    this->_gameEngine = std::make_shared<GameEngine>();
    this->_window.setFramerateLimit(FRAMERATE_LIMIT);
}

Game::~Game()
{
}

void Game::initNetwork()
{
    this->_network = std::make_unique<Network>();
    this->_network->bindSocket();
}

void Game::unpack()
{
    this->_entities
        .push_back(new Entity("assets/r-typesheet42.gif", sf::Vector2f(100, 100)));
}

void Game::renderEntities()
{
    for (size_t i = 0; i < this->_entities.size(); i++)
    {
        this->_entities[i]->render(this->_window);
    }
}

void Game::renderMenu()
{
    // Afficher background
    // Gerer event menu
    // Afficher boutons
    // Recuperer inputs (ip, port)
}

void Game::startLoop()
{
    std::cout << "Start window" << std::endl;
    sf::Event event;

    while (this->_window.isOpen())
    {
        if (this->_isMenu)
            this->renderMenu();
        // this->_network->receiveData();
        if (!this->_isMenu)
        {
            this->unpack();
            this->renderEntities();
            while (this->_window.pollEvent(event))
            {
                if (event.type == sf::Event::KeyPressed)
                {
                    this->_gameEngine->TreatmentEvent(event);
                }
                if (event.type == sf::Event::Closed)
                {
                    this->_window.close();
                }
                // process events...
            }
        }
        // send events to server...
        this->_window.display();
        this->_window.clear();
        this->_entities.clear();
    }
}