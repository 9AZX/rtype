/*
** EPITECH PROJECT, 2019
** Fork
** File description:
** Functions for the fork class.
** @Author: Cédric Hennequin
** @Date:   21-11-2019 12:58:43
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 21-11-2019 13:31:33
*/

#include "Fork.hpp"

bool Fork::fork()
{
	return true;
}

std::vector<pid_t> &Fork::getProcess() noexcept
{
	return this->_process_id;
}
