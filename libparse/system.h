#ifndef H_SYSTEL

#include "unistd.h"
#include "arena/arena.h"

typedef struct system
{
    char * content;
    int position;

    Arena alloc;

    int allocated_bytes;
    
} system_t;

system_t* system_new(char*);
void* system_alloc(system_t* system, size_t t);
void* system_realloc(system_t* system, void* ptr, size_t size);
void system_free(system_t*);
int system_read_char(system_t* system);

#endif
