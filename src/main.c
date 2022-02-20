#include "../include/config_handling.h"
#include "../include/defines.h"
#include "../include/firmware_handling.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void  testing(f_bffrP p_fb);
char *updated_file_name(char *orig);

int
main(int argc, char *argv

                   []) {
    /* Read in the firmware file into a f_bffr_t struct */
    f_bffrP    p_fb = get_firmware_buffer(argv[1]);

    /* Call testing method */

    // testing(p_fb);

    f8_macroP *my_macros = get_f8_macros(argv[2]);
    int        len       = sizeof(my_macros);

    printf("Length of my_macros: %d\r\n", len);

    for (int i = 0; i < len;

         i++) {
        set_program(p_fb, my_macros[i]);
        free(my_macros[i]);
    }

    char *new_name = updated_file_name(argv[1]);
    write_firmware_buffer(new_name, p_fb);
    free(new_name);

    free(p_fb->buffer);
    free(p_fb);

    return 0;
}

char *
updated_file_name(char *orig) {
    char *ne  = "_new.bin";
    int   len = strlen(orig);

    char *new_name = malloc(len + 4);

    strncpy(new_name, orig, len - 4);
    strcat(new_name, ne);

    printf("New File Name: %s", new_name);

    return new_name;
}

void
testing(f_bffrP p_fb) {

    /*
    set_key_value(p_fb->buffer, F8_KEY1, KEY_9_LeftParenthesis);
    set_key_value(p_fb->buffer, F8_KEY2, KEY_8_Asterisk);
    set_key_value(p_fb->buffer, F8_KEY3, KEY_7_Ampersand);
    set_key_value(p_fb->buffer, F8_KEY4, KEY_6_Caret);
    set_key_value(p_fb->buffer, F8_KEY5, KEY_5_Percent);
    set_key_value(p_fb->buffer, F8_KEY6, KEY_4_Dollar);
    set_key_value(p_fb->buffer, F8_KEY7, KEY_3_Pound);
    set_key_value(p_fb->buffer, F8_KEY8, KEY_2_At);
    */

    /* for debugging -> print content of buffer to terminal */
    /*
    for(int i = 0; i<p_fb->size; i++){
        putc(isprint(p_fb->buffer[i]) ? p_fb->buffer[i] : '.', stdout);
    }
    */

    f8_macro_actionP pma = calloc(1, sizeof(*pma));
    pma->modifier        = 0x00;
    pma->delay           = 0x00;
    pma->action1         = 0x0B;
    pma->action2         = 0x04;
    pma->action3         = 0x0F;
    pma->action4         = 0x0F;
    pma->action5         = 0x12;
    pma->action6         = 0x00;

    f8_macroP pm    = calloc(1, sizeof(*pm));
    pm->offset      = PROG1_OFFSET;
    pm->actions[0]  = pma;
    pm->actions[1]  = pma;
    pm->actions[2]  = pma;
    pm->actions[3]  = pma;
    pm->actions[99] = pma;
    //*/

    set_program(p_fb, pm);

    free(pm);
    free(pma);
}
