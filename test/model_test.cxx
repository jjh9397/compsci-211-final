#include "model.hxx"
#include <catch.hxx>


struct Test_access
{
    Model& model ;

    Rectangle& rect1()
    { return model.player1_.body}

    Rectangle& rect2()
    { return model.player2_.body}

    int& health1()
    { return model.player1_.health}
};

TEST_CASE("hit each other at same time")
{
    Player p1={10,10,10,0};
    Player p2={10,10,20,0};
    model m(p1,p2);
    m.p1_attack();
    m.p2_attack();
    CHECK(check_p1_health()==check_p2_health());
}

TEST_CASE("block in corner")
{
    Player p1={10,10,0,0};
    Player p2={10,10,20,0};
    model m(p1,p2);
    m.p1_block();
    m.p2_attack();
    Test_access t{m};
    CHECK(t.rect1().x==0);
}

TEST_CASE("collide with player")
{
    Player p1={10,10,10,0};
    Player p2={10,10,20,0};
    model m(p1,p2);
    m.set_p1_velocity({10,0});
    p1=p1.next();
    Test_access t{m};
    CHECK(t.rect1().x==10);
}

TEST_CASE("wall collision")
{
    Player p1={10,10,10,0};
    Player p2={10,10,20,0};
    model m(p1,p2);
    m.set_p1_velocity({-10,0});
    p1=p1.next();
    Test_access t{m};
    CHECK(t.rect1().x==10);
}

TEST_CASE("game over")
{
    Player p1={10,10,10,0};
    Player p2={10,10,20,0};
    model m(p1,p2);
    CHECK(!m.health_check());
    Test_access t{m};
    t.health1()=0;
    CHECK(m.health_check());
    CHECK(t.rect1().x!=10);
}