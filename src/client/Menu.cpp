/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<bool> isMenu)
    : _window(window), _isMenu(isMenu)
{
    this->initAssets();
}

Menu::~Menu()
{
}

void Menu::initAssets()
{
    if (!this->_font.loadFromFile(FONT)) return;
    if (!this->_text_background.loadFromFile(BACKGROUND))
        return;
    if (!this->_text_logo.loadFromFile(LOGO))
        return;
    this->_background.setTexture(this->_text_background);
    this->_logo.setTexture(this->_text_logo);
}

void Menu::renderEntitiesMenu()
{
    this->_background.setPosition(0, 0);
    this->_logo.setPosition(600, 200);
    this->_window->draw(this->_background);
    this->_window->draw(this->_logo);
}

void Menu::displayMenuString()
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
        this->_window->draw(text);
        y += 70;
    }
}

void Menu::eventInput()
{
    if (this->_isPlay)
    {
        sf::Text playerText(this->_ip, this->_font, 50);

        if (this->_event.type == sf::Event::TextEntered)
        {
            if (this->_event.text.unicode == '\b')
            {
                _playerInput.erase(_playerInput.getSize() - 1);
                this->_ip = this->_playerInput.toAnsiString();
                return;
            }
            if (this->_event.text.unicode < 128)
            {
                this->_playerInput += this->_event.text.unicode;
                playerText.setString(this->_playerInput);
            }
            if (this->_event.key.code == sf::Keyboard::BackSpace)
                return;
        }
        this->_ip = this->_playerInput.toAnsiString();
    }
}

void Menu::eventMenu()
{
    while (this->_window->pollEvent(this->_event))
    {
        if (this->_event.type == sf::Event::Closed)
        {
            this->_window->close();
        }
        this->eventPressed();
        this->eventInput();
        if (!this->_isMenu)
            return;
    }
}

void Menu::eventPressed()
{
    int size = this->_strMenu.size();

    if (this->_event.type == sf::Event::KeyPressed)
    {
        switch (this->_event.key.code)
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
                this->_isPlay = true;
            if (this->_ip.empty() == false)
            {
                *(this->_isMenu) = false;
                this->_isPlay = false;
            }
            else if (position == 1)
                break;
            if (position == 2)
                this->_window->close();
            break;
        case sf::Keyboard::Escape:
            this->_window->close();
            break;
        default:
            break;
        }
    }
}

void Menu::renderMenu()
{
    sf::Text playerText(this->_ip, this->_font, 50);

    this->renderEntitiesMenu();
    playerText.setString(this->_playerInput);
    playerText.setPosition(800, 600);
    this->_window->draw(playerText);
    if (!this->_isPlay)
        this->displayMenuString();
    else
    {
        this->eventMenu();
    }
    this->eventMenu();
}