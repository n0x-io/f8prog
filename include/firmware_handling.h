#ifndef FIRMWARE_HANDLING_H_
#define FIRMWARE_HANDLING_H_

#include <stdint.h>

/* Max f8_macro_actions per f8_macro */
#define MAX_ACTION 100

/**** STRUCTS ****/
typedef struct f_bffr_t *f_bffrP;
struct f_bffr_t {
    char *buffer;
    int   size;
};

/*
 * A single macro action
 * First value is the modifiers to be hold while executing the other actions
 * (see keycodes.h) Second value is the delay between the keypresse ranging from
 * 0.0 seconds to 3.0 seconds The remaining values are the keycodes to be
 * pressed
 */
typedef struct f8_macro_action *f8_macro_actionP;
struct f8_macro_action {
    uint8_t modifier;
    uint8_t delay;
    uint8_t action1;
    uint8_t action2;
    uint8_t action3;
    uint8_t action4;
    uint8_t action5;
    uint8_t action6;
};

/*
 * A single macro program consisting of the offset and up to MAX_ACTION (100)
 * actions
 */
typedef struct f8_macro *f8_macroP;
struct f8_macro {
    int              offset;
    f8_macro_actionP actions[MAX_ACTION];
};

/*
 * set the value "value" to the specified key "key" inside the buffer
 * "firmware_buffer" Key has to be the offset of the key to be altered. Value
 * has to be a keycode
 */
void    set_key_value(char *firmware_buffer, int key, int value);

void    set_program(f_bffrP p_fb, f8_macroP kp);

/* reads in the firmware file into a buffer */
f_bffrP get_firmware_buffer(char *filename);

void    write_firmware_buffer(char *filename, f_bffrP p_fb);

#endif /* FIRMWARE_HANDLING_H_ */
