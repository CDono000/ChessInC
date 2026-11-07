#include "stdio.h"
#include "defs.h"

#define PAWNMOVESW "rnbqkb1r/pp1p1pPp/8/2p1pP2/1P1P4/3P3P/P1P1P3/RNBQKBNR w KQkq e6 0 1"
#define PAWNMOVESB "rnbqkbnr/p1p1p3/3p3p/1p1p4/2P1Pp2/8/PP1P1PpP/RNBQKB1R b KQkq e3 0 1"
#define KNIGHTSKINGSW "5k2/1n6/4n3/6N1/8/3N4/8/5K2 w - - 0 1"
#define KNIGHTSKINGSB "5k2/1n6/4n3/6N1/8/3N4/8/5K2 b - - 0 1"
#define ROOKSW "6k1/8/5r2/8/1nR5/5N2/8/6K1 w - - 0 1"
#define ROOKSB "6k1/8/5r2/8/1nR5/5N2/8/6K1 b - - 0 1"
#define QUEENSW "6k1/8/4nq2/8/1nQ5/5N2/1N6/6K1 w - - 0 1"
#define QUEENSB "6k1/8/4nq2/8/1nQ5/5N2/1N6/6K1 b - - 0 1"
#define BISHOPSW "6k1/1b6/4n3/8/1n4B1/1B3N2/1N6/2b3K1 w - - 0 1"
#define BISHOPSB "6k1/1b6/4n3/8/1n4B1/1B3N2/1N6/2b3K1 b - - 0 1"
#define CASTLE1W "r3k2r/8/8/8/8/8/8/R3K2R w KQkq - 0 1"
#define CASTLE1B "r3k2r/8/8/8/8/8/8/R3K2R b KQkq - 0 1"
#define CASTLE2W "3rk2r/8/8/8/8/8/6p1/R3K2R w KQk - 0 1"
#define CASTLE2B "3rk2r/6P1/8/8/8/8/8/R3K2R b KQk - 0 1"
#define CHECKW "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1"
#define CHECKB "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R b KQkq - 0 1"

int main(){
    AllInit();

    S_BOARD board[1];
    S_MOVELIST list[1];

    // ParseFEN(PAWNMOVESW, board);
    // PrintBoard(board);
    // ASSERT(CheckBoard(board));
    // GenerateAllMoves(board, list);
    // PrintMoveList(list);

    // ParseFEN(PAWNMOVESB, board);
    // PrintBoard(board);
    // ASSERT(CheckBoard(board));
    // GenerateAllMoves(board, list);
    // PrintMoveList(list);

    // ParseFEN(KNIGHTSKINGSW, board);
    // PrintBoard(board);
    // GenerateAllMoves(board, list);
    // PrintMoveList(list);

    // ParseFEN(KNIGHTSKINGSB, board);
    // PrintBoard(board);
    // GenerateAllMoves(board, list);
    // PrintMoveList(list);

    // ParseFEN(ROOKSW, board);
    // PrintBoard(board);
    // GenerateAllMoves(board, list);
    // PrintMoveList(list);

    // ParseFEN(ROOKSB, board);
    // PrintBoard(board);
    // GenerateAllMoves(board, list);
    // PrintMoveList(list);

    // ParseFEN(QUEENSW, board);
    // PrintBoard(board);
    // GenerateAllMoves(board, list);
    // PrintMoveList(list);

    // ParseFEN(QUEENSB, board);
    // PrintBoard(board);
    // GenerateAllMoves(board, list);
    // PrintMoveList(list);

    // ParseFEN(BISHOPSW, board);
    // PrintBoard(board);
    // GenerateAllMoves(board, list);
    // PrintMoveList(list);

    // ParseFEN(BISHOPSB, board);
    // PrintBoard(board);
    // GenerateAllMoves(board, list);
    // PrintMoveList(list);

    // ParseFEN(CASTLE1W, board);
    // PrintBoard(board);
    // GenerateAllMoves(board, list);
    // PrintMoveList(list);

    // ParseFEN(CASTLE1B, board);
    // PrintBoard(board);
    // GenerateAllMoves(board, list);
    // PrintMoveList(list);

    // ParseFEN(CASTLE2W, board);
    // PrintBoard(board);
    // GenerateAllMoves(board, list);
    // PrintMoveList(list);

    // ParseFEN(CASTLE2B, board);
    // PrintBoard(board);
    // GenerateAllMoves(board, list);
    // PrintMoveList(list);

    ParseFEN(CHECKW, board);
    PrintBoard(board);
    GenerateAllMoves(board, list);
    PrintMoveList(list);

    ParseFEN(CHECKB, board);
    PrintBoard(board);
    GenerateAllMoves(board, list);
    PrintMoveList(list);

    return 0;
}