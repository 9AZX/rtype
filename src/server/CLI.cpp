/*
** EPITECH PROJECT, 2019
** CLI
** File description:
** Functions for the CLI class.
** @Author: Cédric Hennequin
** @Date:   19-11-2019 17:53:27
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 20-11-2019 16:36:20
*/

#include <iostream>
#include <sstream>
#include <regex>
#include "CLI.hpp"

using namespace App;

CLI::CLI(int argc, char **argv)
{
	this->_argc = argc;
	while (--argc) {
		this->_argv.push_back(argv[argc]);
	}
}

void CLI::launchCLI()
{
	do {
		std::cout << CLI_HEADER;
		std::getline(std::cin, this->_cmd, '\n');
		if (!this->callCommand()) {
			break;
		}
	} while (true);
	std::cout << std::endl << CLI_STOP << std::endl;
}

bool CLI::callCommand()
{
	if ((std::cin.eof() || std::cin.fail()) || this->_cmd == "exit") {
		return false;
	}
	this->_cmd = std::regex_replace(this->_cmd, std::regex("^\\s+"), "");
	this->_cmd = std::regex_replace(this->_cmd, std::regex("\\s+$"), "");
	std::cout << "input: \"" << this->_cmd << '\"' << std::endl;
	this->_cmd.clear();
	return true;
}
