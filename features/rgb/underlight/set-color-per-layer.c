#include "features/rgb/underlight/set-color-per-layer.h"

void process_set_color_per_layer() {
    static uint8_t old_layer = 255;
    uint8_t new_layer = biton32(layer_state);

    if (old_layer != new_layer) {
        switch (new_layer) {
          case 0:
            rgblight_sethsv(HSV_WHITE);
            break;
          case 1:
            rgblight_sethsv(HSV_GREEN);
            break;
          case 2:
            rgblight_sethsv(HSV_BLUE);
            break;
          case 3:
            rgblight_sethsv(HSV_RED);
            break;
        }
        old_layer = new_layer;
    }
}




