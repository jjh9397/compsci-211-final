#include "view.hxx"

View::View(Model const &model)
    : model_(model)
    , hitbox({50,100}, {255,255,255})
    , hurtbox({10,50}, {255,255,255})
    , p1(ge211::Position(400,20), ge211::Position(400,20), ge211::Dimensions({1,0}))
    , p2(ge211::Position(400,20), ge211::Position(400,20), ge211::Dimensions({-1,0}))
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
    set.add_sprite(hitbox, p1.hitbox.top_left());
    set.add_sprite(hitbox, p2.hitbox.top_left());
}