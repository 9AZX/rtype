/*
** EPITECH PROJECT, 2019
** Commands
** File description:
** Commands for the CLI.
** @Author: Cédric Hennequin
** @Date:   20-11-2019 12:27:45
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 18-12-2019 14:51:31
*/

#include <iostream>
#include <cstdlib>
#include "CLI.hpp"

using namespace App;

bool Commands::dispatcher(const int type, const std::vector<std::string> &args)
{
	bool value = true;

	switch (type)
	{
	case Commands::CMD_START:
		value = this->start(args);
		break;
	case Commands::CMD_STATE:
		value = this->state();
		break;
	case Commands::CMD_HELP:
		value = this->help();
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

	if (args.size() != 1)
	{
		std::cerr << "Error: \"" << CMD_HELP_START << '\"' << std::endl;
		return true;
	}
	port = static_cast<unsigned short>(std::atoi(args.front().c_str()));
	cli->_instance->setPort(port);
	cli->_instance->run();
#if defined(_WIN32) || defined(_WIN64)
	std::cout << SERVER_NEW_INSTANCE;
#else
	std::cout << SERVER_NEW_INSTANCE << cli->_instance->getLastPid();
#endif
	std::cout << ')' << std::endl;
	cli->_instance->setPort(SERVER_PORT_NULL);
	return true;
}

#if !defined(_WIN32) && !defined(_WIN64)
bool Commands::state() noexcept
{
	CLI *cli = dynamic_cast<CLI *>(this);
	std::vector<pid_t> process = cli->_instance->getProcess();

	for (const auto &pid : process)
	{
		std::cout << "Server instance: [" << pid << ']' << std::endl;
	}
	return true;
}
#else
bool Commands::state() noexcept
{
	CLI *cli = dynamic_cast<CLI *>(this);

	std::cout << "Number of instance: " << cli->_instance->countInstances();
	std::cout << std::endl;
	return true;
}
#endif

bool Commands::help() const noexcept
{
	std::cout << CMD_HELP__1 << std::endl;
	std::cout << CMD_HELP__2 << std::endl;
	std::cout << std::endl << CMD_HELP__3 << std::endl;
	std::cout << CMD_HELP__4 << std::endl;
	std::cout << CMD_HELP__5 << std::endl;
	std::cout << CMD_HELP__6 << std::endl;
	std::cout << CMD_HELP__7 << std::endl;
	return true;
}

bool Commands::exit() const noexcept
{
	return false;
}
