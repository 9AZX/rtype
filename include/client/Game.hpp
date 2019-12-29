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
#include "GameEngineClient.hpp"
#include "Network.hpp"
#include "Entity.hpp"
#include "Menu.hpp"

#define PLAYER1_TEXT "assets/r-typesheet42.gif"
#define PLAYER2_TEXT "assets/r-typesheet42_2.gif"
#define PLAYER3_TEXT "assets/r-typesheet42_3.gif"
#define PLAYER4_TEXT "assets/r-typesheet42_4.gif"
#define MOB_TEXT "assets/r-typesheet23a.gif"
#define PLAYER_MISSILE "assets/r-typesheet1a_shoot_player.gif"
#define MOB_MISSILE "assets/r-typesheet37a.gif"

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
        MISSILE,
        MOB1,
        MOB2,
        MOB3,
        MOB4,
        ENTITIES_NUMBER
    } EEntities;

    void initNetwork();
    void startLoop();
    void unpack();

    void renderEntities();
    void createEntity(int &uniqueId, Game::entities, float &posX, float &posY);
    bool updateEntity(int &id, float &posX, float &posY);
    void deleteEntity(int &id);

    void initSprites();
    std::shared_ptr<GameEngineClient> getGameEngine() const;

protected:
    std::shared_ptr<GameEngineClient> _gameEngine;
    std::shared_ptr<sf::RenderWindow> _window;
    std::unique_ptr<Network> _network;
    std::unique_ptr<Menu> _menu;
    std::vector<std::unique_ptr<Entity>> _entities;
    std::unordered_map<int, std::pair<sf::Texture, sf::Sprite>> _sprites;
    std::shared_ptr<bool> _isMenu = std::make_shared<bool>(true);
    sf::Event event;

private:
};

#endif /* !GAME_HPP_ */