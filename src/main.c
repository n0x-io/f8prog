#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "../include/change_key.h"
#include "../include/firmware_handling.h"
#include "../include/keycodes.h"

int main (int argc, char *argv[])
{
    fbuffer_t* p_fb = get_firmware_buffer(argv[1]);

    set_key_value(p_fb->buffer, F8_KEY8, KEY_a_A);

    /* for debugging -> print content of buffer to terminal */
    /*
    for(int i = 0; i<fb->size; i++){
        putc(isprint(fb->buffer[i]) ? fb->buffer[i] : '.', stdout);
    }
    */
   
    /* Temporary solution to renaming the input file */
    char str[50];
    sprintf(str, "new_%s", argv[1]);

    write_firmware_buffer(str, p_fb);
    return 0;
}
