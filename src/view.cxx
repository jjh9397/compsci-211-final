#include "model.hxx"
#include <ge211.hxx>
#include "view.hxx"

View::View(Model const &model)
    : model_(model)
    , hitbox()
    , hurtbox()
{}
