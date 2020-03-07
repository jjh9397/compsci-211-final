#pragma once
#include "model.hxx"
#include "view.hxx"

class Controller : public ge211::Abstract_game
{
public:
    explicit Controller(Player p1, Player p2);

protected:
    void draw(ge211::Sprite_set&) override;
    ge211::Dimensions initial_window_dimensions() const override;
    std::string initial_window_title() const override;
    //void on_mouse_move(ge211::Position) override;
    //void on_mouse_up(ge211::Mouse_button, ge211::Position) override;
    void on_key_down(ge211::Key) override;
    void on_key_up(ge211::Key) override;
//    void on_frame(double dt) override;

private:
    Model model_;
    View view_;
};