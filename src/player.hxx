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
    bool recovered();

private:
    ge211::Rectangle hitbox;
    ge211::Rectangle hurtbox;
    ge211::Dimensions hitbox_velocity;
    ge211::Dimensions hurtbox_velocity;
    ge211::Dimensions hurtbox_angular_velocity;
    ge211::Dimensions facing;
    
    bool blocking;
    bool active;
    
    int health;
    int recovery;
    

    friend struct Test_access;
};