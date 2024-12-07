SRC += rf.c sleep.c rf_driver.c mcu_pwr.c rf_queue.c user_kb.c debounce.c matrix.c
LTO_ENABLE = yes
CUSTOM_MATRIX = lite

UART_DRIVER_REQUIRED = yes
RGB_MATRIX_CUSTOM_KB = yes

SLEEP_LED_ENABLE = no

SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no

