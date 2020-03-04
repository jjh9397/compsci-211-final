#include <iostream>
#include "player.hxx"
#include <ge211.hxx>

Player::Player(ge211::Position hit_pos, ge211::Position hurt_pos, ge211::Dimensions direction)
        : hitbox({50,100})
        , hitbox_velocity({0,0})
        , hurtbox_velocity({0,0})
        , blocking(false)
        , active(false)
        , health(100)     
        , facing(direction)
{
    hitbox.top_left() = hit_pos;
    hitbox.top_right() = hurt_pos;
}

ge211::Position Player::hitbox_next()
{
    ge211::Position result = hitbox.top_left();
    result += hitbox_velocity;
    return result;
}

ge211::Position Player::hurtbox_next()
{
    ge211::Position result = hurtbox.top_left();
    result += hurtbox_velocity;
    return result;
}