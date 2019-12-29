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
    Menu(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<bool> isMenu);
    ~Menu();

    void initAssets();
    void renderMenu();
    void eventMenu();
    void displayMenuString();
    void eventPressed();
    void eventInput();
    void renderEntitiesMenu();
    std::string getIp();
    std::string getPort();
    void detachIpPort();
    void setIsPlay();

protected:
    sf::Texture _text_background;
    sf::Sprite _background;
    sf::Texture _text_logo;
    sf::Sprite _logo;

    std::shared_ptr<sf::RenderWindow> _window;
    sf::Event _event;
    std::shared_ptr<bool> _isMenu;
    bool _isPlay = false;
    std::string _ip = "";
    std::string _port = "";
    std::vector<std::string> gameName;
    sf::String _playerInput;
    sf::Font _font;
    std::vector<std::string> _strMenu{"Start", "Exit"};
    int position = 0;

private:
};

#endif /* !Menu_HPP_ */
