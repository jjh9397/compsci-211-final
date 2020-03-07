#include "player.hxx"

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
    hurtbox.top_left() = hurt_pos;
}
// change these to return rectangles??
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

bool Player::take_damage(int damage) {
    health -= damage;
    if (health < 0) {
        return false;
    } else {
        return true;
    }
}


