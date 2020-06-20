#include <foxer/app.hpp>

#include "textbox_test_scene.hpp"
#include "my_scene.hpp"
#include <X11/Xlib.h>

int main() {
  XInitThreads();
  fox::App app(400, 300, "Foxer Game Sample");
  app.app_start(new TextBoxTestScene(), false, true);
}
