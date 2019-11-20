/*
** EPITECH PROJECT, 2019
** Exception
** File description:
** Header for the Exception class.
** @Author: Cédric Hennequin
** @Date:   19-09-2019 15:36:25
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 19-11-2019 17:52:06
*/

#ifndef	_EXCEPTION_HPP_
#define	_EXCEPTION_HPP_

#include <string>
#include <exception>

class Exception : public std::exception
{
public:
	Exception() = default;
	Exception(const std::string &msg);
	~Exception() = default;

public:
	const char *what() const noexcept;

private:
	std::string _msg = "An internal error occured.";
};

#endif	/* !_EXCEPTION_HPP_ */
