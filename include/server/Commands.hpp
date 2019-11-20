/*
** EPITECH PROJECT, 2019
** Commands
** File description:
** Header for the Commands class.
** @Author: Cédric Hennequin
** @Date:   20-11-2019 12:21:19
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 20-11-2019 12:32:21
*/

#ifndef	_COMMANDS_HPP_
#define	_COMMANDS_HPP_

namespace App
{
	class Commands
	{
	public:
		Commands() = default;
		virtual ~Commands() = default;

	public:
		virtual void foo();
	};
}

#endif	/* !_COMMANDS_HPP_ */
