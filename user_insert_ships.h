#include <stdio.h>

void insert_ship(char board[11][11]){
    int count_2 = 4;
    int count_3 = 3;
    int count_4 = 2;
    int count_6 = 1;
    int ship_type = 0;

    printf("\nNow its time to put your ships on the board!\n");

    for(int i = 0; i < 1; i++){
        printf("\nPlase choose what type of ship you want to put now on the board:\n1. Small (2 boxes)\n2. Medium (3 boxes)\n3. Large (4 boxes)\n4. Cruiser (6 boxes)\n");
        scanf("%d", &ship_type);


    }
}