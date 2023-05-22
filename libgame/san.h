#ifndef H_SAN
#define H_SAN

#include "libmem/vector.h"

typedef enum san_piece
{
    PIECE_UNKNOWN = 'Z',
    PIECE_KNIGHT = 'N',
    PIECE_BISHOP = 'B',
    PIECE_ROOK = 'R',
    PIECE_QUEEN = 'Q',
    PIECE_KING = 'K',
    PIECE_PAWN = 'P',
    PIECE_CASTLING = '@',
} san_piece_t;

typedef enum file
{
    FILE_NONE = '-',
    FILE_A = 'a',
    FILE_B = 'b',
    FILE_C = 'c',
    FILE_D = 'd',
    FILE_E = 'e',
    FILE_F = 'f',
    FILE_G = 'g',
    FILE_H = 'h',
} file_t;

typedef enum rank
{
    RANK_NONE = '0',
    RANK_1 = '1',
    RANK_2 = '2',
    RANK_3 = '3',
    RANK_4 = '4',
    RANK_5 = '5',
    RANK_6 = '6',
    RANK_7 = '7',
    RANK_8 = '8'
} rank_t;

typedef struct square
{
    file_t file;
    rank_t rank;
} square_t;

typedef struct piece_move
{
    square_t destination;
    char captures;
    char from_file;
} piece_move_t;

typedef enum castling_side
{
    KINGSIDE,
    QUEENSIDE
} castling_side_t;

typedef struct castling_move
{
    castling_side_t side;
} castling_move_t;

typedef struct pawn_move
{
    square_t destination;
    square_t captures;
    san_piece_t promoted;
} pawn_move_t;

typedef struct san
{
    san_piece_t type;
    char* comment;
    char check, checkmate;

    union
    {
        piece_move_t piece_move;
        castling_move_t castling_move;
        pawn_move_t pawn_move;
    } inner;

} san_t;

int san_to_str(san_t*, char*);

#endif