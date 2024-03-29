#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

int main(){

    AllInit(); //Initalizing Arrays
    
    int PieceOne = rand();
    int PieceTwo = rand();
    int PieceThree = rand();
    int PieceFour = rand();

    printf("PieceOne:%X\n", PieceOne);
    printf("PieceTwo:%X\n", PieceTwo);
    printf("PieceThree:%X\n", PieceThree);
    printf("PieceFour:%X\n", PieceFour);

    int Key = PieceOne ^ PieceTwo ^ PieceThree ^ PieceFour;
    int TempKey = PieceOne;
    TempKey ^= PieceThree;
    TempKey ^= PieceFour;
    TempKey ^= PieceTwo;

    printf("key: %X\n", Key);
    printf("tmp: %X\n %lu",TempKey, sizeof(int));

    return 0;
}