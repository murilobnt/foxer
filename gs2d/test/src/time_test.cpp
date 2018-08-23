#include "gtest/gtest.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include "gs2d_engine/time.hpp"

class TimeTest : public ::testing::Test {
protected:
    gs::ClockHandler ch;
    gs::TimeHandler th;

    virtual void SetUp(){
        th = gs::TimeHandler(sf::seconds(3));
    }

    virtual void TearDown(){

    }
};

TEST_F(TimeTest, constructor_test) {
    EXPECT_EQ(th.get_update_rate().asSeconds(), 3);
}

TEST_F(TimeTest, restart_test) {
    sf::Time before_restart = th.get_last_update();
    sf::Time elapsed_time = ch.get_elapsed_time();

    ch.restart_time_handler(&th);

    sf::Time after_restart = th.get_last_update();
    EXPECT_EQ(after_restart.asMilliseconds(), (elapsed_time + before_restart).asMilliseconds());
}

TEST_F(TimeTest, time_to_update_test){
    EXPECT_NE(th.time_to_update(), true);

    sf::Time current;
    do{
        ch.restart_clock();
        current += ch.get_elapsed_time();
        ch.restart_time_handler(&th);
    } while (current.asSeconds() <= sf::seconds(3).asSeconds());

    EXPECT_EQ(th.time_to_update(), true);
}

TEST_F(TimeTest, reset_last_update_test){
    th.reset_last_update();
    EXPECT_EQ(th.get_last_update(), sf::Time::Zero);
}

TEST_F(TimeTest, set_update_rate_test){
    sf::Time current;
    do{
        ch.restart_clock();
        current += ch.get_elapsed_time();
        ch.restart_time_handler(&th);
    } while (current.asSeconds() <= sf::seconds(2).asSeconds());

    float first_proportion = th.get_last_update() / th.get_update_rate();
    th.set_update_rate(sf::seconds(5));
    float second_proportion = th.get_last_update() / th.get_update_rate();

    EXPECT_EQ(first_proportion, second_proportion);
    EXPECT_EQ(th.get_update_rate().asSeconds(), 5);
}
