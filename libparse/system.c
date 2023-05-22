#include "libparse/system.h"
#include "malloc.h"
#define ARENA_IMPLEMENTATION
#include "arena/arena.h"

system_t* system_new(char* content) {
    system_t* system = malloc(sizeof(system_t));
    system->alloc.begin = NULL;
    system->alloc.end = NULL;
    return system;
} 

void* system_alloc(system_t* system, size_t size) {
    void* header = arena_alloc(&system->alloc, size + sizeof(int));
    *(int*)(header) = (int)(size + sizeof(int));
    // skip the header.
    void* ptr = header + sizeof(int);

    system->allocated_bytes += size + sizeof(int);

    return ptr;
}

void system_free(system_t* system) {
    arena_free(&(system->alloc));
}

void* system_realloc(system_t* system, void* ptr, size_t size) {
    if (ptr == NULL) {
        return system_alloc(system, size);
    }
    int header = *(int*)(ptr - sizeof(int));
    void* newheader = arena_realloc(&system->alloc, ptr - sizeof(int), header, size + sizeof(int));
    *(int*)newheader = (int)(size + sizeof(int));

    system->allocated_bytes += size + sizeof(int) - header;

    return newheader + sizeof(int);
}

int system_read_char(system_t *system)
{
    return getchar();
}
