#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../include/firmware_handling.h"
#include "../include/keycodes.h"

void testing (f_bffrP p_fb);
char *updated_file_name(char *orig);

int main (int argc, char *argv[])
{
    /* Read in the firmware file into a f_bffr_t struct */
    f_bffrP p_fb = get_firmware_buffer(argv[1]);

    /* Call testing method */
    testing(p_fb);

    write_firmware_buffer(updated_file_name(argv[1]), p_fb);

    free(p_fb->buffer);
    free(p_fb);

    return 0;
}

char *updated_file_name (char *orig){
    char *ne = "_new.bin";
    int len = strlen(orig);

    char *new_name = malloc(len + 4);

    strncpy(new_name, orig, len - 4);
    strcat(new_name, ne); 

    printf("New File Name: %s", new_name);

    return new_name;
}

void testing (f_bffrP p_fb) {
    set_key_value(p_fb->buffer, F8_KEY1, KEY_9_LeftParenthesis);
    set_key_value(p_fb->buffer, F8_KEY2, KEY_8_Asterisk);
    set_key_value(p_fb->buffer, F8_KEY3, KEY_7_Ampersand);
    set_key_value(p_fb->buffer, F8_KEY4, KEY_6_Caret);
    set_key_value(p_fb->buffer, F8_KEY5, KEY_5_Percent);
    set_key_value(p_fb->buffer, F8_KEY6, KEY_4_Dollar);
    set_key_value(p_fb->buffer, F8_KEY7, KEY_3_Pound);
    set_key_value(p_fb->buffer, F8_KEY8, KEY_2_At);

    /* for debugging -> print content of buffer to terminal */
    /*
    for(int i = 0; i<p_fb->size; i++){
        putc(isprint(p_fb->buffer[i]) ? p_fb->buffer[i] : '.', stdout);
    }
    */

    prog_actionP pa = calloc(1, sizeof(*pa));
    pa->k_modifier = 0x00;
    pa->k_delay = 0x00;
    pa->k_action1 = 0x0B;
    pa->k_action2 = 0x04;
    pa->k_action3 = 0x0F;
    pa->k_action4 = 0x0F;
    pa->k_action5 = 0x12;
    pa->k_action6 = 0x00;

    
    key_progP kp = calloc(1, sizeof(*kp));
    kp->prog_offset = PROG1_OFFSET;
    kp->prog_actions[0] = pa;
    kp->prog_actions[1] = pa;
    kp->prog_actions[2] = pa;
    kp->prog_actions[3] = pa;
    kp->prog_actions[99] = pa;
    //*/
    
    set_program(p_fb, kp);

    free(kp);
    free(pa);
}
