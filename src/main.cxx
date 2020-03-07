#include "controller.hxx"

int main()
{
    Player p1({400,600},{20,20},{1,0});
    Player p2({900,600},{260,20},{-1,0});
    Model model(p1,p2,300,300);
    Controller(p1,p2).run();
}
