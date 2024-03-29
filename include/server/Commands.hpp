/*
** EPITECH PROJECT, 2019
** Commands
** File description:
** Header for the Commands class.
** @Author: Cédric Hennequin
** @Date:   20-11-2019 12:21:19
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 21-11-2019 18:02:13
*/

#ifndef	_COMMANDS_HPP_
#define	_COMMANDS_HPP_

#include <string>
#include <vector>

#define	CMD_HELP__1	"SYNOPSIS"
#define	CMD_HELP__2	"\tR-Type Server - CLI"
#define	CMD_HELP__3	"DESCRIPTION"
#define	CMD_HELP__4	"\t* start [port]\tstart a new server instance"
#define	CMD_HELP__5	"\t* state\tsee all instances created"
#define	CMD_HELP__6	"\t* exit\t\tstop all instances and exit."
#define	CMD_HELP__7	"\t* help\t\tdisplay this help."
#define	CMD_HELP_WIDTH	4
#define	CMD_HELP_START	"start [port]"

namespace App
{
	class Commands
	{
	public:
		enum {
			CMD_START,
			CMD_STATE,
			CMD_HELP,
			CMD_EXIT
		};

	public:
		Commands() = default;
		virtual ~Commands() = default;

	public:
		bool dispatcher(const int type, const std::vector<std::string> &args);

	private:
		bool start(const std::vector<std::string> &args);
		bool state() noexcept;
		bool help() const noexcept;
		bool exit() const noexcept;
	};
}

#endif	/* !_COMMANDS_HPP_ */
