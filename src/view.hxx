#pragma once
#include "model.hxx"
#include <ge211.hxx>

class View
{
public:
   explicit View(Model const&);

   void draw(ge211::Sprite_set& set);

private:
   Model const& model_;
   ge211::Rectangle_sprite hitbox;
   ge211::Rectangle_sprite hurtbox;
   Player p1;
   Player p2;
};