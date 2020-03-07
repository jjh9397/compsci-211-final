#pragma once

#include <iostream>
#include <ge211.hxx>

struct Player
{
    Player(ge211::Position, ge211::Position, ge211::Dimensions);

    ge211::Position hitbox_next();
    ge211::Position hurtbox_next();
    bool hits_side();
    bool hits_bottom();
    bool recovered();

    bool take_damage(int damage);
    


    ge211::Rectangle hitbox;
    ge211::Rectangle hurtbox;
    ge211::Dimensions hitbox_velocity;
    ge211::Dimensions hurtbox_velocity;
    int hurtbox_angular_velocity;
    ge211::Dimensions direction;
    
    bool blocking;
    bool active;
    
    int health;
    int recovery;
    

    friend struct Test_access;
};