/*
** EPITECH PROJECT, 2019
** Server
** File description:
** Functions for the server class.
** @Author: Cédric Hennequin
** @Date:   21-11-2019 23:45:32
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 28-11-2019 16:18:04
*/

#include "Server.hpp"

Server::Server(unsigned short port) : NetworkUDP(port)
{
}
