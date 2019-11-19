/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** sprites
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include <stdio.h>
#include <iostream>
#include <memory>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Sprite
{
    public:
        Sprite();
        ~Sprite();

        void setPath(std::string path);
        sf::Sprite getSprite();
    protected:
        sf::Sprite _sprite;
        sf::Vector2f _pos;
        std::string _path;
};

#endif /* !SPRITE_HPP_ */
