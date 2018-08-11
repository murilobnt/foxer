#include <string>

#include "gamesimple/concrete/game.hpp"
#include "instance/testscene.hpp"

int main() {
        Game game(800, 600, std::string("Tartaruga"));
        game.game_start(new TestScene());
        return 0;
}
