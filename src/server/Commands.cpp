/*
** EPITECH PROJECT, 2019
** Commands
** File description:
** Commands for the CLI.
** @Author: Cédric Hennequin
** @Date:   20-11-2019 12:27:45
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 21-11-2019 13:27:54
*/

#include <iostream>
#include "CLI.hpp"

using namespace App;

bool Commands::dispatcher(const int type, const std::vector<std::string> &args)
{
	if (type == Commands::CMD_START) {
		return this->start(args);
	}
	return true;
}

bool Commands::start(const std::vector<std::string> &args)
{
	//CLI *cli = dynamic_cast<CLI *>(this);

	for (const auto &v : args) {
		std::cout << "value: \"" << v << '\"' << std::endl;
	}
	return true;
}
