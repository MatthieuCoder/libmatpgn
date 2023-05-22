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
#include "string.h"
#include <stdio.h> 
#include <unistd.h> 

static char *PRINT_BOARD = "\n\\chessboard\\\\";

int main(int argc, char **argv)
{
    int opt, interval;
    while ((opt = getopt(argc, argv, "n:")) != -1)
    {
        switch (opt)
        {
        case 'n':
            interval = atoi(optarg);
            break;
        default: /* aq?aq */
            fprintf(stderr, "Usage: %s [-n interval]\n",
                    argv[0]);
            exit(EXIT_FAILURE);
        }
    }
    system_t *s = system_new();
    parser_context_t *parser = parser_create(s);

    game *ast;
    parser_parse(parser, (void **)&ast);
    parser_destroy(parser);

    printf("\\documentclass[article]{article}\n");
    printf("\\usepackage[english]{babel}\n");
    printf("\\usepackage[utf8x]{inputenc}\n");
    printf("\\usepackage{xskak}\n");
    printf("\\usepackage{texmate}\n");

    for (int i = ast->header->length - 1; i != 0; i--)
    {
        kv *kv = vector_at(ast->header, i);
        if (strcmp(kv->key, "White ") == 0)
        {
            printf("\\whitename{%s}\n", kv->value);
        }
        else if (strcmp(kv->key, "Black ") == 0)
        {
            printf("\\blackname{%s}\n", kv->value);
        }
        else if (strcmp(kv->key, "Event ") == 0)
        {
            printf("\\title{%s}\n", kv->value);
            printf("\\chessevent{%s}\n", kv->value);
        }
        else if (strcmp(kv->key, "Date ") == 0)
        {
            printf("\\date{%s}\n", kv->value);
        }
    }

    printf("\\begin{document}\n");
    printf("\\maketitle\n");

    printf("\\makegametitle\n");

    char out[255];
    printf("\\mainline{");
    for (int i = ast->round->length - 1; i != -1; i--)
    {
        round *r = vector_at(ast->round, i);
        san_to_str(r->first_move, &out);
        printf("%i. %s ", r->number, out);

        if (r->second_move != NULL)
        {
            san_to_str(r->second_move, &out);
            printf("%s ", out);
        }
        if (r->number % interval == 0 || i == 0)
        {
            printf("}\n%s\n", PRINT_BOARD);
            if (i != 0)
            {
                printf("\\mainline{");
            }
        }
    }
    // printf("}\n");
    printf("\\end{document}\n");
    system_free(s);

    return 0;
}
