#include "gtest/gtest.h"

#include <SFML/Graphics.hpp>
#include <string>
#include "gs2d/core.hpp"
#include "gs2d/scene.hpp"

class MyScene : public gs::Scene {

public:
bool gone_through_start;
bool gone_through_update;
bool gone_through_draw;

MyScene() :
        gone_through_start(false),
        gone_through_update(false),
        gone_through_draw(false) {
}

void start() {
        gone_through_start = true;
}

void update() {
        gone_through_update = true;
        app_window->close();
}

void draw_entities() {
        gone_through_draw = true;
}

};

class NextScene : public gs::Scene {

public:
    MyScene *my_scene;

explicit NextScene(MyScene *my_scene) {
    this->my_scene = my_scene;
}

void start() {
    change_scene(my_scene);
}

void update() {
}

void draw_entities() {
}

};

class AppTest : public ::testing::Test {
protected:
gs::App *game;
MyScene *my_scene;

virtual ~AppTest(){
    delete game;
}

virtual void SetUp(){
        my_scene = new MyScene();
        game = new gs::App(200, 200, "FFS");
}

virtual void TearDown(){
}
};

TEST_F(AppTest, getters_test){
        EXPECT_EQ(game->get_app_width(), 200);
        EXPECT_EQ(game->get_app_height(), 200);
}

TEST_F(AppTest, start_update_draw_test){
        EXPECT_EQ(my_scene->gone_through_start, false);
        EXPECT_EQ(my_scene->gone_through_update, false);
        EXPECT_EQ(my_scene->gone_through_draw, false);
        game->app_start(my_scene);
        EXPECT_EQ(my_scene->gone_through_start, true);
        EXPECT_EQ(my_scene->gone_through_update, true);
        EXPECT_EQ(my_scene->gone_through_draw, true);
}

TEST_F(AppTest, change_scene_test){
    NextScene* ns = new NextScene(my_scene);
    game->app_start(ns);
    EXPECT_EQ(my_scene->gone_through_start, true);
    EXPECT_EQ(my_scene->gone_through_update, true);
    EXPECT_EQ(my_scene->gone_through_draw, true);
}
