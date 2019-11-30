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
    this->_font.loadFromFile(FONT);
}

Game::~Game()
{
}

std::shared_ptr<GameEngine> Game::getGameEngine() const
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
    // create
    static int newUniqueId = 0; // mock entity creation
    if (newUniqueId == 1)
        return;
    std::cout << newUniqueId << std::endl;
    this->_entities.push_back(std::make_unique<Entity>(PLAYER1, newUniqueId, 100, 100));
    newUniqueId++;
}

void Game::initSprites()
{
    sf::Texture texture;
    sf::Sprite sprite;
    std::vector<std::string> _paths = {
        PLAYER1_TEXT,
        PLAYER1_TEXT,
        PLAYER1_TEXT,
        PLAYER1_TEXT,
        PLAYER1_TEXT,
        PLAYER1_TEXT,
        PLAYER1_TEXT,
        PLAYER1_TEXT,
        PLAYER1_TEXT,
    };

    for (int i = 0; i < _paths.size(); i++)
    {
        this->_sprites.insert({i, std::make_pair(texture, sprite)});
        if (!this->_sprites[i].first.loadFromFile(_paths[i]))
            return;
        this->_sprites[i].second.setTexture(this->_sprites[i].first);
    }
}

void Game::renderEntities()
{
    std::cout << this->_entities.size() << std::endl;
    for (size_t i = 0; i < this->_entities.size(); i++)
    {
        this->_window.draw(this->_sprites[this->_entities[i]->getEntityId()].second);
    }
}

void Game::eventPressed()
{
    int size = this->_strMenu.size();
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
            if (event.text.unicode == '\b')
            {
                _playerInput.erase(_playerInput.getSize() - 1);
                this->_ip = this->_playerInput.toAnsiString();
                return;
            }
            if (event.text.unicode < 128)
            {
                this->_playerInput += event.text.unicode;
                playerText.setString(this->_playerInput);
            }
            if (event.key.code == sf::Keyboard::BackSpace)
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
    int size = this->_strMenu.size();

    for (int idx = 0; idx != size; ++idx)
    {
        std::string name = this->_strMenu[idx].substr(0, this->_strMenu[idx].size());
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
}

void Game::playSong()
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

void Game::renderEntitiesMenu()
{
    sf::Texture texture;
    sf::Sprite background;
    sf::Texture texture2;
    sf::Sprite background2;

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
}

void Game::renderMenu()
{

    sf::Text playerText(this->_ip, this->_font, 50);

    this->renderEntitiesMenu();
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
        this->playSong();
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
    }
}