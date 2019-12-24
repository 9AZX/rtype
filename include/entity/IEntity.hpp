/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** IEntity
*/

#ifndef	_IENTITY_HPP_
#define	_IENTITY_HPP_

#include <atomic>

namespace Entity
{
	enum type
	{
		PLAYER1,
		PLAYER2,
		PLAYER3,
		PLAYER4,
		MISSILE_ALLY,
		MISSILE_MOB,
		MOB1,
		MOB2,
		MOB3,
		MOB4,
		ENUM_SIZE
	};

	class IEntity
	{
	public:
		IEntity() = default;
		virtual ~IEntity() = default;

	public:
		virtual const std::atomic<float> &getPosX() const noexcept = 0;
		virtual void setPosX(const float x) noexcept = 0;
		virtual const std::atomic<float> &getPosY() const noexcept = 0;
		virtual void setPosY(const float y) noexcept = 0;
		virtual const std::atomic<int> &getType() const noexcept = 0;
		virtual void setType(type type) noexcept = 0;
		virtual void move(const float x, const float y) noexcept = 0;
		virtual bool limits(const float x, const float y) const noexcept = 0;
	};
}

#endif	/* !_IENTITY_HPP_ */
