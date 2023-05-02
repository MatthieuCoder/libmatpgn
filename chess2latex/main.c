#include <stddef.h>
#include "libparse/parser.h"
#include "libgame/game.h"
#include "libmem/kv.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    parser_context_t *parser = parser_create(NULL);
    game* ast;
    parser_parse(parser, &ast);

    printf("************ Printing Game Info at %x \n", ast);
    printf("---- Metadata keys at %x\n", ast->header);
    for (int i = 0; i < ast->header->length; i++) {
        printf("Key at %i", i);
        kv entry = *(kv*)vector_at(ast->header, i);
        printf("\tMetadata key(%s): %s", entry.key, entry.value);
    }

    parser_destroy(parser);
    return 0;
}
