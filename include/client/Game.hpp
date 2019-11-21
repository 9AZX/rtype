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

#include <memory>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "GameEngine.hpp"
#include "Network.hpp"
#include "Entity.hpp"

class Game {
	public:
		Game();
		~Game();

        void initNetwork();
        void startLoop();
        void unpack();
        void renderEntities();
        std::shared_ptr<GameEngine> getGameEngine() const {return this->_gameEngine;}
	protected:
        std::shared_ptr<GameEngine> _gameEngine;
        sf::RenderWindow _window;
        std::unique_ptr<Network> _network;
        std::vector<Entity *> _entities;
	private:
};

#endif /* !GAME_HPP_ */
