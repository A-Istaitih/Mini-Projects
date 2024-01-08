#include <stdio.h>
#include "defs.h"

int main(){

    AllInit();

    U64 play = 0ULL;
    printf("Start:\n\n");
    PrintBitBoard(play);

    play |= (1ULL << SQ64(D2));

    printf("D2 Added:\n\n");
    PrintBitBoard(play);

    play |= (1ULL << SQ64(G2));

    printf("G2 Added:\n\n");
    PrintBitBoard(play);
    return 0;
}