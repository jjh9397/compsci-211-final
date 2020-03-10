#include "controller.hxx"

Controller::Controller(Player p1, Player p2)
        : model_(p1, p2, 0, 0)
        , view_(model_)
{}

void Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}

ge211::Dimensions Controller::initial_window_dimensions() const
{
    return view_.initial_window_dimensions();
}

std::string Controller::initial_window_title() const
{
    return view_.initial_window_title();
}

void Controller::on_key_down(ge211::Key key)
{
    if (key == ge211::Key::code('q'))
    {
        model_.p1_move({-10,0});
        back.timestamp = ge211::Time_point::now();
        p1_buffer.push_back(back);
    }
    if (key == ge211::Key::code('e'))
    {
        model_.p1_move({10,0});
        forward.timestamp = ge211::Time_point::now();
        p1_buffer.push_back(forward);
    }
    if (key == ge211::Key::code(','))
    {
        model_.p2_move({-10,0});
        p2_buffer.push_back(back);
    }
    if (key == ge211::Key::code('/'))
    {
        model_.p2_move({10,0});
        p1_buffer.push_back(forward);
    }
}

void Controller::on_key_up(ge211::Key key)
{
    if (key == ge211::Key::code('q'))
    {
        model_.p1_move({0,0});
    }
    if (key == ge211::Key::code('e'))
    {
        model_.p1_move({0,0});
    }
    if (key == ge211::Key::code(','))
    {
        model_.p2_move({0,0});
    }
    if (key == ge211::Key::code('/'))
    {
        model_.p2_move({0,0});
    }
}

void Controller::on_frame(double dt)
{
    model_.update(dt);
}
