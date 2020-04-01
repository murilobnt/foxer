#include <foxer/app.hpp>

#include "my_scene.hpp"
#include <X11/Xlib.h>

int main() {
  XInitThreads();
  fox::App app(960, 640, "Foxer Game Sample");
  app.app_start(new MyScene(), true, true);
}
