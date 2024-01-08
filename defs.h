#ifndef DEFS_H // if not defined
#define DEFS_H

#include <stdlib.h>

#define DEBUG 

#ifndef DEBUG
#define ASSERT(n)
#else
#define ASSERT(n) \
if(!(n)) { \
printf("%s - Failed ", #n); \
printf("On %s ",__DATE__); \
printf("At %s ",__TIME__); \
printf("In File %s ",__FILE__); \
printf("At Line %d\n",__LINE__); \
exit(1);}
#endif

typedef unsigned long long U64; //64 squares in chess

#define NAME "Vice 1.0"
#define BRD_SQ_NUM 120 // board + borders that we added

#define MAXGAMEMOVES 2048 //I've searched in Google the max moves of a game is 2048

enum { EMPTY, wP, wN, wB, wR, wQ, wK, bP, bN, bB, bR, bQ, bK }; //pieces of chess
enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE }; //col
enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE }; //row

enum { WHITE, BLACK, BOTH }; //colors

enum {
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_SQ
}; //each square

enum { FALSE,TRUE }; //0 1

//               0 0 0 0 
enum { WKCA = 1, WQCA = 2, BKCA = 4, BQCA = 8 }; //if the Queen/King Castle can "Castling" 1 for yes

typedef struct{

    int move; //the move that have been made
    int castlePerm; //the castle permission
    int enPas;
    int fiftyMove; 
    U64 posKey;

} S_UNDO; //details of a move

typedef struct{
    
    int pieces[BRD_SQ_NUM]; 
    U64 pawns[3]; //3 because there is black, white, both

    int KingSq[2];

    int side;
    int enPas;
    int fiftyMove;

    int ply;
    int hisPly;

    int castlePerm; //castle permission

    U64 posKey; //where the piece was played

    int pceNum[13];
    int bigPce[3];
    int majPce[3];
    int minPce[3];

    S_UNDO history[MAXGAMEMOVES]; //all moves done

    //piece list
    int pList[13][10];


} S_BOARD;

//MACROS

#define FR2SQ(f, r) ((21 + (f)) + ((r) * 10));

//GLOBALS

extern int Sq120ToSq64[BRD_SQ_NUM];
extern int Sq64ToSq120[64];

//FUNCTIONS

extern void AllInit();

#endif