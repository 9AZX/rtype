/*
** EPITECH PROJECT, 2019
** Commands
** File description:
** Header for the Commands class.
** @Author: Cédric Hennequin
** @Date:   20-11-2019 12:21:19
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 21-11-2019 16:02:14
*/

#ifndef	_COMMANDS_HPP_
#define	_COMMANDS_HPP_

#include <string>
#include <vector>

#define	CMD_HELP_START	"start [port]"

namespace App
{
	class Commands
	{
	public:
		enum {
			CMD_START,
			CMD_EXIT
		};

	public:
		Commands() = default;
		virtual ~Commands() = default;

	public:
		bool dispatcher(const int type, const std::vector<std::string> &args);

	private:
		bool start(const std::vector<std::string> &args);
		bool exit() const noexcept;
	};
}

#endif	/* !_COMMANDS_HPP_ */
