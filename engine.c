#include "stdio.h"
#include "defs.h"

#define FEN1 "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1"
#define FEN2 "rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2"
#define FEN3 "rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2"
#define FEN4 "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1"
#define FEN5 "8/3q1p2/8/5P2/4Q3/8/8/8 w KQkq - 0 1"

int main(){
    AllInit();

    S_BOARD board[1];

    ParseFEN(FEN4, board);
    PrintBoard(board);
    ASSERT(CheckBoard(board));

    int move = 0;

    int from = 6; int to = 12;
    int cap = wR; int prom = bR;
    move = from | (to << 7) | (cap << 14) | (prom << 20);

    printf("\ndec:%d\nhex:%X\nbin:", move, move);

    int index = 0;
    for(index = 27; index >= 0; index--){
        if ((1 << index) & move){printf("1");}
        else{printf("0");}
        if (index!=28 && index%4==0){printf(" ");}
    }
    printf("\n\nfrom:%d\nto:%d\ncap:%d\nprom:%d\n", FROMSQ(move), TOSQ(move), CAPTURED(move), PROMOTED(move));

    return 0;
}