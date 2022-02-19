#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/* Just for debugging */
#include "../include/firmware_handling.h"

#include <ctype.h>

f_bffrP
get_firmware_buffer(char *filename) {

    f_bffrP p_fb = malloc(sizeof(*p_fb));

    FILE   *firmware = fopen(filename, "rb");
    if (!firmware) {
        perror("Error while reading in Firmware File.\r\nExiting.");
        exit(EXIT_FAILURE);
    }

    struct stat sb;
    if (stat(filename, &sb) == -1) {
        perror("Error while reading Firmware metadata.\r\nExiting.");
        exit(EXIT_FAILURE);
    }

    /* set buffer size and read in firmware file into buffer*/
    p_fb->size   = sb.st_size;
    p_fb->buffer = malloc(p_fb->size);
    fread(p_fb->buffer, p_fb->size, 1, firmware);

    /* for testing if the buffer could be read correclty */
    // printf("buffer size: %d", p_fb->size);

    fclose(firmware);

    return p_fb;
}

void
write_firmware_buffer(char *filename, f_bffrP p_fb) {

    FILE *firmware_file = fopen(filename, "wb+");
    if (!firmware_file) {
        perror("Error while opening in Firmware File.\r\nExiting.");
        exit(EXIT_FAILURE);
    }

    fwrite(p_fb->buffer, p_fb->size, 1, firmware_file);

    fclose(firmware_file);
}

void
set_key_value(char *firmware_buffer, int key, int value) {
    memset(firmware_buffer + key, value, 1);
}

void
set_program(f_bffrP p_fb, f8_macroP mp) {
    for (int i = 0; i < MAX_ACTION; i++) {
        // Check if an action for that position exists
        if (mp) {
            if (mp->actions[i]) {
                /* calculate the offset for the action
                 * -> general prog_offset + current prog_action i times bytes
                 * per action
                 */
                int actionpointer = mp->offset + (i * sizeof(*mp->actions[0]));

                /* set the modifiers */
                memset(p_fb->buffer + actionpointer + 0,
                       mp->actions[i]->modifier, 1);
                /* set timing delay */
                memset(p_fb->buffer + actionpointer + 1, mp->actions[i]->delay,
                       1);
                /* set action 1-6 */
                memset(p_fb->buffer + actionpointer + 2,
                       mp->actions[i]->action1, 1);
                memset(p_fb->buffer + actionpointer + 3,
                       mp->actions[i]->action2, 1);
                memset(p_fb->buffer + actionpointer + 4,
                       mp->actions[i]->action3, 1);
                memset(p_fb->buffer + actionpointer + 5,
                       mp->actions[i]->action4, 1);
                memset(p_fb->buffer + actionpointer + 6,
                       mp->actions[i]->action5, 1);
                memset(p_fb->buffer + actionpointer + 7,
                       mp->actions[i]->action6, 1);
            }
        }
    }
}
