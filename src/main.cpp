#include <graphics.h>

#include "color.h"
#include "vector_2.h"

const int WIDTH = 1280;
const int HEIGHT = 960;

int main() {
  genv::gout.open(WIDTH, HEIGHT);

  genv::event evt;
  while (genv::gin >> evt) {
    if (evt.type == genv::ev_key) {
      if (evt.keycode == genv::key_escape) {
        return 0;
      }
    }

    Color(255, 255, 0).apply();
    Vector2(0, 0).rect_to_abs({100, 100});

    genv::gout << genv::refresh;
  }

  return 1;
}
