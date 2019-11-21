/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Entity
*/

#include "Entity.hpp"

Entity::Entity(std::string imgPath, sf::Vector2f pos)
: _imgPath(imgPath), _pos(pos)
{
}

Entity::~Entity()
{
}

void Entity::render(sf::RenderWindow &window)
{
    sf::Texture texture;
    sf::Sprite sprite;

    if (!texture.loadFromFile(this->_imgPath))
        return;
    sprite.setTexture(texture);
    sprite.setPosition(this->_pos.x, this->_pos.y);
    window.draw(sprite);
}