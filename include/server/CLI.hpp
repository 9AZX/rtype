/*
** EPITECH PROJECT, 2019
** CLI
** File description:
** Set class for the CLI.
** @Author: Cédric Hennequin
** @Date:   19-11-2019 16:15:28
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 20-11-2019 23:51:43
*/

#ifndef	_CLI_HPP_
#define	_CLI_HPP_

#include <functional>
#include <string>
#include <vector>
#include <map>
#include "Commands.hpp"

#define	CLI_HEADER	"r-type $> "
#define	CLI_STOP	"Server stop."
#define	CLI_HELP	"Type \"exit\" for stop."

using vecStr = std::vector<std::string>;
using funcPtr = std::function<bool(const std::string &str)>;

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

	private:
		int _argc = 0;
		std::vector<std::string> _args;
		std::vector<std::string> _argv;

	private:
		const std::map<std::string, funcPtr> _cmdList = {
			{"test", nullptr}
		};
	};
}

#endif	/* !_CLI_HPP_ */
