#include "model.hxx"

Model::Model(Player player1, Player player2, int width, int height)
        : p1_(player1)
        , p2_(player2)
        , frame(0)
{}

void Model::p1_attack()
{
    p1_.active=true;
    p1_.attack();
    check_for_hit();
}
void Model::p1_stop_attack()
{
    p1_.active=false;
    p1_.attack();
}

void Model::p2_attack()
{
    p2_.active=true;
    p2_.attack();
    check_for_hit();
}
void Model::p2_stop_attack()
{
    p2_.active=false;
    p2_.attack();
}
void Model::check_for_hit()
{
    if(p1_.active)
    {
        if(!(p1_.hurtbox.top_left().x+p1_.hurtbox.width < p2_.hitbox.top_left().x))
        {
            p2_.health-=10;
        }
    }
    if(p2_.active)
    {
        if(p2_.hurtbox.top_left().x <= p1_.hitbox.top_right().x)
        {
            p1_.health-=10;
        }
    }
}

void Model::p1_block()
{
    p1_.blocking=true;
}

void Model::p1_stops_block()
{
    p1_.blocking=false;
}

void Model::p2_block()
{
    p2_.blocking=true;
}

void Model::p2_stops_block()
{
    p2_.blocking=false;
}

bool Model::health_check()
{
    if (p1_.health<=0)
    {
        winner_=2;
        return true;
    }
    else if (p2_.health<=0)
    {
        winner_=1;
        return true;
    }
    return false;
}

bool Model::check_collision()
{
    return !(p1_.hitbox.top_right().x<p2_.hitbox.top_left().x || p2_.hitbox.top_right().x<p1_.hitbox.top_left().x ||
            p1_.hitbox.bottom_right().y<p2_.hitbox.top_right().y || p2_.hitbox.bottom_right().y<p1_.hitbox.top_right().y);
}

int Model::get_p1_health()
{
    return p1_.health;
}

int Model::get_p2_health()
{
    return p2_.health;
}

void Model::update(double dt)
{
    p1_ = p1_.hitbox_next();
    p2_ = p2_.hitbox_next();
    frame++;
}

void Model::p1_move(ge211::Dimensions pos)
{
    if(!check_collision() || (!p1_.hits_side()))
    {
        p1_.hitbox_velocity = pos;
    }
    // else
    // {
    //     ge211::Dimensions position={0, 0};
    //     p1_.hitbox_velocity = position;
    // }
}
void Model::p2_move(ge211::Dimensions pos)
{
    if(!check_collision() || (!p2_.hits_side()))
    {
        p2_.hitbox_velocity = pos;
    }
    // else
    // {
    //     ge211::Dimensions position={0, 0};
    //     p2_.hitbox_velocity = position;
    // }
}

ge211::Position Model::get_p1_position() const
{
    return p1_.hitbox.top_left();
}

ge211::Position Model::get_p2_position() const
{
    return p2_.hitbox.top_left();
}
bool Model::get_p1_active() const
{
    return p1_.active;
}

bool Model::get_p2_active() const
{
    return p2_.active;
}

bool Model::game_over()
{
    if(p1_.health==0)
    {
        return true;
    }
    else if(p2_.health==0)
    {
        return true;
    }
    else if(p1_.health==0 && p2_.health==0)
    {
        return true;
    }
    return false;
}