#include "features/oled/print-wpm/print-wpm.h"

void process_print_wpm() {
    oled_set_cursor(0, 2);
    oled_write_P(PSTR("WPM: "), false);
    oled_write(get_u8_str(get_current_wpm(), '0'), false);
}
