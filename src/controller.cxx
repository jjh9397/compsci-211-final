#include "controller.hxx"

bool operator==(const Input& lhs, const Input& rhs)
{
    return (lhs.move == rhs.move && lhs.timestamp == rhs.timestamp);
}

Controller::Controller(Player p1, Player p2)
        : model_(p1, p2, 0, 0)
        , view_(model_)
        , p1_buffer()
        , p2_buffer()
        , front({"6", 0})
        , back({"4", 0})
        , attack({"A", 0})
        , neutral({"5", 0})
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
        //model_.p1_move({-10,0});
        back.timestamp = model_.frame;
        p1_buffer.buffer.push_back(back);
    }
    if (key == ge211::Key::code('e'))
    {
        //model_.p1_move({10,0});
        front.timestamp = model_.frame;
        p1_buffer.buffer.push_back(front);
    }
    if (key == ge211::Key::code(','))
    {
        model_.p2_move({-10,0});
        back.timestamp = model_.frame;
        p2_buffer.buffer.push_back(back);
    }
    if (key == ge211::Key::code('/'))
    {
        model_.p2_move({10,0});
        front.timestamp = model_.frame;
        p2_buffer.buffer.push_back(front);
    }
    if (key == ge211::Key::code('r'))
    {
        model_.p1_attack();
        attack.timestamp = model_.frame;
        p1_buffer.buffer.push_back(attack);
    }
}

void Controller::on_key_up(ge211::Key key)
{
    if (key == ge211::Key::code('q'))
    {
        neutral.timestamp = model_.frame;
        p1_buffer.buffer.push_back(neutral);
    }
    if (key == ge211::Key::code('e'))
    {
        neutral.timestamp = model_.frame;
        p1_buffer.buffer.push_back(neutral);
    }
    if (key == ge211::Key::code(','))
    {
        model_.p2_move({0,0});
    }
    if (key == ge211::Key::code('/'))
    {
        model_.p2_move({0,0});
    }
    if (key == ge211::Key::code('r'))
    {
        model_.p1_stop_attack();
    }
}

void Controller::on_frame(double dt)
{
    if (p1_buffer.buffer.size() > 0)
    {
        if (model_.frame - p1_buffer.buffer[0].timestamp > 8 && p1_buffer.buffer.size() > 1)
        {
            p1_buffer.buffer.erase(p1_buffer.buffer.begin());
        }

        if (p1_buffer.check_move("4"))
        {
            model_.p1_move({-10,0});
        }
        else
        {
            model_.p1_move({0,0});
        }
        
        if (p1_buffer.check_move("6"))
        {
            model_.p1_move({10,0});
        }
        else
        {
            model_.p1_move({0,0});
        }

        if (p1_buffer.check_move("A"))
        {
            model_.p1_attack();
        }
    }
    // if (p2_buffer.buffer.size() > 0)
    // {
    //     if (model_.frame - p2_buffer.buffer[0].timestamp > 8)
    //     {
    //         p2_buffer.buffer.erase(p1_buffer.buffer.begin());
    //     }
    // }
    model_.update(dt);
}
