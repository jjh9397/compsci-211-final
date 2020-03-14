#pragma once

#include <iostream>
#include <ge211.hxx>

// Struct that represents a single player. Has members that keep track of its location and status
struct Player
{
    Player(ge211::Position, ge211::Dimensions);

    // returns the player after velocity is added to its location, places them back on the ground if they fall too much
    Player hitbox_next();
    
    // returns whether the player hit the edge of the screen
    bool hits_side();

    // returns if the player has recovered or still has recovery frames
    bool recovered() const;

    // causes player to attack if active is true by creating a hurtbox; otherwise it shrinks the hurtbox
    void attack();

    // causes player to do an air attack by creating a hurtbox if attack_1_air is not zero
    void start_attack_1_air();

    ge211::Rectangle hitbox;
    ge211::Rectangle hurtbox;
    ge211::Rectangle hurtbox_attack_1_air;
    ge211::Dimensions hitbox_velocity;
    ge211::Dimensions hurtbox_velocity;
    ge211::Dimensions direction;
    
    bool blocking;
    bool active;
    bool air;
    
    int health;
    int recovery;
    bool stun;

    int jump;
    int attack_1;
    int attack_1_air;

};