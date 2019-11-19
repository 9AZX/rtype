/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Entity
*/

#include "Entity.hpp"

Entity::Entity(std::string imgPath)
{
    this->_imgPath = imgPath;
    this->_sprite = std::make_unique<Sprite>(new Sprite());
}

Entity::~Entity()
{
}

void Entity::setSprite()
{
}

void Entity::renderSprite()
{
    sf::RenderTexture texture;

    if (!texture.create(500, 500))
        return;
    texture.clear();
    texture.draw(this->_sprite.getSprite());
    texture.display();
}