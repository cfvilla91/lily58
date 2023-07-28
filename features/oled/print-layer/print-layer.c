#include "features/oled/print-layer/print-layer.h"

void process_print_layer() {
    oled_set_cursor(0, 0);
    oled_write("Layer", false);
    oled_set_cursor(0, 1);
    switch(biton32(layer_state)){
        case 0:
            oled_write("BASE ", false);
            break;
        case 1:
            oled_write("LOWER", false);
            break;
        case 2:
            oled_write("RAISE", false);
            break;
        case 3:
            oled_write("ADJST", false);
            break;
    }
}
