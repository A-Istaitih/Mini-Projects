#include <stdio.h>
#include "defs.h"

int Sq120ToSq64[BRD_SQ_NUM];
int Sq64ToSq120[64];

void InitSq120To64(){
    int index = 0, sq64 = 0;
    int file = FILE_A, rank = RANK_1, sq = A1;

    for(index = 0; index < BRD_SQ_NUM; ++index){//initalizing
        Sq120ToSq64[index] = 65; //I'll never git 65 max 63
    }
    for(index = 0; index < 64; ++index){
        Sq64ToSq120[index] = 120; //I'll never git 120 max 119
    }

    for(rank = RANK_1; rank <= RANK_8; ++rank){//filling the converting arrays
        for(file = FILE_A; file <= FILE_H; ++file){
            sq = FR2SQ(file, rank);
            Sq64ToSq120[sq64] = sq;
            Sq120ToSq64[sq] = sq64;
            sq64++;
        }
    }
}

void AllInit(){
    InitSq120To64();

}