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
    this->_font.loadFromFile("assets/font/arial.ttf");
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

void Game::eventPressed()
{
    int size = gameName.size();
    if (event.type == sf::Event::KeyPressed)
    {
        switch (event.key.code)
        {
        case sf::Keyboard::Up:
            position = position - 1;
            if (position < 0)
                position = size - 1;
            break;
        case sf::Keyboard::Down:
            position = position + 1;
            if (position == size)
                position = 0;
            break;
        case sf::Keyboard::Return:
            if (position == 0)
            {
                this->_isPlay = true;
                if (this->_ip.empty() == false)
                {
                    this->_isMenu = false;
                    this->_isPlay = false;
                }
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

void Game::eventInput()
{
    if (this->_isPlay)
    {
        sf::Text playerText(this->_ip, this->_font, 50);

        if (event.type == sf::Event::TextEntered)
        {
            if (event.text.unicode < 128)
            {
                this->_playerInput += event.text.unicode;
                playerText.setString(this->_playerInput);
            }
            if (event.key.code == sf::Keyboard::Return)
                return;
        }
        this->_ip = this->_playerInput.toAnsiString();
    }
}

void Game::eventMenu()
{
    while (this->_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            this->_window.close();
        }
        this->eventPressed();
        this->eventInput();
        if (this->_isMenu == false)
            return;
    }
}

void Game::displayMenuString()
{
    int y = 800;
    int size = gameName.size();

    for (int idx = 0; idx != size; ++idx)
    {
        std::string name = gameName[idx].substr(0, gameName[idx].size());
        sf::Text text(name.c_str(), _font, 50);
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

    this->eventMenu();
    // _window.draw(playerText);
}

void Game::renderMenu()
{
    sf::Texture texture;
    sf::Sprite background;
    sf::Texture texture2;
    sf::Sprite background2;
    sf::Text playerText(this->_ip, this->_font, 50);

    if (!texture.loadFromFile(BACKGROUND))
    {
        return;
    }
    if (!texture2.loadFromFile(LOGO))
    {
        return;
    }
    background.setTexture(texture);
    background.setPosition(0, 0);
    background2.setTexture(texture2);
    background2.setPosition(600, 200);
    _window.draw(background);
    _window.draw(background2);

    playerText.setString(this->_playerInput);
    playerText.setPosition(800, 600);
    this->_window.draw(playerText);
    if (!this->_isPlay)
        this->displayMenuString();
    else
    {
        this->displayConnect();
    }
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