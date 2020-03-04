#pragma once

#include <iostream>
#include <ge211.hxx>

class Player
{
    public:
    explicit Player(ge211::Position, ge211::Position);

    void hitbox_next();
    void hurtbox_next();
    void hits_side();
    void collides(Player);

    private:
    ge211::Rectangle hitbox;
    ge211::Rectangle hurtbox;
    bool blocking;
    bool active;
    ge211::Position hitbox_velocity;
    ge211::Position hurtbox_velocity;
    int health;

    friend struct Test_access;
};