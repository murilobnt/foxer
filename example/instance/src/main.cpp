#include <string>

#include "gs2d_engine/core.hpp"
#include "menu_example.hpp"

int main() {
        gs::App app(800, 600, "Tartaruga");
        app.app_start(new MenuExample());
        return 0;
}
