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
        , block({"X",0})
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
        q = true;
        //if (e && model_.frame - p1_buffer.buffer.back().timestamp > 8)
        //{
         //   neutral.timestamp = model_.frame;
        //    p1_buffer.buffer.push_back(neutral);
        //}
        //else
        //{
               back.timestamp = model_.frame;
              p1_buffer.buffer.push_back(back);
        //} 
    }
    if (key == ge211::Key::code('e') && !model_.check_collision())
    {
        e = true;
        //if (q && model_.frame - p1_buffer.buffer.back().timestamp > 8)
        //{
        //    neutral.timestamp = model_.frame;
        //    p1_buffer.buffer.push_back(neutral);
        //}
        //else
        //{
           front.timestamp = model_.frame;
           p1_buffer.buffer.push_back(front);
        //}
        
    }
    if (key == ge211::Key::code('r'))
    {
        attack.timestamp = model_.frame;
        p1_buffer.buffer.push_back(attack);
    }
    if (key == ge211::Key::code('t'))
    {
        block.timestamp = model_.frame;
        p1_buffer.buffer.push_back(block);
    }

    if (key == ge211::Key::code(','))
    {
        back.timestamp = model_.frame;
        p2_buffer.buffer.push_back(back);
    }
    if (key == ge211::Key::code('/'))
    {
        front.timestamp = model_.frame;
        p2_buffer.buffer.push_back(front);
    }
    
    if (key == ge211::Key::code('m'))
    {
        attack.timestamp = model_.frame;
        p2_buffer.buffer.push_back(attack);
    }
    if (key == ge211::Key::code('n'))
    {
        block.timestamp = model_.frame;
        p2_buffer.buffer.push_back(block);
    }
    if (key == ge211::Key::code('f'))
        quit();
}

void Controller::on_key_up(ge211::Key key)
{
    if (key == ge211::Key::code('q'))
    {
        q = false;
        if (!e)
        {
            neutral.timestamp = model_.frame;
            p1_buffer.buffer.push_back(neutral);
        }
    }
    if (key == ge211::Key::code('e'))
    {
        e = false;
        if (!q)
        {
            neutral.timestamp = model_.frame;
            p1_buffer.buffer.push_back(neutral);
        }
    }
    if (key == ge211::Key::code('t'))
    {
        neutral.timestamp = model_.frame;
        p1_buffer.buffer.push_back(neutral);
    }

    
    if (key == ge211::Key::code(','))
    {
        neutral.timestamp = model_.frame;
        p2_buffer.buffer.push_back(neutral);
    }
    if (key == ge211::Key::code('/'))
    {
        neutral.timestamp = model_.frame;
        p2_buffer.buffer.push_back(neutral);
    }
    if (key == ge211::Key::code('n'))
    {
        neutral.timestamp = model_.frame;
        p2_buffer.buffer.push_back(neutral);
    }
}

void Controller::on_frame(double dt)
{
    // if (q)
    // {
    //     back.timestamp = model_.frame;
    //     p1_buffer.buffer.push_back(back);
    // }
    // if (e)
    // {
    //     front.timestamp = model_.frame;
    //     p1_buffer.buffer.push_back(front);
    // }
    
    if (p1_buffer.buffer.size() > 0)
    {
        if (model_.frame - p1_buffer.buffer[0].timestamp > 16 && p1_buffer.buffer.size() > 1)
        {
            p1_buffer.buffer.erase(p1_buffer.buffer.begin());
        }

        if (p1_buffer.check_move("4"))
        {
            model_.p1_move({-10,0});
        }
        else if (p1_buffer.check_move("6"))
        {
            model_.p1_move({10,0});
        }
        else
        {
            model_.p1_move({0,0});
        }

        if (p1_buffer.check_move("A") && p1_buffer.buffer.end()->timestamp>=model_.frame-10)
        {
            model_.p1_attack();
        }
        else
        {
            model_.p1_stop_attack();
        }

        if (p1_buffer.check_move("X"))
        {
            model_.p1_block();
        }
        else
        {
            model_.p1_stops_block();
        }
    }
    if (p2_buffer.buffer.size() > 0)
    {
        if (model_.frame - p2_buffer.buffer[0].timestamp > 16 && p2_buffer.buffer.size() > 1)
        {
            p2_buffer.buffer.erase(p2_buffer.buffer.begin());
        }

        if (p2_buffer.check_move("4"))
        {
            model_.p2_move({-10,0});
        }
        else if (p2_buffer.check_move("6"))
        {
            model_.p2_move({10,0});
        }
        else
        {
            model_.p2_move({0,0});
        }

        if (p2_buffer.check_move("A") && p2_buffer.buffer.end()->timestamp>=model_.frame-10)
        {
            model_.p2_attack();
        }
        else
        {
            model_.p2_stop_attack();
        }

        if (p2_buffer.check_move("X"))
        {
            model_.p2_block();
        }
        else
        {
            model_.p2_stops_block();
        }
    }
    if (model_.game_over())
    {
        quit();
    }
    if (model_.push_p1)
    {
        model_.p1_move({-25,0});
        model_.push_p1=false;
    }
    if (model_.push_p2)
    {
        model_.p2_move({25,0});
        model_.push_p2=false;
    }
    //if (model_.frame>model_.p1_attack())
    //{
      //  model_.p1_stop_attack();
    //}
    model_.update(dt);
}
