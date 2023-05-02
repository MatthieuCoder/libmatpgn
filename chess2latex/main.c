#include <stddef.h>
#include "libparse/parser.h"
#include "libgame/game.h"
#include "libmem/kv.h"
#include "libgame/round.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    parser_context_t *parser = parser_create(NULL);
    game* ast;
    parser_parse(parser, (void**)&ast);

    printf("** Pgn game \n");
    printf("* %i headers\n", ast->header->length);
    printf("* %i moves\n", ast->round->length);

    printf("Header data: \n");
    for (int i = 0; i < ast->header->length; i++) {
        kv* kv = vector_at(ast->header, i);

        printf("\t=> %i: header(%s): %s\n", i, kv->key, kv->value);
    }

    printf("Move data: \n");
    for (int i = 0; i < ast->round->length; i++) {
        round* round = vector_at(ast->round, i);
        printf("\t=> Got game round(%i) %i\n", i, round->number);
    }

    parser_destroy(parser);
    return 0;
}
