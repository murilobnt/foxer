#include "gs2d/core.hpp"
#include "my_scene.hpp"

int main() {
  gs::App app(200, 200, "Sample SFML");
  app.app_start(new MyScene());
}
