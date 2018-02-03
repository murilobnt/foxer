#ifndef _ANIMATEDENTITY_HPP_
#define _ANIMATEDENTITY_HPP_

class AnimatedEntity {
private:
  int spriteInitX;
  int spriteEndX;
  int spriteInitY;
  int spriteEndY;

protected:
  int animationLoopState;

public:
  AnimatedEntity(int spriteInitX, int spriteEndX, int spriteInitY,
                 int spriteEndY);

  AnimatedEntity();
  int getSpriteInitX() const;
  int getSpriteEndX() const;
  int getSpriteInitY() const;
  int getSpriteEndY() const;
  virtual void animate() = 0;
};

#endif
