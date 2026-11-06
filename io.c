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