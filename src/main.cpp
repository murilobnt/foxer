#include <string>

#include "gamesimple/concrete/game.hpp"
#include "instance/testscene.hpp"

int main() {
  Game game(200, 200, std::string("Tartaruga"));
  TestScene *initialScene = new TestScene(game.getSceneManager());
  game.gameStart(initialScene, true);
  return 0;
}
