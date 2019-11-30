/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Entity
*/

#include "Entity.hpp"

Entity::Entity(int entityId, int uniqueId, float posX, float posY)
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

void Entity::updatePosition(float x, float y)
{
    this->_pos.x = x;
    this->_pos.y = y;
}

sf::Vector2f Entity::getPosition() const
{
    return this->_pos;
}