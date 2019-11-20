/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <stdio.h>
#include <iostream>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Sprite.hpp"

class Entity
{
public:
	Entity(std::string imgPath);
	~Entity();

	void setSprite();
	void renderSprite(sf::RenderWindow &window);

protected:
	std::unique_ptr<Sprite> _sprite;
	std::string _imgPath;

private:
};

#endif /* !ENTITY_HPP_ */
