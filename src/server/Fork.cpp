/*
** EPITECH PROJECT, 2019
** Fork
** File description:
** Functions for the fork class.
** @Author: Cédric Hennequin
** @Date:   21-11-2019 12:58:43
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 21-11-2019 17:29:22
*/

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <iostream>
#include <cerrno>
#include "Fork.hpp"
#include "Exception.hpp"

void Fork::fork()
{
	pid_t pid = ::fork();

	if (pid == -1) {
		throw Exception(std::strerror(errno));
	}
	else if (pid == 0) {
		this->_fork = Fork::FORK_CHILD;
		this->_process_id.clear();
		return;
	}
	this->_process_id.push_back(pid);
	this->_last = pid;
}

void Fork::kill() const
{
	if (this->_process_id.empty()) {
		return;
	}
	for (const auto &pid : this->_process_id) {
		this->killDebug(FORK_DEBUG, pid);
		if (::kill(pid, SIGTERM) == -1) {
			throw Exception(std::strerror(errno));
		}
	}
}

constexpr void Fork::killDebug(const bool state, const pid_t pid) const noexcept
{
	if (state) {
		std::cout << "Close server instance [pid: " << pid << ']' << std::endl;
	}
}

bool Fork::isParent() const noexcept
{
	return this->_fork == Fork::FORK_PARENT ? true : false;
}

std::vector<pid_t> &Fork::getProcess() noexcept
{
	return this->_process_id;
}

pid_t Fork::getLastPid() const noexcept
{
	return this->_last;
}
