#include <stddef.h>
#include "libparse/parser.h"
#include "libgame/game.h"
#include "libmem/kv.h"
#include "libgame/round.h"
#include "libgame/san.h"
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>

int main(int argc, char **argv)
{
    
    system_t s;

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        printf("File not found.\n");
        return 1;
    }
    int len = lseek(fd, 0, SEEK_END);
    void *data = mmap(0, len, PROT_READ, MAP_PRIVATE, fd, 0);

    s.content = data;
    s.position = 0;
    parser_context_t *parser = parser_create(&s);

    game *ast;
    parser_parse(parser, (void **)&ast);

    printf("** Pgn game \n");
    printf("* %i headers\n", ast->header->length);
    printf("* %i moves\n", ast->round->length);

    printf("Header data: \n");
    for (int i = 0; i < ast->header->length; i++)
    {
        kv *kv = vector_at(ast->header, i);

        printf("\t=> %i: header(%s): %s\n", i, kv->key, kv->value);
    }

    printf("Move data: \n");
    for (int i = 0; i < ast->round->length; i++)
    {
        round *round = vector_at(ast->round, i);
        printf("\t=> Got game round(%i) %i\n", i, round->number);
        char a[255];
        san_to_str(*(round->first_move), &a);
        printf("\t\t fm: %c: %s\n", round->first_move->type, a);
        
        if (round->second_move != 0) {
        san_to_str(*(round->second_move), &a);
            printf("\t\t sm: %c: %s\n", round->second_move->type, a);
        }
    }

    parser_destroy(parser);
    
    san_t* t = (void*)malloc(sizeof(san_t));


    return 0;
}
