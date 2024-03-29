/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Entity
*/

#include "Entity.hpp"

Entity::Entity(int entityId, int uniqueId, int posX, int posY)
    : _entityId(entityId), _uniqueId(uniqueId)
{
    this->_pos.x = posX;
    this->_pos.y = posY;
}

Entity::~Entity()
{
}

int Entity::getEntityId() const
{
    return this->_entityId;
}

int Entity::getId() const
{
    return this->_uniqueId;
}

void Entity::updatePosition(int &x, int &y)
{
    this->_pos.x = x;
    this->_pos.y = y;
}

sf::Vector2f Entity::getPosition() const
{
    return this->_pos;
}