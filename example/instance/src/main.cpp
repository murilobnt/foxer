#include <string>

#include "gs2d_engine/concrete/game.hpp"
#include "menu_example.hpp"

int main() {
        gs::Game game(800, 600, std::string("Tartaruga"));
        game.game_start(new MenuExample());
        return 0;
}
