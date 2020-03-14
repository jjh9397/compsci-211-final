#include "controller.hxx"

int main()
{
    Player p1({400,470},{1,0});
    Player p2({900,470},{-1,0});
    Controller(p1,p2).run();
}
