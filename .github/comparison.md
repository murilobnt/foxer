# Comparison

This file will present comparisons of implementations of examples.

## Example 1

For **Example 1** it's required to:

- Draw a 32x32 sprite and position it at the center of the screen (point 400x 300y);
- Move the sprite to the left and to the right with the A and D keys, respectively;
- Animate the sprite when moving (1st row, columns 1 and 2 for right. 2nd row, columns 1 and 2 for left).

### Implementation 1 (without GS2D)

An implementation of **Example 1** was developed in a single, source file. This file only makes use of a main method.

### Implementation 2 (without GS2D)

Another implementation of **Example 1** has two classes: Game and Player.

### Implementation 3 (with GS2D)

The third implementation of **Example 1** has two classes: GameScene and Player.

### Results

| Implementation ID | Lines of Code | McCabe's Complexity Number     |
| ----------------- | ------------- | ------------------------------ |
| 1                 | 55            | Overall: 11, Per Module: 11    |
| 2                 | 99            | Overall: 13, Per Module: 1.444 |
| 3                 | 72            | Overall: 5, Per Module: 0.556  |

The results shows that **Implementation 3**'s McCabe's Complexity Number is **2.2 and 2.6 times lower than Implementation 1 and Implementation 2, respectively**.

About the lines of codes, **Implementation 1** shows the lowest number, followed by **Implementation 3** and **Implementation 2**.

### Verdict

**Implementation 1** feels faster and easier to do. It works as it is, but it **would be a nightmare to maintain and expand**.

**Implementation 2** feels the hardest. To carefully think what every class would contain and what should it be responsible to do was no easy task. I thought of making classes to act like the ones in the framework, but I gave up. **It would take a lot of time to implement and test everything to make it work**.

**Implementation 3** feels the mixed experience. You have an framework with a lot of "work done" for you, but now you gotta learn how to use it. However, it pays off: **Everything is organized and simple to expand, and the programmer don't need to worry about controlling the game cycle**.

### Gists of the implementations

- [Implementation 1](https://gist.github.com/murilobnt/e1e40a17df6cf7a83e308ff86b5aa739)
- [Implementation 2](https://gist.github.com/murilobnt/80ea16af536e169e3ae50fea4004cb2a)
- [Implementation 3](https://gist.github.com/murilobnt/d589f25365879338a6d76345141cb67c)
