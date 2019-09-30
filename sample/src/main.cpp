#include <foxer/core.hpp>

#include "my_scene.hpp"
#include <X11/Xlib.h>

int main() {
  XInitThreads();
  fox::App app(480, 320, "Foxer Game Sample");
  app.app_start(new MyScene(), false, false);
}
