#pragma once
#include "model.hxx"
#include "view.hxx"

// struct that holds a move (e.g. moving forwards, attacking)
// and a corresponding timestamp
struct Input
{
    std::string move;
    int timestamp;
};

// allows comparison of Inputs
bool operator==(const Input& lhs, const Input& rhs);

// struct that is a buffer that holds recent inputs
struct Input_buffer
{
    std::vector<Input> buffer;

    // looks through the buffer for the given move, and returns true if found
    bool check_move(std::string check) const
    {
        for (Input input : buffer)
        {
            if (check == "X")
            {
                if (input.move == check && input == buffer[buffer.size() - 1])
                {
                    return true;
                }
            }
            if (check == "j.A")
            {
                if (input.move == check && input == buffer[buffer.size() - 1])
                {
                    return true;
                }
            }
            if (check == "A")
            {
                if (input.move == check && (input == buffer[buffer.size() - 1]))
                {
                    return true;
                }
            }
            if (check == "9")
            {
                if (input.move == check && input == buffer[buffer.size() - 1])
                {
                    return true;
                }
            }
            if (check == "4")
            {
                if (input.move == check && input == buffer[buffer.size() - 1])
                {
                    return true;
                }
            }
            if (check == "6")
            {
                if (input.move == check && input == buffer[buffer.size() - 1])
                {
                    return true;
                }
            }
        }
        return false;
    }
};

class Controller : public ge211::Abstract_game
{
public:
    explicit Controller(Player p1, Player p2);

protected:
    void draw(ge211::Sprite_set&) override;
    ge211::Dimensions initial_window_dimensions() const override;
    std::string initial_window_title() const override;
    void on_key_down(ge211::Key) override;
    void on_key_up(ge211::Key) override;
    void on_frame(double dt) override;

private:
    Model model_;
    View view_;
    Input_buffer p1_buffer;
    Input_buffer p2_buffer;
    bool t;
    bool q;
    bool w;
    bool e;
    bool comma;
    bool period;
    bool slash;
};