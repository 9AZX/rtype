/*
** EPITECH PROJECT, 2019
** CLI
** File description:
** Set class for the CLI.
** @Author: Cédric Hennequin
** @Date:   19-11-2019 16:15:28
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 20-11-2019 15:45:06
*/

#ifndef	_CLI_HPP_
#define	_CLI_HPP_

#include <vector>
#include "Commands.hpp"

#define	CLI_HEADER	"r-type $> "
#define	CLI_STOP	"Server stop."
#define	CLI_HELP	"Type \"exit\" for stop."

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

	private:
		bool callCommand();

	private:
		int _argc = 0;
		std::string _cmd = "";
		std::vector<std::string> _argv;
	};
}

#endif	/* !_CLI_HPP_ */
