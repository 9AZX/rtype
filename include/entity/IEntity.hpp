/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** IEntity
*/

#ifndef IENTITY_HPP_
#define IENTITY_HPP_

#include <atomic>

namespace Entity
{
typedef enum type
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
} e_type;

class IEntity
{
    public:
        IEntity() = default;
        virtual ~IEntity() = default;

        virtual void move(float, float) = 0;

        virtual float getPosX() const = 0;
        virtual float getPosY() const = 0;
        virtual e_type getType() const = 0;

    protected:
        float _posX;
        float _posY;
        int _id;
        e_type _type;

    private:
};
}

#endif /* !IENTITY_HPP_ */