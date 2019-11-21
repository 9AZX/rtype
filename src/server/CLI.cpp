/*
** EPITECH PROJECT, 2019
** CLI
** File description:
** Functions for the CLI class.
** @Author: Cédric Hennequin
** @Date:   19-11-2019 17:53:27
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 21-11-2019 12:32:32
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
	std::string input = "";

	do {
		std::cout << CLI_HEADER;
		std::getline(std::cin, input, '\n');
		if (!input.empty()) {
			input = std::regex_replace(input, std::regex("^\\s+"), "");
			input = std::regex_replace(input, std::regex("\\s+$"), "");
		}
		if (!this->callCommand(input)) {
			break;
		}
		input.clear();
	} while (true);
	std::cout << std::endl << CLI_STOP << std::endl;
}

std::vector<std::string> CLI::explode(const std::string &str, const char delim)
{
	std::string token = "";
	std::istringstream iss(str);
	std::vector<std::string> result;

	while (std::getline(iss, token, delim)) {
		result.push_back(std::move(token));
	}
	return result;
}

bool CLI::callCommand(const std::string &str)
{
	if ((std::cin.eof() || std::cin.fail()) || str == "exit") {
		return false;
	}
	this->_args = this->explode(str, ' ');
	if (this->_args.empty()) {
		return true;
	}
	argsIterator it = this->_cmdList.find(this->_args.front());
	std::cout << "cmd: \"" << this->_args.front() << '\"' << std::endl;
	if (it != this->_cmdList.end()) {
		this->_args.erase(this->_args.begin());
		this->dispatcher(it->second, this->_args);
	}
	return true;
}
