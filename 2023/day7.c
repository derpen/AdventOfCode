#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_BUFFER_LENGTH 1000
#define MAX_ROW 5 // Change this when doing real case
#define MAX_COLUMN 2
#define UNIQUE_CARDS 5

int sum = 0;

struct Map {
    char currentCard;
    int cardAmount;
};

int getIndex(struct Map map[], char key){
    for(int i = 0; i < UNIQUE_CARDS; i++){
        if(map[i].currentCard == key){
            return i;
        }
    }
    // not found
    return -1;
}

void insertOrIncrease(struct Map map[], char key, int* map_size){
    // increase
    int index = getIndex(map, key);
    if(index != -1){
        map[index].cardAmount += 1;
        return;
    }

    // not found, add new
    map[*map_size].currentCard = key;
    map[*map_size].cardAmount = 1;
    *map_size += 1;
    map[*map_size].currentCard = '\0';
    //printf("No such value to increase");
}

void insertcards(char * buffer){
    char hand[5];
    int handValue = 0;
    int bid;

    struct Map map[UNIQUE_CARDS]; // keep track of each unique card in hand
    // Initialize map elements
    for (int i = 0; i < UNIQUE_CARDS; i++) {
        map[i].currentCard = '\0';
        map[i].cardAmount = 0;
    }
    int map_size = 0;
    
    if(sscanf(buffer, "%s %d", hand, &bid) != 1){
        // Convert hand into num
        int idx = 0;
        for(int i=0; hand[i] != '\0'; i++){
            if(isdigit(hand[i])){
                handValue += hand[i];
                insertOrIncrease(map, hand[i], &map_size);
            } else {
                if(hand[i] == 'A'){
                    handValue += 14;
                    insertOrIncrease(map, hand[i], &map_size);
                }
                if(hand[i] == 'K'){
                    handValue += 13;
                    insertOrIncrease(map, hand[i], &map_size);
                }
                if(hand[i] == 'Q'){
                    handValue += 12;
                    insertOrIncrease(map, hand[i], &map_size);
                }
                if(hand[i] == 'J'){
                    handValue += 11;
                    insertOrIncrease(map, hand[i], &map_size);
                }
                if(hand[i] == 'T'){
                    handValue += 10;
                    insertOrIncrease(map, hand[i], &map_size);
                }
            }
            idx += 1;
        }
    }

    for(int i = 0; map[i].currentCard != '\0'; i++){
        printf("%d -------------- %c, %d \n", handValue, map[i].currentCard, map[i].cardAmount - 1);
    }

    printf(">>>>>>>>>>>>>>>>>>>>>>>>>\n");
}

int main(){
    char buffer[MAX_BUFFER_LENGTH];

    // Get input from file
    FILE *file;
    char filename[] = "input7test";

    file = fopen(filename, "r");
    if(file == NULL){
        printf("Filename of %s does not exist", filename);
        return 1;
    }

    char currentLine[MAX_BUFFER_LENGTH];
    while(fgets(currentLine, MAX_BUFFER_LENGTH, file)){
        insertcards(currentLine);
    }


    fclose(file);

    return 0;
}
