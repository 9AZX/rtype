/*
** EPITECH PROJECT, 2019
** CLI
** File description:
** Set class for the CLI.
** @Author: Cédric Hennequin
** @Date:   19-11-2019 16:15:28
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 22-12-2019 17:24:30
*/

#ifndef	_CLI_HPP_
#define	_CLI_HPP_

#include <map>
#include <memory>
#include <functional>
#include "Commands.hpp"
#include "Instance.hpp"

#define	CLI_HEADER	"r-type $> "
#define	CLI_STOP	"Server stop."
#define	CLI_HELP	"Welcome! You can type \"exit\" for stop."
#define	CLI_UNKNOWN	"Unknown command (\""

using vecStr = std::vector<std::string>;
using argsIterator = std::map<std::string, int>::const_iterator;

namespace App
{
	class CLI: public Commands
	{
	public:
		CLI() = default;
		CLI(int argc, char **argv);
		~CLI() = default;

	public:
		void launchCLI();
		static vecStr explode(const std::string &str, const char delim);

	private:
		bool callCommand(const std::string &str);

	public:
		std::unique_ptr<Instance> _instance = nullptr;

	private:
		int _argc = 0;
		std::vector<std::string> _args;
		std::vector<std::string> _argv;
		const std::map<std::string, int> _cmdList = {
			{"start", CLI::CMD_START},
			{"state", CLI::CMD_STATE},
			{"help", CLI::CMD_HELP},
			{"exit", CLI::CMD_EXIT}
		};
	};
}

#endif	/* !_CLI_HPP_ */
