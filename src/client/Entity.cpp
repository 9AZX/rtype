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
    sf::Vector2u test;

    if (!texture.loadFromFile(this->_imgPath))
        return;
    test = texture.getSize();
    sf::IntRect r2(0, 0, test.x/5, test.y/5);
    sprite.setTexture(texture);
    sprite.setTextureRect(r2);
    sprite.setScale(2, 2);
    sprite.setPosition(this->_pos.x, this->_pos.y);

    window.draw(sprite);
}