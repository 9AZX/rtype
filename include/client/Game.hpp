/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#define WIN_WIDTH 1920
#define WIN_HEIGHT 1080
#define FRAMERATE_LIMIT 60

#include <utility>
#include <memory>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "GameEngine.hpp"
#include "Network.hpp"
#include "Entity.hpp"

#define BACKGROUND "assets/background.png"
#define LOGO "assets/r_type_logo.png"
#define PLAYER1_TEXT "assets/r-typesheet42.gif"

class Game
{
public:
        Game();
        ~Game();

        typedef enum entities
        {
                PLAYER1,
                PLAYER2,
                PLAYER3,
                PLAYER4,
                PLAYER_MISSILE,
                MOB1,
                MOB2,
                MOB3,
                MOB4,
                ENTITIES_NUMBER
        } EEntities;

        void initNetwork();
        void startLoop();
        void unpack();
        void initSprites();
        void renderEntities();
        void renderMenu();
        void eventMenu();
        void displayMenuString();
        void displayConnect();
        void eventPressed();
        void eventInput();
        std::shared_ptr<GameEngine> getGameEngine() const;

protected:
        std::shared_ptr<GameEngine> _gameEngine;
        sf::RenderWindow _window;
        std::unique_ptr<Network> _network;
        std::vector<std::unique_ptr<Entity>> _entities;
        std::unordered_map<int, std::pair<sf::Texture, sf::Sprite>> _sprites;
        bool _isMenu = true;
        bool _isPlay = false;
        std::string _ip = "";
        std::vector<std::string> gameName;
        sf::Event event;
        sf::String _playerInput;
        sf::Font _font;

private:
        int position = 0;
};

#endif /* !GAME_HPP_ */