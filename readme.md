# GS2D Engine

<img src="readme_assets/lion_baby_png_photo.png" width=15%>

## Introduction

**GS2D Engine** aims to be a game engine on creating 2D games using SFML on the C++ programming language. Most of the classes here are based on my another project, [vulnus](https://github.com/murilobnt/vulnus), which is a 2D platform game in development.

This tool will help you focus on the game. All you have to do is to create your own scenes and to set up the main method.

## Requires

-   [GCC](http://gcc.gnu.org).
-   [SFML](https://www.sfml-dev.org).
-   [CxxTest](https://cxxtest.com).

## Features and TO DOs

| Feature              | % Functional | % Documented | Seen in execution | Tested |
| -------------------- | ------------ | ------------ | ----------------- | ------ |
| Game cycle control   | 100%         | 100%         | Yes               | **No** |
| Makefile             | 100%         | 60%          | Yes               | ------ |
| Timed events control | 95%          | 100%         | Yes               | **No** |
| Scene handling       | 90%          | 100%         | Yes               | **No** |
| Game entities        | 70%          | 100%         | Yes               | **No** |
| Default scenes       | 30%          | 0%           | Yes               | **No** |
| Game components      | 10%          | 0%           | No                | **No** |
| Scene transitions    | 0%           | 0%           | No                | **No** |
| Tutorial             | 0%           | ------       | ------            | ------ |

## Compile

### Engine

To compile the engine to a static library,
go to the root of the project:

```
make
```

### Example

To compile and execute the example, go to *example/instance*:

```
make
./bin/example
```

## How it works

### The Game class

The first component you need to create for your game is a game object. The game object will be responsible for keeping the game cycle:

-   Start the game;
-   Handle actions in the game frequency;
-   Process the events;
-   Draw the content of every cycle.

The game class uses a SceneManager for the above actions, and will be explained next.

### The SceneManager class

This class is responsible for knowing what is the current scene you are at. It "translates" the game cycle stage and tells what the current scene needs to do. There isn't much to be explained more than it will be delegating orders to its scene.

### The Scene abstract class

This is the most important part: The Scene abstract class. It will be used for creating the scenes of your game. All you need to do is to include it (gamesimple/abstract/scene.hpp) and to extend from it (class MyScene : public Scene). These are the methods you will be needing to implement:

-   **void start()** will be the first thing your scene will do;
-   **void update()** will be what the scene will do during the 1/FPS seconds;
-   **void handle_event(sf::Event event, sf::RenderWindow &screen)** will be how your scene will react to that event;
-   **void draw_entities(sf::RenderWindow &window)** will be the drawing of your entities on the game window;

A few methods can be overriden:

-   **void reset_time_handlers(ClockHandler &clock_handler)** will be to reset all the time handlers of the scene. By default, the scene uses the vector of time handlers called time_handlers to reset them "automatically". You need to add the time handlers, to the vector, at the start method, for it to work.
-   **void on_exit()** will be what the scene will do when changed. It does nothing by default.

### Components

Some components can be used to ease the development of a game.

-   **SpritedEntity** can be extended by an entity that needs a sprite;
-   **AnimatedEntity** can be extended by an entity with an animated sprite;
-   **FileReader** can be implemented by an entity that reads a file;
-   **EBControlableEntity** can be implemented by an entity that can be controled by an event;
-   **ib_controlable_entity.hpp** can be implemented by an entity that can be controled by an input;
-   **MouseControl** can be implemented by an entity that wants to handle clicks in the game window.

## Note

All lion pictures used by this readme were downloaded from <http://pngimagesfree.com>.

## Development team

[<img src="https://avatars1.githubusercontent.com/u/6081758?s=400&v=4" width="100"/>](https://github.com/murilobnt)

[Murilo Bento](https://github.com/murilobnt)
