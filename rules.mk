BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes        # Mouse keys
EXTRAKEY_ENABLE = yes        # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
RGBLIGHT_ENABLE = yes        # Enable WS2812 RGB underlight.
SWAP_HANDS_ENABLE = no      # Enable one-hand typing
OLED_ENABLE = yes     		# OLED display
WPM_ENABLE = yes			# Words per minute, necesario para luna dog
LTO_ENABLE = yes				# Link time optimization, aumenta compile time pero disminuye el size del build final
SPLIT_KEYBOARD = yes
SPLIT_WPM_ENABLE = no
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c
TAP_DANCE_ENABLE=no

SRC +=	\
		./features/oled/caps/caps.c \
		./features/oled/numlock/numlock.c \
		./features/rgb/underlight/set-color-per-layer.c \
		./features/oled/luna-keyboard-dog/luna.c \
		./features/oled/print-layer/print-layer.c \
		./features/oled/print-wpm/print-wpm.c \
