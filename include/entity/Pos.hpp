/*
** EPITECH PROJECT, 2019
** Pos
** File description:
** description
** @Author: Cédric Hennequin
** @Date:   28-11-2019 17:35:36
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 01-12-2019 14:02:05
*/

#ifndef	_POS_HPP_
#define _POS_HPP_

#include <atomic>

namespace Entity
{
	class Pos
	{
	public:
		Pos();
		Pos(const float x, const float y);
		virtual ~Pos() = default;

	protected:
		std::atomic<float> _x;
		std::atomic<float> _y;
	};
}

#endif /* !_POS_HPP_ */
