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

int print_comment(char *comment)
{
    for (int i = 0; i < strlen(comment); i++)
    {
        if (
            comment[i] == '&' ||
            comment[i] == '%' ||
            comment[i] == '$' ||
            comment[i] == '#' ||
            comment[i] == '_' ||
            comment[i] == '{' ||
            comment[i] == '}' ||
            comment[i] == '~' ||
            comment[i] == '^' ||
            comment[i] == '\\')
        {
        }
        else
        {

            printf("%c", comment[i]);
        }
    }
}

int main(int argc, char **argv)
{
    int opt, interval = 5;
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
    printf("\\usepackage{fancyhdr}\n");
    printf("\\usepackage{multicol}\n");

    char *title;

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
            title = kv->value;
        }
        else if (strcmp(kv->key, "Date ") == 0)
        {
            printf("\\date{%s}\n", kv->value);
        }
    }

    printf("\\begin{document}\n");
    printf("\\pagestyle{fancy}\n");
    printf("\\fancyhead{}\n");
    printf("\\fancyhead[C]{\\textbf{%s}}\n", title);
    printf("\\maketitle\n");
    printf("\\xskaknewstyleitem[afterwhite=\\space,afterblack=\\space]{mystyle}\n");

    // printf("\\xskaknewstyle[level=20,styleitem=mystyle]{mystyle}");
    // printf("\\xskakset{style=mystyle}");
    printf("\\makegametitle\n");

    char* out = malloc(sizeof(char) * 2000);

    printf("\\noindent\n");
    printf("\\begin{minipage}{\\textwidth}\n");
    printf("\\begin{multicols}{2}\n");
    printf("\\mainline{");

    for (int i = ast->round->length - 1; i != -1; i--)
    {
        round *r = vector_at(ast->round, i);
        san_to_str(r->first_move, out);
        printf("%i. %s ", r->number, out);

        if (r->first_move->comment != NULL)
        {
            printf(" \\xskakcomment{");
            print_comment(r->first_move->comment);
            printf("} ");
        }

        if (r->second_move != NULL)
        {
            san_to_str(r->second_move, out);
            printf(" %s ", out);

            if (r->second_move->comment != NULL)
            {
                printf(" \\xskakcomment{");
                print_comment(r->second_move->comment);
                printf("} ");
            }
        }
        if ((r->number % interval == 0 && r->second_move != NULL) || i == 0)
        {
            printf("}\n");
            printf("\n\\chessboard[showmover=false]\n");
            printf("\\end{multicols}\n");
            printf("\\end{minipage}");

            if (i != 0)
            {
                printf("\\\\");
                printf("\\noindent\n");
                printf("\\begin{minipage}{\\textwidth}\n");
                printf("\\begin{multicols}{2}\n");
                printf("\\mainline{\n");
            }
        }
    }

    printf("\\end{document}\n");
    system_free(s);

    return 0;
}
