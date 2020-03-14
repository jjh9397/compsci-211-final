#include "model.hxx"
#include <catch.hxx>

TEST_CASE("Tie")
{
    Player p1({400,470},{1,0});
    Player p2({900,470},{-1,0});
    Model model(p1,p2);
    model.p1_move({300,0});
    model.p2_move({-150,0});
    model.update(1);
    model.p1_move({0,0});
    model.p2_move({0,0});
    model.update(1);
    size_t i=0;
    while (i<20)
    {
        model.p1_attack();
        model.access_p1_recovery()=0;
        i++;
    }
    model.p1_stop_attack();
    model.update(1);
    i=0;
    while (i<20)
    {
        model.p2_attack();
        model.access_p2_recovery()=0;
        i++;
    }
    model.update(1);
    CHECK(model.get_p1_health()==0);
    CHECK(model.get_p2_health()==0);

}

TEST_CASE("hit at same time")
{
    Player p1({400,470},{1,0});
    Player p2({900,470},{-1,0});
    Model model(p1,p2);
    model.p1_move({300,0});
    model.p2_move({-150,0});
    model.update(1);
    model.p1_move({0,0});
    model.p2_move({0,0});
    model.update(1);
    model.p1_attack();
    model.p1_stop_attack();
    model.p2_attack();
    model.update(1);
    CHECK(model.get_p1_health()==95);
    CHECK(model.get_p2_health()==95);
}

TEST_CASE("p2 ground attack win")
{
    Player p1({400,470},{1,0});
    Player p2({900,470},{-1,0});
    Model model(p1,p2);
    model.p1_move({300,0});
    model.p2_move({-150,0});
    model.update(1);
    model.p1_move({0,0});
    model.p2_move({0,0});
    model.update(1);
    size_t i=0;
    while (i<20)
    {
        model.p2_attack();
        model.access_p2_recovery()=0;
        i++;
    }
    model.update(1);
    CHECK(model.get_p1_health()==0);
    CHECK(model.get_p2_health()==100);

}

TEST_CASE("p1 jump attack win")
{
    Player p1({400,470},{1,0});
    Player p2({900,470},{-1,0});
    Model model(p1,p2);
    model.p1_move({300,10});
    model.p2_move({-150,0});
    model.update(1);
    model.p1_move({0,0});
    model.p2_move({0,0});
    model.update(1);
    size_t i=0;
    while (i<10)
    {
        model.p1_jump();
        model.p1_attack_1_air();
        model.access_p1_recovery()=0;
        i++;
    }
    model.update(1);
    CHECK(model.get_p1_health()==100);
    CHECK(model.get_p2_health()==0);
}

TEST_CASE("mix p1 win and break block")
{
    Player p1({400,470},{1,0});
    Player p2({900,470},{-1,0});
    Model model(p1,p2);
    model.p1_move({300,0});
    model.p2_move({-150,0});
    model.update(1);
    model.p1_move({0,0});
    model.p2_move({0,0});
    model.update(1);
    size_t i=0;
    while (i<10)
    {
        model.p1_attack();
        model.access_p1_recovery()=0;
        model.p1_stop_attack();
        model.p2_attack();
        model.access_p2_recovery()=0;
        model.p2_stop_attack();
        i++;
    }
    model.update(1);
    i=0;
    model.p2_block();
    model.p1_move({0,10});
    while(i<5)
    {
        model.p1_jump();
        model.p1_attack_1_air();
        model.access_p1_recovery()=0;
        i++;
    }
    model.update(1);
    CHECK(model.get_p1_health()==50);
    CHECK(model.get_p2_health()==0);
}

TEST_CASE("block working")
{
    Player p1({400,470},{1,0});
    Player p2({900,470},{-1,0});
    Model model(p1,p2);
    model.p1_move({300,0});
    model.p2_move({-150,0});
    model.update(1);
    model.p1_move({0,0});
    model.p2_move({0,0});
    model.update(1);
    model.p1_attack();
    model.access_p1_recovery()=0;
    model.update(1);
    model.p2_block();
    model.update(1);
    model.p1_attack();
    model.update(1);
    CHECK(model.get_p2_health()==95);
}

TEST_CASE("recovery working")
{
    Player p1({400,470},{1,0});
    Player p2({900,470},{-1,0});
    Model model(p1,p2);
    model.p1_move({300,0});
    model.p2_move({-150,0});
    model.update(1);
    model.p1_move({0,0});
    model.p2_move({0,0});
    model.update(1);
    model.p1_attack();
    model.update(1);
    model.p1_attack();
    model.update(1);
    CHECK(model.get_p2_health()==95);
}

TEST_CASE("attack misses")
{
    Player p1({400,470},{1,0});
    Player p2({900,470},{-1,0});
    Model model(p1,p2);
    model.p1_attack();
    model.p2_attack();
    CHECK(model.get_p1_health()==100);
    CHECK(model.get_p2_health()==100);
}