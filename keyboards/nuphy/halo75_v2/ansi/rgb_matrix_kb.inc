// !!! DO NOT ADD #pragma once !!! //

RGB_MATRIX_EFFECT(show_bat_level)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#include "user_kb.h"
#include "ansi.h"

extern DEV_INFO_STRUCT dev_info;

#define NONE 127

const static uint8_t FIRST_DIGIT_INDEX[10] = {NONE,1,2,3,4,5,6,7,8,9};
const static uint8_t SECOND_DIGIT_INDEX[10] = {26,17,18,19,20,21,22,23,24,25};

uint32_t start_time;


static void show_bat_level_init(effect_params_t* params) {
    start_time = g_rgb_timer;
}

static bool show_bat_level_run(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    if((g_rgb_timer - start_time) > 5000){
        rgb_matrix_reload_from_eeprom();
    }

    rgb_matrix_set_color_all(0,0,0);

    HSV hsv = {dev_info.rf_battery,255,255};

    RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
    if(dev_info.rf_battery > 99){
        rgb_matrix_set_color_all(rgb.r,rgb.g,rgb.b);
    } else {

      rgb_matrix_set_color(FIRST_DIGIT_INDEX[dev_info.rf_battery / 10],rgb.r,rgb.g,rgb.b);
      rgb_matrix_set_color(SECOND_DIGIT_INDEX[dev_info.rf_battery % 10],rgb.r,rgb.g,rgb.b);
    }

    return rgb_matrix_check_finished_leds(led_max);
}
static bool show_bat_level(effect_params_t* params){
    if (params->init) show_bat_level_init(params);
    return show_bat_level_run(params);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
