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
    this->gameName.push_back("Start");
    this->gameName.push_back("Option");
    this->gameName.push_back("Exit");
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

void Game::eventMenu()
{
    sf::Event event;

    while (this->_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            this->_window.close();
        }
        if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::W:
                position = position - 1;
                if (position == -1)
                    position = gameName.size();
                break;
            case sf::Keyboard::S:
                position = position + 1;
                if (position == gameName.size())
                    position = 0;
                break;
            case sf::Keyboard::Return:
                if (position == 0)
                {
                    this->_isPlay = true;
                    break;
                }
                else if (position == 1)
                    break;
                if (position == 2)
                    this->_window.close();
                break;
            case sf::Keyboard::Escape:
                this->_window.close();
                break;
            default:
                break;
            }
        }
    }
}

void Game::displayMenuString()
{
    sf::Font font;
    unsigned int y = 800;

    if (!font.loadFromFile("assets/font/arial.ttf"))
    {
        return;
    }
    for (unsigned int idx = 0; idx != gameName.size(); ++idx)
    {
        std::string name = gameName[idx].substr(0, gameName[idx].size());
        sf::Text text(name.c_str(), font, 50);
        if (idx == position)
        {
            text.setFillColor(sf::Color::Red);
        }
        text.setPosition(900, y);
        this->_window.draw(text);
        y += 70;
    }
}

void Game::displayConnect()
{
    sf::Text playerText;
    sf::Event Input;

    if (Input.type == sf::Event::TextEntered)
    {
        if (Input.text.unicode < 128)
        {
            playerInput += Input.text.unicode;
            playerText.setString(playerInput);
        }
    }
    // _window.draw(playerText);
    playerText.setPosition(100, 100);
    playerText.setCharacterSize(50);
    _window.draw(playerText);
}

void Game::renderMenu()
{
    sf::Texture texture;
    sf::Sprite background;
    //     sf::Sprite sprite2;
    //     sf::Vector2u test;

    if (!texture.loadFromFile(BACKGROUND))
    {
        return;
    }
    background.setTexture(texture);
    background.setPosition(0, 0);
    _window.draw(background);
    if (!this->_isPlay)
        this->displayMenuString();
    else
        this->displayConnect();
    this->eventMenu();
    //     // Afficher background
    //     // Gerer event menu
    //     // Afficher boutons
    //     // Recuperer inputs (ip, port)
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