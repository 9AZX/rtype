/*
** EPITECH PROJECT, 2019
** Commands
** File description:
** Commands for the CLI.
** @Author: Cédric Hennequin
** @Date:   20-11-2019 12:27:45
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 21-11-2019 16:02:25
*/

#include <iostream>
#include <cstdlib>
#include "CLI.hpp"

using namespace App;

bool Commands::dispatcher(const int type, const std::vector<std::string> &args)
{
	if (type == Commands::CMD_START) {
		return this->start(args);
	}
	else if (type == Commands::CMD_EXIT) {
		return this->exit();
	}
	return true;
}

bool Commands::start(const std::vector<std::string> &args)
{
	unsigned short port = 0;
	CLI *cli = dynamic_cast<CLI *>(this);

	if (args.size() != 1) {
		std::cerr << "Error: \"" << CMD_HELP_START << '\"' << std::endl;
		return true;
	}
	port = static_cast<unsigned short>(std::atoi(args.front().c_str()));
	cli->_server->run();
	return true;
}

bool Commands::exit() const noexcept
{
	return false;
}
