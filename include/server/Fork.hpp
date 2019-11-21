/*
** EPITECH PROJECT, 2019
** Fork
** File description:
** Header for the Fork class (wrapper of fork syscall).
** @Author: Cédric Hennequin
** @Date:   21-11-2019 12:42:50
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 21-11-2019 17:29:18
*/

#ifndef	_FORK_HPP_
#define	_FORK_HPP_

#include <vector>

#define	FORK_DEBUG	true

class Fork
{
public:
	enum {
		FORK_PARENT,
		FORK_CHILD
	};

public:
	Fork() = default;
	virtual ~Fork() = default;

public:
	void fork();
	void kill() const;
	constexpr void killDebug(const bool state, const pid_t pid) const noexcept;
	bool isParent() const noexcept;
	std::vector<pid_t> &getProcess() noexcept;
	pid_t getLastPid() const noexcept;

private:
	pid_t _last = 0;
	int _fork = FORK_PARENT;
	std::vector<pid_t> _process_id;
};

#endif	/* !_FORK_HPP_ */
