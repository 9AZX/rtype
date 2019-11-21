/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** App
*/

#ifndef APP_HPP_
#define APP_HPP_

#include <memory>
#include <iostream>
#include "Game.hpp"

class App {
	public:
		App();
		~App();

		void run();
	protected:
		std::unique_ptr<Game> _game;
	private:
};

#endif /* !APP_HPP_ */
