#include "player.hxx"

Player::Player(ge211::Position hit_pos, ge211::Dimensions facing)
        : hitbox({hit_pos.x, hit_pos.y,150,210})
        , hurtbox({hit_pos.x+hitbox.width,hit_pos.y+(hitbox.height/2),1,1})
        , hitbox_velocity({0,0})
        , hurtbox_velocity({0,0})
        , blocking(false)
        , active(false)
        , health(100)     
        , direction(facing)
        , stun(false)
        , recovery(0)
        , air(false)
        , attack_1(0)
        , jump(0)
        , attack_1_air(0)
{

}

Player Player::hitbox_next()
{
    ge211::Position next_hit_pos = {this->hitbox.top_left().x + hitbox_velocity.width, this->hitbox.top_left().y + hitbox_velocity.height};
    if (next_hit_pos.y > 470)
    {
        next_hit_pos.y = 470;
        air = false;
    }
    Player result(next_hit_pos, direction);
    result.hitbox_velocity = this->hitbox_velocity;
    result.blocking = this->blocking;
    result.active = this->active;
    result.health = this->health;
    result.direction = this->direction;    
    result.hurtbox = this->hurtbox;
    result.stun = this->stun;
    result.recovery = this->recovery;
    result.air = this->air;
    result.attack_1 = this->attack_1;
    result.jump = this->jump;
    result.attack_1_air = this->attack_1_air;
    return result;
}

bool Player::recovered() const
{
    return recovery == 0;
}

bool Player::hits_side() 
{
    return hitbox_next().hitbox.top_left().x < 0 || hitbox_next().hitbox.top_left().right_by(hitbox.width).x > 1280;
}

void Player::attack()
{
    if (active)
    {
        ge211::Rectangle hurt = {hitbox.x+(hitbox.width*direction.width),hurtbox.y,150,60};
        hurtbox=hurt;
    }
    else
    {
        ge211::Rectangle hurt = {hitbox.x+(hitbox.width*direction.width),hurtbox.y,1,1};
        hurtbox=hurt;
    }
}

void Player::start_attack_1_air()
{
    if (attack_1_air != 0)
    {
        ge211::Rectangle hurt = {hitbox.x+(hitbox.width*direction.width),hurtbox.y,200,120};
        hurtbox_attack_1_air=hurt;
    }
    else
    {
        ge211::Rectangle hurt = {hitbox.x+(hitbox.width*direction.width),hurtbox.y,1,1};
        hurtbox_attack_1_air=hurt;
    }
}