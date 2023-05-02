#include "vector.h"
#include <memory.h>
#include <malloc.h>

vector* vector_new(size_t item_size) {
    vector* vec = (vector*) malloc(sizeof(vector));
    vec->data = malloc(sizeof(void*) * INITIAL_SIZE * item_size);
    vec->capacity = INITIAL_SIZE;
    vec->length = 0;
    vec->item_size = item_size;
    return vec;
}

void* vector_push(vector* vector) {
    if (vector->length + 1 > vector->capacity) {
        vector_allocate(vector, vector->capacity * 2);
    }

    void* start_address = vector->data + vector->item_size * (vector->length);
    printf("Item push to address: %x (base pt=%x) for %i bytes\n", start_address, vector->data, vector->item_size);
    vector->length++;

    return start_address;
}

void vector_allocate(vector* vector, int new_size) {
    // we do not allow downsizing the memory area.
    if (vector->length > new_size) {
        return;
    }

    vector->capacity = new_size;
    vector->data = realloc(vector->data, new_size * vector->item_size);
}

void* vector_at(vector* vector, int index) {
    if(vector->length < index) {
        return (void*)0;
    }
    void* data = vector->data + index * vector->item_size;
    //printf("Recovering data from index %i at address %x (base pt=%x)\n", index, data, vector);
    return data;
}
