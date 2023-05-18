#include "libgame/san.h"

int san_to_str(san_t san, char *out)
{
    int chtr = 0;
    switch (san.type)
    {
    case PIECE_ROOK:
        switch (san.inner.castling_move.side)
        {
        case KINGSIDE:
            out[chtr++] = 'O';
            out[chtr++] = '-';
            out[chtr++] = 'O';
            break;
        case QUEENSIDE:
            out[chtr++] = 'O';
            out[chtr++] = '-';
            out[chtr++] = 'O';
            out[chtr++] = '-';
            out[chtr++] = 'O';
            break;
        default:
            break; // inconsistent state
        }
        break;
    case PIECE_PAWN:
        (out)[chtr++] = san.inner.pawn_move.destination.file;
        if (san.inner.pawn_move.destination.rank != RANK_NONE)
        {
            (out)[chtr++] = san.inner.pawn_move.destination.rank;
        }

        if (san.inner.pawn_move.captures.file != FILE_NONE && san.inner.pawn_move.captures.rank != RANK_NONE)
        {
            // add 'x' file rank
            (out)[chtr++] = 'x';
            (out)[chtr++] = san.inner.pawn_move.captures.file;
            (out)[chtr++] = san.inner.pawn_move.captures.rank;
        }

        if (san.inner.pawn_move.promoted != PIECE_UNKNOWN)
        {
            // add '=' promoted
            (out)[chtr++] = '=';
            (out)[chtr++] = san.inner.pawn_move.promoted;
        }
        break;
    default:
        (out)[chtr++] = san.type;
        if (san.inner.piece_move.captures==1)
        {
            (out)[chtr++] = 'x';
            (out)[chtr++] = san.inner.piece_move.destination.file;
            (out)[chtr++] = san.inner.piece_move.destination.rank;
        }
        else
        {
            // print san.inner.piece_move.destination.{rank,file}
            (out)[chtr++] = san.inner.piece_move.destination.file;
            (out)[chtr++] = san.inner.piece_move.destination.rank;
        }
        break;
    }

    (out)[chtr++] = '\0';
}