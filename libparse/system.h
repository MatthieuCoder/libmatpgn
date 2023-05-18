#ifndef H_SYSTEL

typedef struct system
{
    char * content;
    int position;
} system_t;

int system_read_char(system_t* system);

#endif