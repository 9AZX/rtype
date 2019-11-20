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
#include "Entity.hpp"

#include <typeinfo>

void testClient(sf::RenderWindow *window)
{
	auto entity = std::unique_ptr<Entity>(new Entity("../../assets/r-typesheet42.gif"));
	// std::unique_ptr<Entity> entity;

	std::cout << "Test session..." << std::endl;
	// auto entity = new Entity("../../assets/r-typesheet42.gif");
	entity->renderSprite(window);
}

int main()
{
	sf::Event event;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "My window");

	while (window.isOpen()) {
		testClient(&window);
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}
	return 0;
}
