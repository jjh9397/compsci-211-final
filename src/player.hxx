#pragma once

#include <iostream>
#include <ge211.hxx>

class Player
{
public:
    explicit Player(ge211::Position, ge211::Position, ge211::Dimensions);

    ge211::Position hitbox_next();
    ge211::Position hurtbox_next();
    bool hits_side();
    bool hits_bottom();
    bool recovered();

    bool take_damage(int damage);
    int get_health();
    
    //void set_hitbox_position(ge211::Position);
    ge211::Position get_hitbox_position();

    //void set_hurtbox_position(ge211::Position);
    ge211::Position get_hurtbox_position();
    
    void set_hitbox_velocity(ge211::Dimensions);
    ge211::Dimensions get_hitbox_velocity();

    void set_hurtbox_velocity(ge211::Dimensions);
    void set_hurtbox_angular_velocity(int);
    ge211::Dimensions get_hurtbox_velocity();
    int get_hurtbox_angular_velocity();

    void set_direction(ge211::Dimensions);
    ge211::Dimensions get_direction();

    void set_blocking(bool);
    bool get_blocking();

private:
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