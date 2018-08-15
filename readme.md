# GS2D Engine

<p align="center"><img src="readme_assets/lion_baby_png_photo.png" width=30%></p>

## Introduction

**GS2D Engine** aims to be a game engine on creating 2D games using SFML on the C++ programming language. Most of the classes here are based on my another project, [vulnus](https://github.com/murilobnt/vulnus), which is a 2D platform game in development.

This tool will help you focus on the game. All you have to do is to create your own scenes and to set up the main method.

## Requires

-   [GCC](http://gcc.gnu.org).
-   [SFML](https://www.sfml-dev.org).
-   [CxxTest](https://cxxtest.com).

## Tutorial

You can check the tutorial by clicking one of the topics below (only available for linux at the moment).

#### 1. [Where the heck do I start?](/tutorials/linux/start)
#### 2. [Understanding some concepts](/tutorials/linux/understanding)
#### 3. [The first step](/tutorials/linux/first_step)
#### 4. [Coding the first scene](/tutorials/linux/first_scene)
#### 5. [Executing the project](/tutorials/linux/executing)

## Features and TO DOs

| Feature              | % Functional | % Documented | Seen in execution | Tested |
| -------------------- | ------------ | ------------ | ----------------- | ------ |
| Game cycle control   | 100%         | 100%         | Yes               | **No** |
| Makefile             | 100%         | 60%          | Yes               | ------ |
| Timed events control | 95%          | 100%         | Yes               | **No** |
| Scene handling       | 90%          | 100%         | Yes               | **No** |
| Game entities        | 70%          | 100%         | Yes               | **No** |
| Tutorial             | 40%          | ------       | ------            | ------ |
| Default scenes       | 30%          | 0%           | Yes               | **No** |
| Game components      | 10%          | 0%           | No                | **No** |
| Scene transitions    | 0%           | 0%           | No                | **No** |

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

## Note

All lion pictures used by this readme were downloaded from <http://pngimagesfree.com>.

## Development team

[<img src="https://avatars1.githubusercontent.com/u/6081758?s=400&v=4" width="100"/>](https://github.com/murilobnt)

[Murilo Bento](https://github.com/murilobnt)
