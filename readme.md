<h1 align="center"> GS2D Engine </h1>

<p align="center"><img src="readme_assets/lion_psd_image_free.png" width=30%></p>

## Introduction

**GS2D Engine** aims to be a game engine for creating 2D games using SFML on the C++ programming language. Most of the classes here are based on my another project, [vulnus](https://github.com/murilobnt/vulnus), which is a 2D platform game in development.

This tool will help you focus on the game. All you have to do is to create your own scenes and to set up the main method.

> Note: All lion pictures used by this readme were downloaded from <http://pngimagesfree.com>.

## Requires

-   [GCC](http://gcc.gnu.org).
-   [SFML](https://www.sfml-dev.org).
-   [CxxTest](https://cxxtest.com).

## Tutorial

You can check the tutorial by clicking one of the topics below (only available for linux at the moment).

<h3 align="center"> The base </h3>

<h4 align="center"> 1. <a href="/tutorials/linux/start"> Where the heck do I start? </h4>
<h4 align="center"> 2. [Understanding some concepts](/tutorials/linux/understanding) </h4>
<h4 align="center"> 3. [The first step](/tutorials/linux/first_step) </h4>
<h4 align="center"> 4. [Coding the first scene](/tutorials/linux/first_scene) </h4>
<h4 align="center"> 5. [Executing the project](/tutorials/linux/executing) </h4>

<h3 align="center"> The deepening </h3>

<h4 align="center"> 6. [Time handling](/tutorials/linux/time) </h4>

## Features and TO-DOs

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

## Development team

[<img src="https://avatars1.githubusercontent.com/u/6081758?s=400&v=4" width="100"/>](https://github.com/murilobnt)

[Murilo Bento](https://github.com/murilobnt)
