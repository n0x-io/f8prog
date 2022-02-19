#include "../include/config_handling.h"

#include "../include/defines.h"
#include "../include/keycodes_conv.h"

#include <cjson/cJSON.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

/* define declarations */
#define JO_MACROS "macros"
#define JO_MACRO_NO "macro_no"
#define JO_ACTIONS "actions"
#define JO_MOD_KEYS "mod_keys"
#define JO_DELAY "delay"
#define JO_KEYS "keys"

enum MacroNumber {
    MACRO1 = 1,
    MACRO2,
    MACRO3,
    MACRO4,
    MACRO5,
    MACRO6,
    MACRO7,
    MACRO8
};

/* method declarations */
char *read_in_config(const char *conf_name);

f8_macroP *
get_f8_macros(char *conf_name) {

    /* reserve space for up to 8 macros */
    f8_macroP *return_macros = malloc(sizeof(return_macros) * 8);

    for (int i = 0; i < sizeof(return_macros); i++) {
        f8_macroP pm     = calloc(1, sizeof(*pm));
        return_macros[i] = pm;
    }

    cJSON       *macros = NULL;
    const cJSON *macro  = NULL;

    /* pmarse the read in config file */
    cJSON       *config_json = cJSON_Parse(read_in_config(conf_name));
    if (config_json == NULL) {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error before: %s\n", error_ptr);
        }
        exit(EXIT_FAILURE);
    }

    /* READ IN VALUES */
    macros = cJSON_GetObjectItemCaseSensitive(config_json, JO_MACROS);
    cJSON_ArrayForEach(macro, macros) {

        /* create new macro-pointer */
        f8_macroP pm = calloc(1, sizeof(*pm));

        /* Get the macro number from the JSON and set the offest */
        cJSON *macro_no = cJSON_GetObjectItemCaseSensitive(macro, JO_MACRO_NO);
        switch ((int)cJSON_GetNumberValue(macro_no)) {
        case MACRO1:
            return_macros[MACRO1 - 1] = pm;
            pm->offset                = PROG1_OFFSET;
            break;
        case MACRO2:
            return_macros[MACRO2 - 1] = pm;
            pm->offset                = PROG2_OFFSET;
            break;
        case MACRO3:
            return_macros[MACRO3 - 1] = pm;
            pm->offset                = PROG3_OFFSET;
            break;
        case MACRO4:
            return_macros[MACRO4 - 1] = pm;
            pm->offset                = PROG4_OFFSET;
            break;
        case MACRO5:
            return_macros[MACRO5 - 1] = pm;
            pm->offset                = PROG5_OFFSET;
            break;
        case MACRO6:
            return_macros[MACRO6 - 1] = pm;
            pm->offset                = PROG6_OFFSET;
            break;
        case MACRO7:
            return_macros[MACRO7 - 1] = pm;
            pm->offset                = PROG7_OFFSET;
            break;
        case MACRO8:
            return_macros[MACRO8 - 1] = pm;
            pm->offset                = PROG8_OFFSET;
            break;
        }

        /* Move through all the actions in the current macro and set the values
         */
        cJSON *action  = NULL;
        cJSON *actions = cJSON_GetObjectItemCaseSensitive(macro, JO_ACTIONS);

        int    i = 0;
        cJSON_ArrayForEach(action, actions) {

            f8_macro_actionP pma = calloc(1, sizeof(*pma));

            cJSON           *mod_keys =
                cJSON_GetObjectItemCaseSensitive(action, JO_MOD_KEYS);
            // cJSON *delay = cJSON_GetObjectItemCaseSensitive(action,
            // JO_DELAY);
            cJSON *keys = cJSON_GetObjectItemCaseSensitive(action, JO_KEYS);

            printf(" >> %s\r\n",
                   cJSON_GetStringValue(cJSON_GetArrayItem(keys, 0)));
            printf(" >> %s\r\n",
                   cJSON_GetStringValue(cJSON_GetArrayItem(keys, 1)));
            printf(" >> %s\r\n",
                   cJSON_GetStringValue(cJSON_GetArrayItem(keys, 2)));
            printf(" >> %s\r\n",
                   cJSON_GetStringValue(cJSON_GetArrayItem(keys, 3)));
            printf(" >> %s\r\n",
                   cJSON_GetStringValue(cJSON_GetArrayItem(keys, 4)));
            printf(" >> %s\r\n",
                   cJSON_GetStringValue(cJSON_GetArrayItem(keys, 5)));

            pma->modifier =
                get_modkeycode_by_name(cJSON_GetStringValue(mod_keys));
            pma->delay   = 0x00; // TODO: Set acutal value from JSON
            pma->action1 = get_keycode_by_name(
                cJSON_GetStringValue(cJSON_GetArrayItem(keys, 0)));
            pma->action2 = get_keycode_by_name(
                cJSON_GetStringValue(cJSON_GetArrayItem(keys, 1)));
            pma->action3 = get_keycode_by_name(
                cJSON_GetStringValue(cJSON_GetArrayItem(keys, 2)));
            pma->action4 = get_keycode_by_name(
                cJSON_GetStringValue(cJSON_GetArrayItem(keys, 3)));
            pma->action5 = get_keycode_by_name(
                cJSON_GetStringValue(cJSON_GetArrayItem(keys, 4)));
            pma->action6 = get_keycode_by_name(
                cJSON_GetStringValue(cJSON_GetArrayItem(keys, 5)));

            /* append the new action to the macro */
            pm->actions[i++] = pma;
        }
    }

    return return_macros;
}

char *
read_in_config(const char *conf_name) {

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
