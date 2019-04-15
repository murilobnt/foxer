#include "gs2d/core.hpp"
#include "my_scene.hpp"
#include <X11/Xlib.h>

int main() {
  XInitThreads();
  gs::App app(1366, 768, "Sample SFML");
  app.app_start(new MyScene());
}
