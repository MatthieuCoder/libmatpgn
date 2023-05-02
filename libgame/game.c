#include "game.h"
#include <memory.h>
game* game_new() {
    return malloc(sizeof(game));
}