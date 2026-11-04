#ifndef DEFS_H
#define DEFS_H

#include "stdlib.h"

// Used for testing but will slow down when running
// When testing, we can use this to assert that we are getting expected values
// When not testing, comment out #define DEBUG so that the code is not slowed down
#define DEBUG

#ifndef DEBUG
#define ASSERT(n)
#else
#define ASSERT(n) \
if(!(n)) { \
    printf("%s - Failed ", #n); \
    printf("On %s ", __DATE__); \
    printf("At %s ", __TIME__); \
    printf("In File %s", __FILE__); \
    printf("At Line %d\n", __LINE__);\
    exit(1);}
#endif

// Unsigned 64 bit integer
typedef unsigned long long U64;

#define Name "Engine"

// Number of squares for the "board"
#define BRD_SQ_NUM 120

// allows for 2048 plys
#define MAXGAMEMOVES 2048

enum { EMPTY, wP, wN, wB, wR, wQ, wK, bP, bN, bB, bR, bQ, bK};

enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE };
enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE };

enum { WHITE, BLACK, BOTH};

enum {
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_SQ
};

enum { FALSE, TRUE};

// (Colour)(Side)CA
enum { WKCA = 1, WQCA = 2, BKCA = 4, BQCA = 8};

typedef struct {

    int move;
    int castlePerm;
    int enPas;
    int fiftyMove;
    U64 posKey;

} S_UNDO;


typedef struct {

    int pieces[BRD_SQ_NUM];

    // Index 0 - White, Index 1 - Black, Index 2 - Both (Index 1 | Index 2)
    U64 pawns[3];
    U64 kingSq[2];

    int side;
    int enPas;
    int fiftyMove;

    int ply;
    int hisPly;

    int castlePerm;

    U64 posKey;

    // Each index is the number of that piece
    //e.g. EMPTY = 0, wP = 1, etc
    int pceNum[13];

    // 0 is white, 1 is black, 2 is both
    // Non-pawn pieces
    int bigPce[3];
    // Rooks & Queens
    int majPce[3];
    // Bishops & Knights
    int minPce[3];

    S_UNDO history[MAXGAMEMOVES];

    // Piece List
    // Stores the position of pieces for each type
    int pList[13][10];

} S_BOARD;

// GLOBALS
extern int Sq120ToSq64[BRD_SQ_NUM];
extern int Sq64ToSq120[64];

// MACROS
#define FR2SQ(f, r) ((21 + (f)) + (r*10))
#define SQ64(sq120) Sq120ToSq64[sq120]

// FUNCTIONS

//init.c
extern void AllInit();

// bitboards.c
extern void PrintBitBoard(U64 bb);

#endif