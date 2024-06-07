#include "game.h"
#include <memory.h>
#include <stdlib.h>
game* game_new() {
    return malloc(sizeof(game));
}