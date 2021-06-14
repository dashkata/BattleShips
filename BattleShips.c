#include <stdio.h>
#include "BattleShipsConfigurations.h"





int main(){

    FILE *file = fopen("config1.bin", "wb");
    int config1[2][3][2] = 
    {
        {{3,4}, {3,5}, {3,6}},
        {{6,7}, {6,8}, {6,9}}

    };
    fwrite(config1, sizeof(config1[0]), 2, file);
    for(int i = 0; i < 3; i++){
        fread(config1, sizeof(config1[0]), 1, file); 
        printf("%d", config1[i]);

    }

    fclose(file);


    // board();
    
    return 0;
}