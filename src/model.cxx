#include "model.hxx"

Model::Model(Player player1, Player player2, int width, int height)
        : p1_(player1)
        , p2_(player2)
{}

void Model::p1_attack()
{

}

void Model::p2_attack()
{

}

void Model::check_for_hit()
{

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
    
}

void Model::p1_move(ge211::Dimensions pos)
{
    if(!check_collision() || (!p1_.hits_side()))
    {
        p1_.hitbox_velocity = pos;
    }
}
void Model::p2_move(ge211::Dimensions pos)
{
    if(!check_collision() || (!p2_.hits_side()))
    {
        p2_.hitbox_velocity = pos;
    }
}