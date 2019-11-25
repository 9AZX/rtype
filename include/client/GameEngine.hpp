/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GameEngine
*/

#ifndef GAMEENGINE_HPP_
#define GAMEENGINE_HPP_

#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>


class GameEngine {
	public:
		GameEngine();
		~GameEngine();
		void TreatmentEvent(sf::Event event);

	protected:
	private:
};

#endif /* !GAMEENGINE_HPP_ */
