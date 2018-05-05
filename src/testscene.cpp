#include "instance/testscene.hpp"

TestScene::~TestScene(){
    std::cout << "My destructor have been called. Yay!" << std::endl;
}

void TestScene::start() {
    timeHandlers.push_back(&character.getAnimationTimeHandler());

  TextureLoader::setTextureFromFile(
      this->charTexture, std::string("images/linkEdit.png"), 1200, 1040);
  character = Character(this->charTexture, 0, 0, 120, 130, 0, 1200, 520, 910, 20);
  character.setSpriteScale(0.4, 0.4);

  TextureLoader::setTextureFromFile(
      this->bgTexture, std::string("images/7536921_orig.png"), 1000, 750);
  bg = SpritedEntity(this->bgTexture, 0, 0, 1000, 750);

  character.setSpritePosition(sf::Vector2f(0, 0));
  bg.setSpritePosition(sf::Vector2f(0, 0));
}

void TestScene::update() { doInternalTimedActions(); character.moveCharacter(); }

void TestScene::handleEvent(sf::Event event, sf::RenderWindow &screen) {
  switch (event.type) {
  case sf::Event::KeyReleased:
    character.controlEntity(event.key.code, false);
    if(event.key.code == sf::Keyboard::Return){
        changeScene(new SecondScene(this->sceneManager));
    }
    break;
  case sf::Event::KeyPressed:
    character.controlEntity(event.key.code, true);
    break;
  }
}

void TestScene::drawEntities(sf::RenderWindow &window) {
  window.draw(bg.getSprite());
  window.draw(character.getSprite());
}

void TestScene::doInternalTimedActions() {
  while (character.getAnimationTimeHandler().timeToUpdate())
    character.animate();
}
