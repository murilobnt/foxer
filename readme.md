# Game Simple

<p align="center">
<img src ="./images/lion_baby_png_photo.png" width=200>
</p>

## Introduction

**Game Simple** aims to be a framework on creating 2D games using SFML on the C++ programming language.
Most of the classes here are reused from my another project, [vulnus](https://github.com/murilobnt/vulnus),
which is a 2D platform game in development.

## Features and TO DOs

- [x] Reuse vulnus' classes;
- [x] Bring inside, immutable, operations up;
- [x] Implement the [SFML example](https://www.sfml-dev.org/tutorials/2.4/start-linux.php#compiling-a-sfml-program) using the framework;
- [x] Get rid of enums;
- [x] Ease the development of animations;
- [x] Documment .hpp files;
- [ ] Documment the .hpp files of the instance (wish me luck lol);
- [ ] Implement classes to ease the development of platform and classic RPG games (like Final Fantasy).

## How it works

### The Game class

The first component you need to create for your game is a game object. The game object will be responsible for keeping the game cycle:
* Start the game;
* Handle actions in the game frequency;
* Process the events;
* Draw the content of every cycle.

The game class uses a SceneManager for the above actions, and will be explained next.

### The SceneManager class

This class is responsible for knowing what is the current scene you are at. It "translates" the game cycle position and tells what the current scene needs to do. There isn't much to be explained more than it will be delegating orders to the scene.

### The Scene abstract class

This is the most important part: The Scene abstract class. It will be used for creating the scenes of your game. All you need to do is to include it (gamesimple/abstract/scene.hpp) and to extend from it (class MyScene : public Scene). These are the methods you will be needing to implement:

* **void start()** will be the first thing your scene will do;
* **void update()** will be what the scene will do during the 1/FPS seconds;
* **void handleEvent(sf::Event event, sf::RenderWindow &screen)** will be how your scene will react to that event;
* **void drawEntities(sf::RenderWindow &window)** will be the drawing of your entities on the game window;
* **void doInternalTimedActions()** will be about timed actions (using the class TimeHandler is strongly recommended);
* **void resetTimeHandlers(ClockHandler &clockHandler)** will be to reset all the time handlers of the scene;
* **void onExit()** will be what the scene will do when changed;
* **void resumeScene()** will be to resume scene on some point (like enemies).

### The classes in gamesimple/components

All the classes in gamesimple/components can be used to ease the development of a game.

* **SpritedEntity** can be extended by an entity that needs a sprite;
* **AnimatedEntity** can be extended by an entity with an animated sprite;
* **FileReader** can be implemented by an entity that reads a file;
* **ControlableEntity** can be implemented by an entity that can be controled by an input;
* **MouseControl** can be implemented by an entity that wants to handle clicks in the game window.

## Run the example

### Requisites
I don't use Windows OS for development. This guide will help you to compile the test on Linux (Ubuntu distro).

You will need:

* SFML;
* GCC compiler (g++).

To get the latest SFML library:
```
sudo apt install libsfml-dev
```

To get the GCC compiler (g++):
```
sudo apt install g++
```

### Compiling
To run this project, you will may want to compile it first. To do so, go to the root of the project folder via terminal and run the following:
```
make
```

And then, to execute it, you need to be at the **root of the project folder**. Then, run the following:
```
./bin/gamesimpleapp
```

## Author

[Murilo Bento](https://github.com/murilobnt)
(mourilob@gmail.com)
