# Tutorial - The first step

So, here we are. This is the first tutorial about the project itself.
Finally, huh?

In this tutorial, we'll be starting your project.
You might be expectating this already, so there are some things we need to know first.

   * The Game object: What does it do?
   * The Game object: What is it missing?

## The Game object: What does it do?

If you've read the SFML tutorial, you might have run into something like:

```
int main(){
   // create the game window.
   // create entities.

   while (window.isOpen()) {

      // handle events

      // do stuff like character movement

      window.clear();

      // draw entities

      window.display();

   }   
}
```

And it works pretty well! I've, basically, done an university project with only this.
But... can it be more simple, so I can focus on the game? This' the thought what made me code this project.

The game object is responsible for providing a structure to handle the game's processing cycle. Framerate, which is something you might take some time to apply to your project, is a simple argument you pass through its constructor.

So, now, let's create our main. At the root of the project, go to *your_project/src* and create a file called **main.cpp**. This is what you'll put in there.

```
#include "gs2d_engine/concrete/game.hpp"

int main(){
   Game game(800, 600, "MyApp");
   //game.game_start();
}
```

Have you noticed the "game.game_start()" is commented? That's because there's
something missing.

## The Game object: What is it missing?

Since Game controls the game cycle, it can't be responsible for what the
game itself (entities, event handling, entities drawing, etc.) does, so we need
something else to do those things. This something else is called **Scene**.

That's what is missing to our main. We need a starting scene to our game.
And that's what we'll be doing in the next tutorial.

# Where do we go from here?

#### [Next: Coding the first scene](/tutorials/linux/first_scene)

#### [Table of Contents / Home](https://github.com/murilobnt/gs2d_engine#tutorial)
