#ifndef CONFIG_HANDLING_H_
#define CONFIG_HANDLING_H_

/* config_handling.h */
#include "../include/firmware_handling.h"

/* Read in a config file with the specified name. */
prog_actionP *get_config(char *conf_name);

#endif /* CONFIG_HANDLING_H_ */
