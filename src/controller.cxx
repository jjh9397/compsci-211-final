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
        // , front({"6", 0})
        // , back({"4", 0})
        // , attack({"A", 0})
        // , neutral_1({"5", 0})
        // , block({"X",0})
        , q(false)
        , w(false)
        , e(false)
        , comma(false)
        , period(false)
        , slash(false)
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
         //   neutral_1.timestamp = model_.frame;
        //    p1_buffer.buffer.push_back(neutral_1);
        //}
        //else
        //{
            Input back = {"4", model_.frame};
            //back.timestamp = model_.frame;
            p1_buffer.buffer.push_back(back);
        //} 
    }
    if (key == ge211::Key::code('e') && !model_.check_collision())
    {
        e = true;
        //if (q && model_.frame - p1_buffer.buffer.back().timestamp > 8)
        //{
        //    neutral_1.timestamp = model_.frame;
        //    p1_buffer.buffer.push_back(neutral_1);
        //}
        //else
        //{
           Input front = {"6", model_.frame};
           //front.timestamp = model_.frame;
           p1_buffer.buffer.push_back(front);
        //}
        
    }
    if (key == ge211::Key::code('w') && !model_.check_collision())
    {
        w = true;
        Input jump = {"9", model_.frame};
        p1_buffer.buffer.push_back(jump);
    }
    if (key == ge211::Key::code('r'))
    {
        Input attack = {"A", model_.frame};
        //attack.timestamp = model_.frame;
        p1_buffer.buffer.push_back(attack);
    }
    if (key == ge211::Key::code('t'))
    {
        Input block = {"X", model_.frame};
        //block.timestamp = model_.frame;
        p1_buffer.buffer.push_back(block);
    }

    if (key == ge211::Key::code(','))
    {
        comma = true;
        Input back = {"4", model_.frame};
        //back.timestamp = model_.frame;
        p2_buffer.buffer.push_back(back);
    }
    if (key == ge211::Key::code('/'))
    {
        slash = true;
        Input front = {"6", model_.frame};
        //front.timestamp = model_.frame;
        p2_buffer.buffer.push_back(front);
    }
    
    if (key == ge211::Key::code('m'))
    {
        Input attack = {"A", model_.frame};
        attack.timestamp = model_.frame;
        p2_buffer.buffer.push_back(attack);
    }
    if (key == ge211::Key::code('n'))
    {
        Input block = {"X", model_.frame};
        //block.timestamp = model_.frame;
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
            Input neutral_1 = {"5", model_.frame};
            //neutral.timestamp = model_.frame;
            p1_buffer.buffer.push_back(neutral_1);
        }
    }
    if (key == ge211::Key::code('e'))
    {
        e = false;
        if (!q)
        {
            Input neutral_1 = {"5", model_.frame};
            //neutral.timestamp = model_.frame;
            p1_buffer.buffer.push_back(neutral_1);
        }
    }
    if (key == ge211::Key::code('w'))
    {
        w = false;
        Input neutral_1 = {"5", model_.frame};
        p1_buffer.buffer.push_back(neutral_1);
    }
    if (key == ge211::Key::code('t'))
    {
        Input neutral_1 = {"5", model_.frame};
        //neutral.timestamp = model_.frame;
        p1_buffer.buffer.push_back(neutral_1);
    }

    
    if (key == ge211::Key::code(','))
    {
        comma = false;
        if (!slash)
        {
            Input neutral_2 = {"5", model_.frame};
            //neutral.timestamp = model_.frame;
            p2_buffer.buffer.push_back(neutral_2);
        }
    }
    if (key == ge211::Key::code('/'))
    {
        slash = false;
        if (!comma)
        {
            Input neutral_2 = {"5", model_.frame};
            //neutral_2.timestamp = model_.frame;
            p2_buffer.buffer.push_back(neutral_2);
        }
    }
    if (key == ge211::Key::code('n'))
    {
        Input neutral_2 = {"5", model_.frame};
        //neutral_1.timestamp = model_.frame;
        p2_buffer.buffer.push_back(neutral_2);
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
    
    if (p1_buffer.buffer.size() > 0 && !model_.p1_stun())
    {
        if (model_.frame - p1_buffer.buffer[0].timestamp > 16 && p1_buffer.buffer.size() > 1)
        {
            p1_buffer.buffer.erase(p1_buffer.buffer.begin());
        }

        if (p1_buffer.check_move("4") && !model_.side_p1())
        {
            model_.p1_move({-10,0});
        }
        else if (p1_buffer.check_move("6")  && !model_.check_collision())
        {
            model_.p1_move({10,0});
        }
        else
        {
            model_.stop_p1();
        }
        if (p1_buffer.check_move("9") && !model_.check_collision())
        {
            model_.p1_move({10,-20});
        }
        else
        {
            model_.stop_p1_jump();
        }

        if (p1_buffer.check_move("A") && p1_buffer.buffer.end()->timestamp>=model_.frame - 10)
        {
            model_.p1_attack();
        }
        else
        {
            if (model_.access_p1_recovery() != 0)
            {
                model_.p1_attack();
            }
            else
            {
                model_.p1_stop_attack();
            }
            
            model_.set_p2_stun(false);
        }
        if (p1_buffer.buffer.end()->timestamp>=model_.frame-15)
        {
            model_.set_p2_stun(true);
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
    if (p2_buffer.buffer.size() > 0 && !model_.p2_stun())
    {
        if (model_.frame - p2_buffer.buffer[0].timestamp > 16 && p2_buffer.buffer.size() > 1)
        {
            p2_buffer.buffer.erase(p2_buffer.buffer.begin());
        }

        if (p2_buffer.check_move("4") && !model_.check_collision())
        {
            model_.p2_move({-10,0});
        }
        else if (p2_buffer.check_move("6") && !model_.side_p2())
        {
            model_.p2_move({10,0});
        }
        else
        {
            model_.stop_p2();
        }

        if (p2_buffer.check_move("A") && p2_buffer.buffer.end()->timestamp>=model_.frame-10)
        {
            model_.p2_attack();
        }
        else
        {
            model_.p2_stop_attack();
            model_.set_p1_stun(false);
        }
        if (p2_buffer.buffer.end()->timestamp>=model_.frame-15)
        {
            model_.set_p1_stun(true);
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
    if (model_.push_p1 && model_.p1_state())
    {
        model_.p1_move({-20,0});
        model_.push_p1=false;
    }
    else if(model_.push_p1)
    {
        model_.p1_move({-3,0});
        model_.push_p1=false;
    }

    if (model_.push_p2 && model_.p2_state())
    {
        model_.p2_move({20,0});
        model_.push_p2=false;
    }
    else if(model_.push_p2)
    {
        model_.p2_move({3,0});
        model_.push_p2=false;
    }
    model_.update(dt);
}
