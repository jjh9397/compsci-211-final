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
   ge211::Rectangle_sprite hitbox_sprite;
   ge211::Rectangle_sprite hurtbox_sprite;
   ge211::Image_sprite bg;
   ge211::Image_sprite p1_sprite;
   ge211::Image_sprite p2_sprite;
   ge211::Rectangle_sprite health_red;
   ge211::Image_sprite block_sprite;
   ge211::Image_sprite attack_1_sprite;
   ge211::Image_sprite attack_1_air_sprite;
};