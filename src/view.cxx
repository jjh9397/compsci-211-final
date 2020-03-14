#include "view.hxx"

View::View(Model const &model)
    : model_(model)
    , hitbox_sprite({50,100}, {255,255,255})
    , hurtbox_sprite({100,50}, {255,255,255})
    , health_red({5,50,}, {255,0,0})
    , bg("bg.png")
    , p1_sprite("p1.png")
    , p2_sprite("p2.png")
    , block_sprite("block.png")
    , attack_1_sprite("attack_1.png")
    , attack_1_air_sprite("attack_1_air.png")
{}

ge211::Dimensions View::initial_window_dimensions() const
{
    return {1280, 486};
}

std::string View::initial_window_title() const 
{
    return "Grabble Versus 2";
}

void View::draw(ge211::Sprite_set& set)
{
    set.add_sprite(p1_sprite, {model_.get_p1_position().x, model_.get_p1_position().y-236}, 1, ge211::Transform::flip_h());
    set.add_sprite(p2_sprite, {model_.get_p2_position().x, model_.get_p2_position().y-236}, 1);
    set.add_sprite(bg, {0,0}, 0);
    if(model_.get_p1_active())
    {
        set.add_sprite(attack_1_sprite, {model_.get_p1_position().x+50,model_.get_p1_position().y+50-236},1,  ge211::Transform::flip_h());
    }
    if(model_.get_p2_active())
    {
        set.add_sprite(attack_1_sprite, {model_.get_p2_position().x-150,model_.get_p2_position().y+50-236},1);
    }
    
    if (model_.get_p1_attack_1_air() != 0)
    {
        set.add_sprite(attack_1_air_sprite,{model_.get_p1_position().x+100,model_.get_p1_position().y+75-236},1, ge211::Transform::rotation(30));
    }
    if (model_.get_p2_attack_1_air() != 0)
    {
        set.add_sprite(attack_1_air_sprite,{model_.get_p2_position().x-100,model_.get_p2_position().y+75-236},1, ge211::Transform::rotation(30));
    }

    if (model_.get_p1_block())
    {
        set.add_sprite(block_sprite, {model_.get_p1_position().x+50,model_.get_p1_position().y+50-300},1, ge211::Transform::flip_h());
    }
    if (model_.get_p2_block())
    {
        set.add_sprite(block_sprite, {model_.get_p2_position().x-50,model_.get_p2_position().y+50-300},1);
    }
    set.add_sprite(health_red, {50,50},1,ge211::Transform::scale_x(model_.get_p1_health()));
    ge211::Transform custom=ge211::Transform{}.set_flip_v(true).scale_x(model_.get_p2_health());
    set.add_sprite(health_red, {730,50},1,custom);
}