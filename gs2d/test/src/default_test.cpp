#include "gtest/gtest.h"

#include <SFML/Graphics.hpp>
#include "gs2d_engine/time.hpp"

TEST(DefaultTest, simple_test){
    gs::TimeHandler th(sf::seconds(1));
    EXPECT_EQ(1 + 1, 2);
}
