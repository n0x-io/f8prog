#include <cjson/cJSON.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "../include/config_handling.h"
#include "../include/keycodes_conv.h"

/* define declarations */
#define JO_MACROS "macros"
#define JO_MACRO_NO "macro_no"
#define JO_ACTIONS "actions"
#define JO_MOD_KEYS "mod_keys"
#define JO_DELAY "delay"
#define JO_KEYS "keys"

/* method declarations */
char *read_in_config(char *conf_name);

prog_actionP *get_config(char *conf_name) {

    const cJSON *macros = NULL;
    const cJSON *macro = NULL;

    /* parse the read in config file */
    cJSON *config_json = cJSON_Parse(read_in_config(conf_name));
    if (config_json == NULL) {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error before: %s\n", error_ptr);
        }
        exit(EXIT_FAILURE);
    }

    // READ IN VALUES //
    macros = cJSON_GetObjectItemCaseSensitive(config_json, JO_MACROS);
    cJSON_ArrayForEach(macro, macros) {
        //cJSON *macro_no = cJSON_GetObjectItemCaseSensitive(macro, JO_MACRO_NO);
        cJSON *action = NULL;

        int i = 0;
        cJSON *actions = cJSON_GetObjectItemCaseSensitive(macro, JO_ACTIONS);
        cJSON_ArrayForEach(action, actions) {
            cJSON *mod_keys =
                cJSON_GetObjectItemCaseSensitive(action, JO_MOD_KEYS);
            //cJSON *delay = cJSON_GetObjectItemCaseSensitive(action, JO_DELAY);
            cJSON *keys = cJSON_GetObjectItemCaseSensitive(action, JO_KEYS);

            prog_actionP pa = calloc(1, sizeof(*pa));
            pa->k_modifier = get_modkeycode_by_name(cJSON_GetStringValue(mod_keys));
            pa->k_delay = 0x00;
            pa->k_action1 = get_keycode_by_name(
                cJSON_GetStringValue(cJSON_GetArrayItem(keys, 0)));
            pa->k_action2 = get_keycode_by_name(
                cJSON_GetStringValue(cJSON_GetArrayItem(keys, 1)));
            pa->k_action3 = get_keycode_by_name(
                cJSON_GetStringValue(cJSON_GetArrayItem(keys, 2)));
            pa->k_action4 = get_keycode_by_name(
                cJSON_GetStringValue(cJSON_GetArrayItem(keys, 3)));
            pa->k_action5 = get_keycode_by_name(
                cJSON_GetStringValue(cJSON_GetArrayItem(keys, 4)));
            pa->k_action6 = get_keycode_by_name(
                cJSON_GetStringValue(cJSON_GetArrayItem(keys, 5)));

            i++;
        }
    }

    return NULL;
}

char *read_in_config(char *conf_name) {

    FILE *fp = fopen(conf_name, "r");
    if (!fp) {
        perror("Error while reading conf file");
        exit(EXIT_FAILURE);
    }

    struct stat sb;
    if (stat(conf_name, &sb) == -1) {
        perror("Error while reading config file metadata.\r\nExiting.");
        exit(EXIT_FAILURE);
    }

    char *config = malloc(sb.st_size);
    fread(config, sb.st_size, 1, fp);

    return config;
}
