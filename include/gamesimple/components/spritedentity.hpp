#ifndef _SPRITEDENTITY_HPP_
#define _SPRITEDENTITY_HPP_

#include <SFML/Graphics.hpp>

// Sprited entities are entities that have a sprite.
// This is useful to encapsulate all operations over
// a sprite of an entity without having to get its member
// sprite.

class SpritedEntity {
private:
  // The sprite of the entity.
  sf::Sprite sprite;

  // The dimensions of the entity. This is a two-dimensional
  // vector of int which contains, respectively, the width and
  // the height of the sprite.
  sf::Vector2i spriteDimensions;

public:
  // Constructor. It takes the texture, the X and Y positions,
  // and the width and height of this sprite.
  SpritedEntity(sf::Texture const &texture, int spriteX, int spriteY,
                int spriteW = 32, int spriteH = 32);

  // Empty constructor. This is important so the user of the
  // animated sprite can choose to initialize it later (but it's
  // important to not forget to do so).
  SpritedEntity();

  // Configure the rect of the sprite, so it can turn into another
  // one in its texture. This method also requires the width and
  // height of the new sprite, in case of different dimensions.
  void configureSpriteRect(int x, int y, int w, int h);

  // Configure the rect of the sprite, so it can turn into another
  // one in its texture. This method uses the current width and
  // height of the sprite to load the next one. Useful with animation
  // and standardized dimensions.
  void configureSpriteRect(int x, int y);

  // Set the position of the sprite to the position of the
  // given two-dimensional float vector.
  void setSpritePosition(sf::Vector2f position);

  // Set the position of the sprite to the position of the
  // given X and Y coordinates.
  void setSpritePosition(float x, float y);

  // Scale the sprite in the X and Y axis.
  void setSpriteScale(float x, float y);

  // Move the sprite. This method adds the current position
  // of the sprite to the given two-dimensional vector.
  void moveSprite(sf::Vector2f movement);

  // Set the color of the sprite to the given color.
  void setSpriteColor(sf::Color color);

  sf::Sprite getSprite() const;
  sf::Vector2f getSpritePosition() const;
  sf::Vector2i getSpriteDimensions() const;
  sf::FloatRect getSpriteGlobalBounds() const;
  sf::FloatRect getSpriteLocalBounds() const;
};

#endif
