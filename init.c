#include "defs.h"

//rand generates a 15 bit random number
// This uses that to generate a randon 64 bit number
#define RAND_64 (   (U64)rand() | \
                    (U64)rand() << 15 | \
                    (U64)rand() << 30 | \
                    (U64)rand() << 45 | \
                    ((U64)rand() & 0xf) << 60)

int Sq120ToSq64[BRD_SQ_NUM];
int Sq64ToSq120[64];

U64 SetMask[64];
U64 ClearMask[64];

U64 PieceKeys[13][120];
U64 SideKey;
U64 CastleKeys[16];

int FilesBrd[BRD_SQ_NUM];
int RanksBrd[BRD_SQ_NUM];

void InitFilesRanksBrd(){

    int index, file, rank, sq;

    for (index = 0; index < BRD_SQ_NUM; ++index){
        FilesBrd[index] = OFFBOARD;
        RanksBrd[index] = OFFBOARD;
    }
    
    for (rank = RANK_1; rank <= RANK_8; ++rank){
        for (file = FILE_A; file <= FILE_H; ++file){
            sq = FR2SQ(file, rank);
            FilesBrd[sq] = file;
            RanksBrd[sq] = rank;
        }
    }

}

// Fills keys with randon 64 bit numbers
void InitHashKeys(){
    int index = 0;
    int index2 = 0;

    for (index = 0; index < 13; ++index){
        for (index2 = 0; index2 < 120; ++index2){
            PieceKeys[index][index2] = RAND_64;
        }
    }

    SideKey = RAND_64;

    for(index = 0; index < 16; ++index){CastleKeys[index] = RAND_64;}
}

void InitBitMasks(){
    int index = 0;

    // Clears the SetMask and ClearMask arrays
    for (index = 0; index < 64; index++){SetMask[index] = 0ULL; ClearMask[index] = 0ULL;}

    for (index = 0; index < 64; index++){SetMask[index] = (1ULL << index); ClearMask[index] = ~SetMask[index];}
}

void InitSq120To64(){

    int index = 0;
    int file = FILE_A;
    int rank = RANK_1;
    int sq = A1;
    int sq64 = 0;

    // Sets every index to an unobtainable number
    // Useful for error checking
    for (index = 0; index < BRD_SQ_NUM; ++index){Sq120ToSq64[index] = 65;}

    for (index = 0; index < 64; ++index){Sq64ToSq120[index] = 120;}

    // Gives us 2 arrays to allow us to convert from one type of board to the other (64 to 128 or vice versa)
    for (rank = RANK_1; rank <= RANK_8; ++rank){
        for (file = FILE_A; file <= FILE_H; ++file){
            sq = FR2SQ(file, rank);
            Sq64ToSq120[sq64] = sq;
            Sq120ToSq64[sq] = sq64;
            sq64++;
        }
    }
}

void AllInit() {
    InitSq120To64();
    InitBitMasks();
    InitHashKeys();
    InitFilesRanksBrd();
}