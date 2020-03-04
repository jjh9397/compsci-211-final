#pragma once

#include <iostream>
#include <ge211.hxx>

class Player
{
public:
    explicit Player(ge211::Position, ge211::Position, ge211::Dimensions);

    ge211::Position hitbox_next();
    ge211::Position hurtbox_next();
    void hits_side();
    void collides(Player);

private:
    ge211::Rectangle hitbox;
    ge211::Rectangle hurtbox;
    bool blocking;
    bool active;
    ge211::Dimensions hitbox_velocity;
    ge211::Dimensions hurtbox_velocity;
    int health;
    ge211::Dimensions facing;

    friend struct Test_access;
};