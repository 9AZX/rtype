/*
** EPITECH PROJECT, 2019
** Commands
** File description:
** Commands for the CLI.
** @Author: Cédric Hennequin
** @Date:   20-11-2019 12:27:45
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 21-11-2019 16:43:52
*/

#include <iostream>
#include <cstdlib>
#include "CLI.hpp"

using namespace App;

bool Commands::dispatcher(const int type, const std::vector<std::string> &args)
{
	bool value = true;

	switch (type) {
		case Commands::CMD_START:
			value = this->start(args);
			break;
		case Commands::CMD_STATE:
			value = this->state();
			break;
		case Commands::CMD_EXIT:
			value = this->exit();
			break;
		default:
			break;
	}
	return value;
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

bool Commands::state() noexcept
{
	CLI *cli = dynamic_cast<CLI *>(this);
	std::vector<pid_t> process = cli->_server->getProcess();

	for (const auto &pid : process) {
		std::cout << "Server instance: [" << pid << ']' << std::endl;
	}
	return true;
}

bool Commands::exit() const noexcept
{
	return false;
}
