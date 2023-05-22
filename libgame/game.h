#ifndef H_ROUND

#include "libmem/vector.h"

#define GS_BLACK_WON 0
#define GS_WHITE_WON 1
#define GS_DRAW 2
#define GS_UNKNOWN 3


typedef struct game_t
{
    vector* header;
    vector* round;
} game;

game *game_new();

#endif
