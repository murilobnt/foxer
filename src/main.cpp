#include <string>

#include "gamesimple/concrete/game.hpp"
#include "instance/testscene.hpp"

int main() {
  Game game(1366, 768, std::string("Tartaruga"));
  game.gameStart(new TestScene());
  return 0;
}
