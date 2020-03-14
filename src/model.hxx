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
    void p1_move(ge211::Dimensions);

    // sets the velocity of the player
    void p2_move(ge211::Dimensions);

    void stop_p1();

    void stop_p2();

    void p1_jump();

    void p2_jump();
    
    void stop_p1_jump();

    void stop_p2_jump();

    bool p1_air();

    bool p2_air();

    // makes the  1st player do their attack based on if it is charged up or not
    void p1_attack();
    void p1_stop_attack();
    // makes the 2nd player do their attack based on if it is charged up or not
    void p2_attack();
    void p2_stop_attack();
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
    bool check_collision();

    // gets the health of the 1st player
    int get_p1_health() const;

    // gets the health of the 2nd player
    int get_p2_health() const;

    void update(double dt);

    int frame;

    bool get_p1_active() const;
    bool get_p2_active() const;
    bool get_p1_block() const;
    bool get_p2_block() const;

    ge211::Position get_p1_position() const;

    ge211::Position get_p2_position() const;
    bool game_over();

    int& access_p1_recovery();
    int& access_p2_recovery();
    bool push_p1;
    bool push_p2;
    bool side_p1();
    bool side_p2();
    bool p1_state();
    bool p2_state();
    bool p1_stun();
    bool p2_stun();
    void set_p1_stun(bool stu);
    void set_p2_stun(bool stu);
private:

    friend struct Test_access;
    int winner_ = 0;
    Player p1_;
    Player p2_;

    // declares winner and resets the game to original positions
    //bool game_over();
};