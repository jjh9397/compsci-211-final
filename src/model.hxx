#pragma once

#include <iostream>
#include "player.hxx"
#include <ge211.hxx>

// Logical state of the game
class Model
{
public:

    // constructs a model with two players and a width and height for the dimensions of the stage
    explicit Model(Player player1, Player player2, int width, int height);

    // sets the velocity of the player
    void set_p1_velocity(ge211::Position);

    // sets the velocity of the player
    void set_p2_velocity(ge211::Position);

    // makes the  1st player do their attack based on if it is charged up or not
    void p1_attack();

    // makes the 2nd player do their attack based on if it is charged up or not
    void p2_attack();

    // checks if either player gets hit by the other and does the necessary animations if they are hit
    void check_for_hit();

    // makes the 1st player go into a state of blocking
    void p1_block();

    void p1_stops_block();

    // makes the 2nd player go into a state of blocking
    void p2_block();

    void p2_stops_block();

    // checks if either player has 0 health and makes the game over with the helper if it returns true
    bool health_check();

    // checks to make sure players do not go through each other
    void check_collision();

    // gets the health of the 1st player
    int get_p1_health();

    // gets the health of the 2nd player
    int get_p2_health();

    void update(double dt);

private:

    friend struct Test_access;
    int winner_ = 0;
    Player p1_;
    Player p2_;

    // declares winner and resets the game to original positions
    void game_over();
};