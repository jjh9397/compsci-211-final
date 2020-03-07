#include "view.hxx"

View::View(Model const &model)
    : model_(model)
    , hitbox_sprite({50,100}, {255,255,255})
    , hurtbox_sprite({10,50}, {255,255,255})
    , p1(model_.get_p1_position(), model_.get_p1_position(), ge211::Dimensions({1,0}))
    , p2(model_.get_p2_position(), model_.get_p2_position(), ge211::Dimensions({-1,0}))
{}

ge211::Dimensions View::initial_window_dimensions() const
{
    return {1280, 720};
}

std::string View::initial_window_title() const 
{
    return "Grabble Versus 2";
}

void View::draw(ge211::Sprite_set& set)
{
    set.add_sprite(hitbox_sprite, p1.hitbox.top_left());
    set.add_sprite(hitbox_sprite, p2.hitbox.top_left());
}