#include <iostream>
#include "player.hxx"
#include <ge211.hxx>

Player::Player(ge211::Position hit_pos, ge211::Position hurt_pos, ge211::Dimensions facing)
        : hitbox({50,100})
        , hitbox_velocity({0,0})
        , hurtbox_velocity({0,0})
        , blocking(false)
        , active(false)
        , health(100)     
        , direction(facing)
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

bool Player::recovered()
{
    return recovery == 0;
}

bool Player::hits_side()
{
    if (hitbox.top_left().x < 0 || hitbox.top_left().right_by(hitbox.width).x > 1280)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Player::hits_bottom()
{
    if (hitbox.top_left().down_by(hitbox.height).y < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Player::take_damage(int damage)
{
    health -= damage;
    if (health < 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int Player::get_health()
{
    return health;
}
    
//void Player::set_hitbox_position(ge211::Position)
ge211::Position Player::get_hitbox_position()
{
    return hitbox.top_left();
}

//void Player::set_hurtbox_position(ge211::Position)
ge211::Position Player::get_hurtbox_position()
{
    return hurtbox.top_left();
}
    
void Player::set_hitbox_velocity(ge211::Dimensions vel)
{
    hitbox_velocity = vel;
}
ge211::Dimensions Player::get_hitbox_velocity()
{
    return hitbox_velocity;
}

void Player::set_hurtbox_velocity(ge211::Dimensions vel)
{
    hurtbox_velocity = vel;
}
void Player::set_hurtbox_angular_velocity(int vel)
{
    hurtbox_angular_velocity = vel;
}
ge211::Dimensions Player::get_hurtbox_velocity()
{
    return hurtbox_velocity;
}
int Player::get_hurtbox_angular_velocity()
{
    return hurtbox_angular_velocity;
}

void Player::set_direction(ge211::Dimensions dir)
{
    direction = dir;
}
ge211::Dimensions Player::get_direction()
{
    return direction;
}

void Player::set_blocking(bool block)
{
    blocking = block;
}

bool Player::get_blocking()
{
    return blocking;
}