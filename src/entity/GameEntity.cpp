/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GameEntity
*/

#include <cstdlib>
#include "GameEntity.hpp"
#include <chrono>

GameEntity::GameEntity()
{
	atomic_init(&this->_posX, 0);
	atomic_init(&this->_posY, 0);
	this->_entityId = std::rand();
}

const std::atomic<int> &GameEntity::getId() const noexcept
{
	return this->_entityId;
}

const std::atomic<int> &GameEntity::getPosX() const noexcept
{
	return this->_posX;
}

void GameEntity::setPosX(const int x) noexcept
{
	this->_posX = x;
}

const std::atomic<int> &GameEntity::getPosY() const noexcept
{
	return this->_posY;
}

void GameEntity::setPosY(const int y) noexcept
{
	this->_posY = y;
}

const std::atomic<int> &GameEntity::getType() const noexcept
{
	return this->_type;
}

void GameEntity::setType(type type) noexcept
{
	this->_type = type;
}

bool GameEntity::getRemoveEntity() const noexcept
{
	return this->_removeEntity;
}

void GameEntity::move(const int x, const int y) noexcept
{
	if (this->limits(this->_posX + x, this->_posY + y)) {
		return;
	}
	this->_posX = this->_posX + x;
	this->_posY = this->_posY + y;
}

bool GameEntity::limits(const int x, const int y) const noexcept
{
	return (x > 1920 - ENTITY_WIDTH || x < 0) || (y > 1080 - ENTITY_HEIGHT || y < 0);
}

void GameEntity::setRemoveEntity() noexcept
{
	this->_removeEntity = true;
}

void GameEntity::ia() noexcept
{
	this->_loopCount++;
	if (this->_loopCount % 2 == 0) {
		if (this->_direction == -1) {
			this->_direction = std::rand() % 2;
			this->_nbMovements = std::rand() % 10 + 3;
		}
		if (this->_moveCount == this->_nbMovements) {
			this->_direction = -1;
		}
		this->_direction == 0 ? this->move(0, 10) : this->move(0, -10);
		this->_moveCount++;
	}
	// if (this->_loopCount % 10 == 0) {
	// 	this->_isShooting = std::rand() % 2 == 0 ? true : false;
	// }
}
