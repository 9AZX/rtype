/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** sprites
*/

#include "Sprite.hpp"

Sprite::Sprite()
{
    std::cout << "Sprite created" << std::endl;
}

Sprite::~Sprite()
{
    std::cout << "Sprite destructed" << std::endl;
}

void Sprite::setPath(std::string path)
{
    this->_path = path;
}

sf::Sprite Sprite::getSprite()
{
    return this->_sprite;
}