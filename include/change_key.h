/* changeKey.h */

/* Define for key offsets */
#define F8_KEY1 0x00005149
#define F8_KEY2 0x00005179
#define F8_KEY3 0x00005181
#define F8_KEY4 0x00005189
#define F8_KEY5 0x00005190
#define F8_KEY6 0x00005182
#define F8_KEY7 0x0000517a
#define F8_KEY8 0x0000514a

/* Define for prog1-8 offset */
#define PROG1_OFFSET 0x0000539C
#define PROG2_OFFSET 0x000056BC
#define PROG3_OFFSET 0x000059DC
#define PROG4_OFFSET 0x00005CFC
#define PROG5_OFFSET 0x0000601C
#define PROG6_OFFSET 0x0000633C
#define PROG7_OFFSET 0x0000665C
#define PROG8_OFFSET 0x0006977C

typedef struct key_prog key_prog;
struct key_prog
{
    int offset;
    int key_settings[100][8];
};


void set_key_value(char* firmware_buffer, int key, int value);

