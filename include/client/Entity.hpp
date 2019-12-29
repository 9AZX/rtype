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
	Entity(int entityId, int uniqueId, int posX, int posY);
	~Entity();

	int getEntityId() const;
	int getId() const;
	void updatePosition(int &x, int &y);
	sf::Vector2f getPosition() const;

protected:
	sf::Vector2f _pos;
	int _entityId;
	int _uniqueId;

private:
};

#endif /* !ENTITY_HPP_ */
