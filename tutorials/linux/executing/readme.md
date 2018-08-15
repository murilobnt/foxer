# Tutorial - Executing the project

Yes! We're finally here. Let's see the project in action.

But, uhhh. Yeah, you know. First:

   * Let's fix our main method.
   * Let's compile the engine.
   * Let's execute it!
   * The magic of Makefile.

## Let's fix our main method

First, we gotta fix our **main.cpp**. Remember that commented line? Time to change
it.

This is how your file gotta be.

```
#include "gs2d_engine/concrete/game.hpp"
#include "my_scene.hpp"

int main(){
   Game game(800, 600, "MyApp");
   game.game_start(new MyScene());
}
```

## Let's compile the engine

So, for it to work, we need the engine to be compiled first. It's no hard work to make this happen, though.

Go to the root of the project, through terminal, and do the following command.

```
make
```

Some messages may show up, but if they start with "g++" or "ar", it's all fine. This is what it may look like.

<p align="center"><img src="assets/ss1.png"></p>

All cool?

## Let's execute it!

Time has come! Go to *your_project*, the root of it, via terminal still, and, once again:

```
make
```

This is how it may go like.

<p align="center"><img src="assets/ss2.png"></p>

No errors? Neat! Now we just gotta execute it by:

```
./bin/your_app
```

This is the result.

<p align="center"><img src="assets/ss3.png" width=50%></p>

... Tada!

## The magic of Makefile

This is what the Makefile I've put into *your_project* is doing:

   - It compiles your source code (under *src*) into objects.
   - It links these objects with the gs2d.a static library under *gs2d/lib* and create the executable.

That's all I've got for now! Thanks for reading this tutorial. I'm going to write more in the future! :D

# Thank you!

#### [Table of Contents / Home](https://github.com/murilobnt/gs2d_engine#tutorial)
