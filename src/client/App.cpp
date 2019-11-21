/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** App
*/

#include "App.hpp"

App::App()
{
}

App::~App()
{
}

void App::run()
{
    std::cout << "Client started." << std::endl;
    this->_game = std::make_unique<Game>();
    this->_game->initNetwork();
    this->_game->startLoop();
}