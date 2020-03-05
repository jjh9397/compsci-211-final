#pragma once
#include "model.hxx"
#include <ge211.hxx>

class View
{
public:
   explicit View(Model const&);

   void draw(ge211::Sprite_set& set);

    ge211::Dimensions initial_window_dimensions() const;

    std::string initial_window_title() const;

private:
   Model const& model_;
   ge211::Rectangle_sprite hitbox;
   ge211::Rectangle_sprite hurtbox;
   Player p1;
   Player p2;
};