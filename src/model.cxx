#include <iostream>
#include "player.hxx"
#include <ge211.hxx>
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
    p1_.set_blocking(true);
}

void Model::p1_stops_block()
{
    p1_.set_blocking(false);
}

void Model::p2_block()
{
    p2_.set_blocking(true);
}

void Model::p2_stops_block()
{
    p2_.set_blocking(false);
}

bool Model::health_check()
{
    
}

void Model::check_collision()
{

}

int Model::get_p1_health()
{
    return p1_.get_health();
}

int Model::get_p2_health()
{
    return p2_.get_health();
}