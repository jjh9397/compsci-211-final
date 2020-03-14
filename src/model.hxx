#pragma once

#include <iostream>
#include "player.hxx"
#include <ge211.hxx>

// Logical state of the game
class Model
{
public:

    // constructs a model with two players and a width and height for the dimensions of the stage
    explicit Model(Player player1, Player player2);

    // sets the velocity of the player
    void p1_move(ge211::Dimensions);

    // sets the velocity of the player
    void p2_move(ge211::Dimensions);

    // stops player's horizontal movement if it is not in the air
    void stop_p1();
    void stop_p2();

    // makes player jump through use of a counter and by using the move functions
    void p1_jump();
    void p2_jump();
    
    // helper functions to set vertical velocity to zero when appropriate
    void stop_p1_jump();
    void stop_p2_jump();

    // returns value of air member variable, used to determine if player is airborne
    bool p1_air();
    bool p2_air();

    // functions that are called to begin and end attacks
    void p1_attack();
    void p1_stop_attack();
    void p2_attack();
    void p2_stop_attack();
    
    // checks if either player gets hit by the other and subtracts health
    void check_for_hit();

    // functions used to begin and end air attacks. Getters are used to draw animations when attack is active
    void p1_attack_1_air();
    void p2_attack_1_air();
    int get_p1_attack_1_air() const;
    int get_p2_attack_1_air() const;

    // functions used to put players into a blocking state, or to make them stop blocking
    void p1_block();
    void p1_stops_block();
    void p2_block();
    void p2_stops_block();

    // returns whether players are colliding
    bool check_collision();

    // returns health of player
    int get_p1_health() const;
    int get_p2_health() const;

    // does calculations that need to happen every frame. Players lose one frame of recovery,
    // are stopped if they try to move past screen bounds, and gain velocity in the y direction 
    //if they are airborne. Players are then updated to their next position, and a frame counter used for calculations is incremented.
    void update(double dt);

   
    // returns whether player's attack is active
    bool get_p1_active() const;
    bool get_p2_active() const;
    
    // returns whether player is blocking
    bool get_p1_block() const;
    bool get_p2_block() const;

    // returns position of players
    ge211::Position get_p1_position() const;
    ge211::Position get_p2_position() const;
    
    // ends the game if there is a winner
    bool game_over();

    // allows modification of recovery values
    int& access_p1_recovery();
    int& access_p2_recovery();
    
    // returns whether player collides with edge
    bool side_p1();
    bool side_p2();

    // returns whether player is blocking
    bool p1_state();
    bool p2_state();
    
    // returns whether player is stunned
    bool p1_stun();
    bool p2_stun();

    // sets whether player is stunned or not
    void set_p1_stun(bool stu);
    void set_p2_stun(bool stu);
    
    int frame;
    bool push_p1;
    bool push_p2;
    bool collide_p1;
    bool collide_p2;
    
private:
    friend struct Test_access;
    Player p1_;
    Player p2_;
};