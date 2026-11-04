#include "stdio.h"
#include "defs.h"

int main(){
    AllInit();

    int index = 0;

    for (index = 0; index < BRD_SQ_NUM; ++index){
        if (index%10==0) printf("\n");
        printf("%5d", Sq120ToSq64[index]);
    }

    printf("\n");
    printf("\n");

    for (index = 0; index < 64; ++index){
        if (index%8==0) printf("\n");
        printf("%5d", Sq64ToSq120[index]);
    }

    printf("\n");

    U64 playBitBoard = 0ULL;
    PrintBitBoard(playBitBoard);

    playBitBoard |= (1ULL << SQ64(D2)) | (1ULL << SQ64(G2));
    PrintBitBoard(playBitBoard);

    return 0;
}