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

<h4 align="center">
<a href="/tutorials/linux/start">1. Where the heck do I start? </a>
</h4>

<h4 align="center">
<a href="/tutorials/linux/understanding">2. Understanding some concepts </a>
</h4>

<h4 align="center">
<a href="/tutorials/linux/first_step"> 3. The first step </a>
</h4>

<h4 align="center">
<a href="/tutorials/linux/first_scene"> 4. Coding the first scene </a>
</h4>

<h4 align="center">
<a href="/tutorials/linux/executing"> 5. Executing the project </a>
</h4>

<h3 align="center"> The deepening </h3>

<h4 align="center">
<a href="/tutorials/linux/time"> 6. Time handling </a>
</h4>

## Features and TO-DOs

<center>

<table align="center">

<tr>
<th>Feature</th>
<th>% Functional</th>
<th>% Documented</th>
<th>Seen in execution</th>
<th>Tested</th>
</tr>

<tr>
<td>Game cycle control</td>
<td>100%</td>
<td>100%</td>
<td>Yes</td>
<td>**No**</td>
</tr>

<tr>
<td>Makefile</td>
<td>100%</td>
<td>60%</td>
<td>Yes</td>
<td>------</td>
</tr>

<tr>
<td>Timed events control</td>
<td>95%</td>
<td>100%</td>
<td>Yes</td>
<td>**No**</td>
</tr>

<tr>
<td>Scene handling</td>
<td>90%</td>
<td>100%</td>
<td>Yes</td>
<td>**No**</td>
</tr>

<tr>
<td>Game entities</td>
<td>70%</td>
<td>100%</td>
<td>Yes</td>
<td>**No**</td>
</tr>

<tr>
<td>Tutorial</td>
<td>50%</td>
<td>------</td>
<td>------</td>
<td>------</td>
</tr>

<tr>
<td>Default scenes</td>
<td>30%</td>
<td>0%</td>
<td>Yes</td>
<td>**No**</td>
</tr>

<tr>
<td>Game components</td>
<td>10%</td>
<td>0%</td>
<td>No</td>
<td>**No**</td>
</tr>

<tr>
<td>Scene transitions</td>
<td>0%</td>
<td>0%</td>
<td>No</td>
<td>**No**</td>
</tr>

</table>
</center>

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
