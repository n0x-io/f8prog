#include "../include/config_handling.h"

#include "../include/defines.h"
#include "../include/keycodes_conv.h"

#include <cjson/cJSON.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
char   *read_in_config(const char *conf_name);
void    set_action(const cJSON *action, f8_macro_actionP pma);
uint8_t get_key_from_json(cJSON *key);

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
    char        *conf        = read_in_config(conf_name);
    cJSON       *config_json = cJSON_Parse(conf);
    free(conf);

    if (config_json == NULL) {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error before: %s\n", error_ptr);
        }
        exit(EXIT_FAILURE);
    }

    /* READ IN VALUES */
    int i  = 0;
    macros = cJSON_GetObjectItemCaseSensitive(config_json, JO_MACROS);
    cJSON_ArrayForEach(macro, macros) {

        /* create new macro-pointer */
        f8_macroP pm = return_macros[i++];

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

        printf("For Macro %d the values are\r\n",
               (int)cJSON_GetNumberValue(macro_no));

        /* Move through all the actions in the current macro and set the values
         */
        cJSON *action  = NULL;
        cJSON *actions = cJSON_GetObjectItemCaseSensitive(macro, JO_ACTIONS);

        int    j = 0;
        cJSON_ArrayForEach(action, actions) {

            printf(" >> Action %d\r\n", j);
            f8_macro_actionP pma = calloc(1, sizeof(*pma));

            set_action(action, pma);
            /* append the new action to the macro */
            pm->actions[j++] = pma;
        }
    }

    cJSON_Delete(config_json);
    return return_macros;
}

void
set_action(const cJSON *action, f8_macro_actionP pma) {

    cJSON *mod_keys = cJSON_GetObjectItemCaseSensitive(action, JO_MOD_KEYS);
    cJSON *delay    = cJSON_GetObjectItemCaseSensitive(action, JO_DELAY);
    cJSON *keys     = cJSON_GetObjectItemCaseSensitive(action, JO_KEYS);

    pma->modifier = get_key_from_json(mod_keys);

    printf(" >> Delay: %.2f\r\n", cJSON_GetNumberValue(delay));
    pma->delay = 0x00; // TODO: Set actual value from JSON

    pma->action1 = get_key_from_json(cJSON_GetArrayItem(keys, 0));
    pma->action2 = get_key_from_json(cJSON_GetArrayItem(keys, 1));
    pma->action3 = get_key_from_json(cJSON_GetArrayItem(keys, 2));
    pma->action4 = get_key_from_json(cJSON_GetArrayItem(keys, 3));
    pma->action5 = get_key_from_json(cJSON_GetArrayItem(keys, 4));
    pma->action6 = get_key_from_json(cJSON_GetArrayItem(keys, 5));
}

/* returns the key-code from the given string. If no keycode is matched or the
 * string is empty keycode 0x00 will be supplied */
uint8_t
get_key_from_json(cJSON *key) {
    uint8_t key_val = 0x00; /* default the key value to zero */

    if (strcmp(cJSON_GetStringValue(key), "") != 0) {
        key_val = get_keycode_by_name(cJSON_GetStringValue(key));
    }

    printf(" >> Got keyvalue 0x%02x for key \"%s\"\r\n", key_val,
           cJSON_GetStringValue(key));

    return key_val;
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
    fclose(fp);

    return config;
}
