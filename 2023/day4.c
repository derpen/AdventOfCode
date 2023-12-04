#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_BUFFER_LENGTH 1000

// Map is not needed actually, a simple array would do just fine Lmao xP
struct Map {
    int value;
};

struct Map map[10];

void partone(char* buffer, int* sum){
    char *firstSplit, *firstSplitEnd;
    firstSplit = strtok_r(buffer, "|", &firstSplitEnd);

    int cardValue = 0;
    int nextFree = 0;

    // Split into two, first the | and second the whitespace
    while(firstSplit != NULL){
        char * secondSplit = strtok(firstSplit, " ");
        while(secondSplit != NULL){
            // got each element, input all into map. When duplicate is found, add 1 to cardValue
            //printf("%s \n", secondSplit);

            bool duplicateFound = false;

            for(int i=0; i <= nextFree; i++){
                if(map[i].value == atoi(secondSplit)){
                    cardValue += 1;
                    duplicateFound = true;
                    printf("Duplicate found on %s \n", secondSplit);
                    break;
                } 
            }
            
            if(!duplicateFound){
                map[nextFree].value = atoi(secondSplit);
                nextFree += 1;
            }

            secondSplit = strtok(NULL, " ");
        }
        firstSplit = strtok_r(NULL, "|", &firstSplitEnd);
    }

    if(cardValue > 0){
        double currentSum = pow(2, cardValue - 1);
        printf("current sum is equal to %f \n", currentSum);
        *sum += (int) (currentSum);
    }
}

int main(){
    int sum = 0;
    char buffer[MAX_BUFFER_LENGTH];

    // Get input from file
    FILE *file;
    char filename[] = "input4";

    file = fopen(filename, "r");
    if(file == NULL){
        printf("Filename of %s does not exist", filename);
        return 1;
    }

    char currentLine[MAX_BUFFER_LENGTH];
    while(fgets(currentLine, MAX_BUFFER_LENGTH, file)){
        // do stuff here
        partone(currentLine, &sum);
    }

    fclose(file);

    printf("Sum is %d", sum);

    return 0;
}
