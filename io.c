#include "stdio.h"
#include "defs.h"

char *PrSq(const int sq){

    static char SqStr[3];

    int file = FilesBrd[sq];
    int rank = RanksBrd[sq];

    sprintf(SqStr, "%c%c", ('a'+file), ('1'+rank));

    return SqStr;
}

char *PrMv(const int move){

    static char MvStr[6];

    //Gets Files & Ranks from
    int ff = FilesBrd[FROMSQ(move)];
    int rf = RanksBrd[FROMSQ(move)];
    //Gets Files & Ranks to
    int ft = FilesBrd[TOSQ(move)];
    int rt = RanksBrd[TOSQ(move)];

    int promoted = PROMOTED(move);

    if (promoted){
        char pchar = 'q';
        if (IsKn(promoted)){pchar='n';}
        else if(IsRQ(promoted) && !IsBQ(promoted)){pchar='r';}
        else if(IsBQ(promoted) && !IsRQ(promoted)){pchar='b';}
        sprintf(MvStr, "%c%c%c%c%c", ('a'+ff), ('1'+rf), ('a'+ft), ('1'+rt), pchar);
    } else {sprintf(MvStr, "%c%c%c%c", ('a'+ff), ('1'+rf), ('a'+ft), ('1'+rt));}

    return MvStr;
}

void PrintMoveList(const S_MOVELIST *list){

    int index, score, move;

    printf("Move List:\n");

    for (index = 0; index < list->count; ++index){
        move = list->moves[index].move;
        score = list->moves[index].score;
        printf("Move: %d > %s (score:%d)\n", index+1, PrMv(move), score);
    }
    printf("MoveList Total: %d Moves:\n\n", list->count);
}