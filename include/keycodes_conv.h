#include "../include/keycodes.h"
#include <stdint.h>
#include <string.h>

#ifndef KEYCODE_CONV_H_
#define KEYCODE_CONV_H_

typedef struct keyCode keyCode;
struct keyCode {
    uint8_t key_code;
    const char *key_name;
};

#define KEYCODE(KC)                                                            \
    { KC, #KC }

uint8_t get_keycode_by_name(char *key_name);
uint8_t get_modkeycode_by_name(char *modkey_name);

#endif /* KEYCODE_CONV_H_ */