typedef struct fbuffer_t fbuffer_t;
struct fbuffer_t
{
    char* buffer;
    int size;
};

/* reads in the firmware file into a buffer */
fbuffer_t* get_firmware_buffer(char* filename); 
void write_firmware_buffer(char* filename, fbuffer_t* p_fb);

