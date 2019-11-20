/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Entity
*/

#include "Entity.hpp"

Entity::Entity(std::string imgPath)
{
    this->_sprite = std::unique_ptr<Sprite>(new Sprite());
    this->_imgPath = imgPath;
}

Entity::~Entity()
{
}

void Entity::setSprite()
{
}

void Entity::renderSprite(sf::RenderWindow &window)
{
    sf::Texture texture;
    sf::Sprite sprite;

    if (!texture.loadFromFile("./r-typesheet42.png"))
        return;
    sprite.setTexture(texture);
    window.draw(sprite);
}