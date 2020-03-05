#include "model.hxx"
#include <ge211.hxx>
#include "view.hxx"

View::View(Model const &model)
    : model_(model)
    , hitbox({50,100}, {0,0,0})
    , hurtbox({10,50}, {255,255,255})
    , p1(ge211::Position(400,20), ge211::Position(400,20), ge211::Dimensions({1,0}))
    , p2(ge211::Position(400,20), ge211::Position(400,20), ge211::Dimensions({-1,0}))
{}
