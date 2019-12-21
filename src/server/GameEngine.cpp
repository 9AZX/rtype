/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GameEngine
*/

#include "GameEngine.hpp"

using namespace Entity;

GameEngine::GameEngine()
{
}

bool GameEngine::checkPosition(GameEntity a, GameEntity b) const
{
    if (a.getPosX() == b.getPosY()
        && a.getPosY() == b.getPosY()) {
            return true;
    } else return false;
}

bool GameEngine::checkEntityType(GameEntity a, GameEntity b) const
{
    if (a.getType() != b.getType()) {
        return true;
    } else return false;
}