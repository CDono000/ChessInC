#include <cstdint>
#include <string>

typedef uint64_t U64; // aliases an unsigned 64 bit integer to U64

U64 board = 0x0000000000000000ULL; // Hex number (64 bits) (0x 16 0s ULL)
// Starts at black corner (a8)

// White Pieces
U64 whitePawns = 0x000000000000FF00ULL;
U64 whiteKnights = 0x0000000000000042ULL;
U64 whiteBishops = 0x0000000000000024ULL;
U64 whiteRooks = 0x0000000000000081ULL;
U64 whiteQueens = 0x0000000000000008ULL;
U64 whiteKing = 0x0000000000000010ULL;
U64 whitePieces = whitePawns | whiteKnights | whiteBishops | whiteRooks | whiteQueens | whiteKing;

// Black Pieces
U64 blackPawns = 0x00FF000000000000ULL;
U64 blackKnights = 0x4200000000000000ULL;
U64 blackBishops = 0x2400000000000000ULL;
U64 blackRooks = 0x8100000000000000ULL;
U64 blackQueens = 0x0800000000000000ULL;
U64 blackKing = 0x1000000000000000ULL;
U64 blackPieces = blackPawns | blackKnights | blackBishops | blackRooks | blackQueens | blackKing;

U64 occupied = whitePieces | blackPieces;
U64 unOccupied = ~occupied;