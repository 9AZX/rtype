/*
** EPITECH PROJECT, 2019
** main
** File description:
** Main file for launch the client.
** @Author: Cédric Hennequin
** @Date:   18-11-2019 15:54:15
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 19-11-2019 10:50:58
*/

#include <SFML/Window.hpp>

int main()
{
	sf::Event event;
	sf::Window window(sf::VideoMode(800, 600), "My window");

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}
	return 0;
}
