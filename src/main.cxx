#include "controller.hxx"

int main()
{
    Player p1({400,470},{20,20},{1,0});
    Player p2({900,470},{260,20},{-1,0});
    Controller(p1,p2).run();
}
