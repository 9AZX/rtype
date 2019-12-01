/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu()
{
    this->_font.loadFromFile(FONT);
}

Menu::~Menu()
{
}

void Menu::renderEntitiesMenu(sf::RenderWindow &window)
{
    sf::Texture texture;
    sf::Sprite background;
    sf::Texture texture2;
    sf::Sprite logo;

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
    logo.setTexture(texture2);
    logo.setPosition(600, 200);
    window.draw(background);
    window.draw(logo);
}

void Menu::displayMenuString(sf::RenderWindow &window)
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
        window.draw(text);
        y += 70;
    }
}

void Menu::displayConnect(sf::RenderWindow &window, sf::Event &event, bool &isMenu)
{

    this->eventMenu(window, event, isMenu);
}

void Menu::eventInput(sf::RenderWindow &window, sf::Event &event)
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

void Menu::eventMenu(sf::RenderWindow &window, sf::Event &event, bool &isMenu)
{
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        this->eventPressed(window, event, isMenu);
        this->eventInput(window, event);
        if (isMenu == false)
            return;
    }
}

void Menu::eventPressed(sf::RenderWindow &window, sf::Event &event, bool &isMenu)
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
                    isMenu = false;
                    this->_isPlay = false;
                }
            }
            else if (position == 1)
                break;
            if (position == 2)
                window.close();
            break;
        case sf::Keyboard::Escape:
            window.close();
            break;
        default:
            break;
        }
    }
}

void Menu::renderMenu(sf::RenderWindow &window, sf::Event &event, bool &isMenu)
{
    sf::Text playerText(this->_ip, this->_font, 50);

    this->renderEntitiesMenu(window);
    playerText.setString(this->_playerInput);
    playerText.setPosition(800, 600);
    window.draw(playerText);
    if (!this->_isPlay)
        this->displayMenuString(window);
    else
    {
        this->displayConnect(window, event, isMenu);
    }
    this->eventMenu(window, event, isMenu);
}