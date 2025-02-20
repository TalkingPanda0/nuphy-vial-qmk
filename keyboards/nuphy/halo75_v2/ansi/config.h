/*
Copyright 2023 @ Nuphy <https://nuphy.com/>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

#define RGB_MATRIX_LED_FLUSH_LIMIT 32

#define DYNAMIC_KEYMAP_MACRO_DELAY 8
// This is the size of the EEPROM for the custom VIA-specific data
#define EECONFIG_USER_DATA_SIZE 12

#define DEV_MODE_PIN C0
#define SYS_MODE_PIN C1
#define DC_BOOST_PIN C2
#define NRF_RESET_PIN B4
#define NRF_TEST_PIN B5
#define NRF_BOOT_PIN B5
#define NRF_WAKEUP_PIN C4

// Shutdown pins for both drivers
#define RGB_DRIVER_SDB1 C6
#define RGB_DRIVER_SDB2 C7

#define SERIAL_DRIVER SD1
#define SD1_TX_PIN B6
#define SD1_TX_PAL_MODE 0
#define SD1_RX_PIN B7
#define SD1_RX_PAL_MODE 0

// This is a 7-bit address, that gets left-shifted and bit 0
// set to 0 for write, 1 for read (as per I2C protocol)
// The address will vary depending on your wiring:
// 0b1110100 AD <-> GND
// 0b1110111 AD <-> VCC
// 0b1110101 AD <-> SCL
// 0b1110110 AD <-> SDA
#define DRIVER_ADDR_1 0b1010000
#define DRIVER_ADDR_2 0b1010011

#define ISSI_TIMEOUT 1

/* I2C Alternate function settings */
#define I2C_DRIVER I2CD1
#define I2C1_SCL_PIN B8
#define I2C1_SDA_PIN B9
#define I2C1_CLOCK_SPEED 1000000

#define I2C1_SCL_PAL_MODE 1
#define I2C1_SDA_PAL_MODE 1

#define I2C1_TIMINGR_PRESC 0U
#define I2C1_TIMINGR_SCLDEL 0U
#define I2C1_TIMINGR_SDADEL 0U
#define I2C1_TIMINGR_SCLH 0U
#define I2C1_TIMINGR_SCLL 0U
#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_16_9

#define DRIVER_COUNT 2
#define DRIVER_1_LED_TOTAL 64
#define DRIVER_2_LED_TOTAL 64
#define RGB_MATRIX_LED_COUNT (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)

#define RGB_MATRIX_SLEEP // turn off effects when suspended

// USB sleep workaround :D
#ifdef USB_SUSPEND_WAKEUP_DELAY
#    undef USB_SUSPEND_WAKEUP_DELAY
#endif
#define USB_SUSPEND_WAKEUP_DELAY 50

#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_KEYRELEASES
#define SLEEP_TIMEOUT_STEP 1

#define IS31FL3733_SW_PULLUP PUR_05KR
#define IS31FL3733_CS_PULLDOWN PUR_05KR

#define WAIT_US_TIMER GPTD14

#define RELEASE_DEBOUNCE (DEBOUNCE)

#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define RGB_DEFAULT_COLOR 168

#define USB_POLLING_INTERVAL_MS 1
