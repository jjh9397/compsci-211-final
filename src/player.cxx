#include "player.hxx"

Player::Player(ge211::Position hit_pos, ge211::Position hurt_pos, ge211::Dimensions facing)
        : hitbox({hit_pos.x, hit_pos.y,200,250})
        , hurtbox({hit_pos.x+hitbox.width,hit_pos.y+(hitbox.height/2),1,1})
        , hitbox_velocity({0,0})
        , hurtbox_velocity({0,0})
        , blocking(false)
        , active(false)
        , health(100)     
        , direction(facing)
{
    //hitbox.top_left() = hit_pos;
    //hurtbox.top_left() = hurt_pos;
}


// change these to return rectangles??
Player Player::hitbox_next()
{
    ge211::Position next_hit_pos = {this->hitbox.top_left().x + hitbox_velocity.width, this->hitbox.top_left().y + hitbox_velocity.height};
    Player result(next_hit_pos, hurtbox.top_left(), direction);
    result.active = this->active;
    result.blocking = this->blocking;
    result.direction = this->direction;
    result.health = this->health;
    result.hitbox_velocity = this->hitbox_velocity;
    result.hurtbox = this->hurtbox;
    result.recovery = this->recovery;
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
    return hitbox.top_left().x < 0 || hitbox.top_left().right_by(hitbox.width).x > 1280;
}

bool Player::hits_bottom()
{
    return hitbox.top_left().down_by(hitbox.height).y < 0;
}

bool Player::take_damage(int damage) {
    health -= damage;
    return health >= 0;
}

void Player::attack()
{
    if (active)
    {
        ge211::Rectangle hurt = {hurtbox.x+hitbox.width,hurtbox.y+(hitbox.height/2),100,100};
        hurtbox=hurt;
    }
    else
    {
        ge211::Rectangle hurt = {hurtbox.x+hitbox.width,hurtbox.y+(hitbox.height/2),1,1};
        hurtbox=hurt;
    }
}

