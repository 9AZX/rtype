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
        MISSILE,
        MOB1,
        MOB2,
        MOB3,
        MOB4,
        ENUM_SIZE
    } e_type;

    class IEntity
    {
    public:
        IEntity();
        virtual ~IEntity() = default;

        void move();

    protected:
        std::atomic<float> _posX;
        std::atomic<float> _posY;
        int _id;
        e_type _type;

    private:
    };
    // class Player;
    // class Mob;
    // class Missile;
}

#endif /* !IENTITY_HPP_ */