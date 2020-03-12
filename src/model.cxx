#include "model.hxx"

Model::Model(Player player1, Player player2, int width, int height)
        : p1_(player1)
        , p2_(player2)
        , frame(0)
        , push_p1(false)
        , push_p2(false)
{}

void Model::p1_attack()
{
    if (p1_.recovered())
    {
        p1_.active = true;
        p1_.attack();
        check_for_hit();
        p1_.recovery = 16;
    }
    if (p1_.recovery == 6)
    {
        p1_stop_attack();
    }
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
        if(!(p1_.hurtbox.top_left().x + p1_.hurtbox.width < p2_.hitbox.top_left().x) && !p2_.blocking)
        {
            p2_.health-=1;
            p2_.stun=true;
            push_p2=true;
        }
        else if(!(p1_.hurtbox.top_left().x + p1_.hurtbox.width < p2_.hitbox.top_left().x) && p2_.blocking)
        {
            push_p1=true;
        }

    }
    if(p2_.active)
    {
        if(p2_.hurtbox.top_left().x <= p1_.hitbox.top_right().x && !p1_.blocking)
        {
            p1_.health-=1;
            p1_.stun=true;
            push_p1=true;
        }
        if(p2_.hurtbox.top_left().x <= p1_.hitbox.top_right().x && p1_.blocking)
        {
            push_p2=true;
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
bool Model::p1_state()
{
    return p1_.blocking;
}
void Model::p2_block()
{
    p2_.blocking=true;
}

void Model::p2_stops_block()
{
    p2_.blocking=false;
}

bool Model::p2_state()
{
    return p2_.blocking;
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

int Model::get_p1_health() const
{
    return p1_.health;
}

int Model::get_p2_health() const
{
    return p2_.health;
}

void Model::update(double dt)
{
    p1_ = p1_.hitbox_next();
    p2_ = p2_.hitbox_next();
    if (!p1_.recovered())
    {
        p1_.recovery--;
    }
    if (!p2_.recovered())
    {
        p2_.recovery--;
    }
    frame++;

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

int& Model::access_p1_recovery()
{
    return p1_.recovery;
}

int& Model::access_p2_recovery()
{
    return p2_.recovery;
}

bool Model::side_p1()
{
    return p1_.hits_side();
}

bool Model::side_p2()
{
    return p2_.hits_side();
}

bool Model::p1_stun()
{
    return p1_.stun;
}

bool Model::p2_stun()
{
    return p2_.stun;
}

void Model::set_p1_stun(bool stu)
{
    p1_.stun=stu;
}

void Model::set_p2_stun(bool stu)
{
    p2_.stun=stu;
}