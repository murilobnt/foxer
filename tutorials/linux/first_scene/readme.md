# Tutorial - Coding the first scene

Time has come to code the first scene. This is what we're going to
do this tutorial.

   * What can we do with a scene?
   * Let's code the SFML example!

## What can we do with a scene?

Alright, basically, here's what we can do with a scene. We **need** to:

   * set it up;
   * do something in 1/FPS second;
   * handle an event;
   * draw everything we want.

In other words, your scene class need to inherit from Scene. So, these are
the methods you need to code.

   ```
   void start();
   void update();
   void handle_event(sf::Event event, sf::RenderWindow& screen);
   void draw_entities(sf::RenderWindow& screen);
   ```

There are some other things we **can**, such as:

   * free allocated stuff;
   * reset some time handlers;
   * define what to do when the scene is changed;
   * change to another scene.

The last one is the icing on the cake. In other words...

   ```
   ~Scene();
   void reset_time_handlers(ClockHandler& clock_handler);
   void on_exit();
   ```

You don't have to implement the scene changing. You can call it by doing the following call, anywhere your code.

   ```
   change_scene(SceneChanger::create_scene(new <scene>, scene_manager));
   ```

Here, I'm using SceneChanger too. The reason I use it is to make possible to not force you to code a constructor (with a pointer to a scene_manager) to your scene.

## Let's code the SFML example!

Enough talking. It's coding time! Remember we coded **main.cpp** in the last tutorial? This time, we'll start with our scene class header. Go to *your_project/include* and create a file called **my_scene.hpp**. This is what we'll be putting there.

```
#ifndef MY_SCENE_HPP
#define MY_SCENE_HPP

#include <SFML/Graphics.hpp>

#include "gs2d_engine/abstract/scene.hpp"

class MyScene : public Scene {

private:
   sf::CircleShape circle;

public:
   void start();
   void update();

   void handle_event(sf::Event event, sf::RenderWindow& screen);
   void draw_entities(sf::RenderWindow& screen);

};

#endif
```

We're done with the header. Now, to the code itself, go to *your_project/src* and create a file named **my_scene.cpp**. This is what it will have.

```
#include "my_scene.hpp"

void MyScene::start(){
   circle = sf::CircleShape(100.f);
   circle.setFillColor(sf::Color::Green);
}
void MyScene::update(){
   // we'll do nothing over here
}

void MyScene::handle_event(sf::Event event, sf::RenderWindow& screen){
   // also nothing over here
}
void MyScene::draw_entities(sf::RenderWindow& screen){
   screen.draw(circle);
}
```

We're done here. Next tutorial, we'll execute it :D.

# Where do we go from here?

#### [Next: Executing the project](/tutorials/linux/executing)

#### [Table of Contents / Home](https://github.com/murilobnt/gs2d_engine#tutorial)
