#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>

#include "../include/change_key.h"

void set_key_value(char* firmware_buffer, int key, int value) {
    memset(firmware_buffer + key, value, 1);
}
