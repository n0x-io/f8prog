#include <stdint.h>

/* Max prog_actions per key_prog */
#define MAX_ACTION 100

/* Defines for key offsets */
#define F8_KEY1 0x00005189
#define F8_KEY2 0x00005181
#define F8_KEY3 0x00005179
#define F8_KEY4 0x00005149
#define F8_KEY5 0x0000518A
#define F8_KEY6 0x00005182
#define F8_KEY7 0x0000517A
#define F8_KEY8 0x0000514A

/* Defines for key program code */
#define F8_PROG1 0xD7
#define F8_PROG2 0xD8
#define F8_PROG3 0xD9
#define F8_PROG4 0xDA
#define F8_PROG5 0xDB
#define F8_PROG6 0xDC
#define F8_PROG7 0xDD
#define F8_PROG8 0xDE

/* Define for prog1-8 offset */
#define PROG1_OFFSET 0x0000539C
#define PROG2_OFFSET 0x000056BC
#define PROG3_OFFSET 0x000059DC
#define PROG4_OFFSET 0x00005CFC
#define PROG5_OFFSET 0x0000601C
#define PROG6_OFFSET 0x0000633C
#define PROG7_OFFSET 0x0000665C
#define PROG8_OFFSET 0x0000697C

typedef struct f_bffr_t* f_bffrP;
struct f_bffr_t
{
    char *buffer;
    int size;
};

/* 
 * A single macro action
 * First value is the modifiers to be hold while executing the other actions (see keycodes.h)
 * Second value is the delay between the keypresse ranging from 0.0 seconds to 3.0 seconds
 * The remaining values are the keycodes to be pressed
 */
typedef struct prog_action* prog_actionP;
struct prog_action
{
    uint8_t k_modifier;
    uint8_t k_delay;
    uint8_t k_action1;
    uint8_t k_action2;
    uint8_t k_action3;
    uint8_t k_action4;
    uint8_t k_action5;
    uint8_t k_action6;
};

/* 
 * A single macro program consisting of the offset and up to MAX_ACTION (100) actions
 */
typedef struct key_prog* key_progP;
struct key_prog
{
    int prog_offset;
    prog_actionP prog_actions[MAX_ACTION];
};

/* 
 * set the value "value" to the specified key "key" inside the buffer "firmware_buffer"
 * Key has to be the offset of the key to be altered.
 * Value has to be a keycode
 */
void set_key_value(char *firmware_buffer, int key, int value);

void set_program(f_bffrP p_fb, key_progP kp);

/* reads in the firmware file into a buffer */
f_bffrP get_firmware_buffer(char *filename); 

void write_firmware_buffer(char *filename, f_bffrP p_fb);

