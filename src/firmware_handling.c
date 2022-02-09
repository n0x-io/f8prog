#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>

#include "../include/firmware_handling.h"

fbuffer_t* get_firmware_buffer(char* filename) {
    
    fbuffer_t buffer;
    fbuffer_t* p_fb = &buffer;

    FILE *firmware = fopen(filename, "rb");
    if(!firmware) {
        perror("Error while reading in Firmware File.\r\nExiting.");
        exit(EXIT_FAILURE);
    }

    struct stat sb;
    if(stat(filename, &sb) == -1) {
        perror("Error while reading Firmware metadata.\r\nExiting.");
        exit(EXIT_FAILURE);
    }
    
    p_fb->size = sb.st_size;
    p_fb->buffer = malloc(p_fb->size);
    fread(p_fb->buffer, p_fb->size, 1, firmware);

    /* for testing if the buffer could be read correclty */
    // printf("buffer size: %d", p_fb->size);

    fclose(firmware);

    return p_fb;
}

void write_firmware_buffer(char* filename, fbuffer_t* p_fb) {

    FILE *firmware_file = fopen(filename, "wb+");
    if(!firmware_file) {
        perror("Error while opening in Firmware File.\r\nExiting.");
        exit(EXIT_FAILURE);
    }

    fwrite(p_fb->buffer, p_fb->size, 1, firmware_file);

    fclose(firmware_file);
}
