#pragma once
#include "model.hxx"
#include <ge211.hxx>
#include "view.hxx"

class View
{
    View::View(Model const& model)
        : model_(model)
        , hitbox({50,100,0,0})
        , hurtbox({25,50,0,0})
    {}
};