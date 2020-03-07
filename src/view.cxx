#include "view.hxx"

View::View(Model const &model)
    : model_(model)
    , hitbox_sprite({50,100}, {255,255,255})
    , hurtbox_sprite({10,50}, {255,255,255})
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
    set.add_sprite(hitbox_sprite, model_.get_p1_position());
    set.add_sprite(hitbox_sprite, model_.get_p2_position());
}