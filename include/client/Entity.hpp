/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <SFML/Graphics.hpp>

class Entity
{
public:
	Entity(std::string imgPath, sf::Vector2f pos);
	~Entity();

	void render(sf::RenderWindow &window);

protected:
	std::string _imgPath;
	sf::Vector2f _pos;
private:
};

#endif /* !ENTITY_HPP_ */
