#ifndef H_VECTOR
#define H_VECTOR

#ifndef INITIAL_SIZE
#define INITIAL_SIZE 1
#endif

#include <unistd.h>

typedef struct vector_t
{
    int length;
    int capacity;
    int item_size;
    void* data;
} vector;

/// Initializes a new vector instance.
vector* vector_new(size_t item_size);
void* vector_push(vector*);
void vector_allocate(vector*, int);
void* vector_at(vector*, int);

#endif
