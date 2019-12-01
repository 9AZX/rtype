/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

#define BACKGROUND "assets/background.png"
#define LOGO "assets/r_type_logo.png"
#define FONT "assets/font/arial.ttf"

class Menu
{
public:
    Menu();
    ~Menu();
    void renderMenu(sf::RenderWindow &window, sf::Event &event, bool &isMenu);
    void eventMenu(sf::RenderWindow &window, sf::Event &event, bool &isMenu);
    void displayMenuString(sf::RenderWindow &window);
    void displayConnect(sf::RenderWindow &window, sf::Event &event, bool &isMenu);
    void eventPressed(sf::RenderWindow &window, sf::Event &event, bool &isMenu);
    void eventInput(sf::RenderWindow &window, sf::Event &event);
    void renderEntitiesMenu(sf::RenderWindow &window);

protected:
    bool _isPlay = false;
    std::string _ip = "";
    std::vector<std::string> gameName;
    sf::String _playerInput;
    sf::Font _font;
    std::vector<std::string> _strMenu{"Start", "Exit"};
    int position = 0;

private:
};

#endif /* !Menu_HPP_ */
