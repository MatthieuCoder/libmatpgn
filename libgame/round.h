#ifndef H_ROUND
#include "libmem/vector.h"
#include "libgame/san.h"

typedef struct round_t
{
    int number;
    san_t* first_move;
    san_t* second_move;
} round;
#endif