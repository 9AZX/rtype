/*
** EPITECH PROJECT, 2019
** Fork
** File description:
** Header for the Fork class (wrapper of fork syscall).
** @Author: Cédric Hennequin
** @Date:   21-11-2019 12:42:50
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 21-11-2019 13:31:39
*/

#ifndef	_FORK_HPP_
#define	_FORK_HPP_

#include <vector>

class Fork
{
public:
	Fork() = default;
	virtual ~Fork() = default;

public:
	bool fork();
	std::vector<pid_t> &getProcess() noexcept;

private:
	std::vector<pid_t> _process_id;
};

#endif	/* !_FORK_HPP_ */
