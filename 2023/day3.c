#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_BUFFER_LENGTH 1000
#define MAX_ROW 140

void part_one(char engine[MAX_BUFFER_LENGTH][MAX_BUFFER_LENGTH], int* sum){
    // [row][column], where positive for x means go down, y positive means go right

    //printf("---------------------------------------------------------- the current matrix ----------------------------------------\n");
    for(int i = 0; i < MAX_BUFFER_LENGTH && i < MAX_ROW; i++){
        char currentNumber[6] = "";
        int validNumber;
        for(int j = 0; j <  MAX_BUFFER_LENGTH; j++){
            if(isdigit(engine[i][j])){
                strncat(currentNumber, &engine[i][j], 1);
            } else {
                if(strlen(currentNumber) > 0) {
                    bool isValid = false;
                    int column;
                    int row;
                    // got the current number, do stuff here

                    // get left character of number
                    column = j - strlen(currentNumber) - 1;
                    if( column >= 0 ) {
                        if(engine[i][column] != '.'){
                            isValid = true;
                        }
                    }

                    // get right character of number
                    column = j;
                    if( column <= MAX_BUFFER_LENGTH ){
                        if(engine[i][column] != '.'){
                            isValid = true;
                        }
                    }
 
                    // get top left diagonally
                    row = i - 1;
                    column = j - strlen(currentNumber) - 1;
                    if(row >= 0 && column >=0) {
                        if(engine[row][column] != '.'){
                            isValid = true;
                        }
                    }

                    // get top right diagonally
                    row = i - 1;
                    column = j;
                    if(row >= 0 && column <= MAX_BUFFER_LENGTH) {
                        if(engine[row][column] != '.'){
                            isValid = true;
                        }
                    }

                    // get bottom left diagonally
                    row = i + 1;
                    column = j - strlen(currentNumber) - 1;
                    if(row < MAX_ROW && column >= 0) {
                        if(engine[row][column] != '.'){
                            isValid = true;
                        }
                    }
                    
                    // get bottom right diagonally
                    row = i + 1;
                    column = j;
                    if(row < MAX_ROW && column <= MAX_BUFFER_LENGTH) {
                        if(engine[row][column] != '.'){
                            isValid = true;
                        }
                    }

                    // check for up and down here
                    for(int x = 0; currentNumber[x] != '\0'; x++){
                        column = j - strlen(currentNumber) + x;
                        int rowUp = i - 1;
                        int rowDown = i + 1;
                        if(rowUp >= 0){
                            if(engine[rowUp][column] != '.'){
                                isValid = true;
                            }
                        }
                        if(rowDown < MAX_ROW){
                            if(engine[rowDown][column] != '.'){
                                isValid = true;
                            }
                        }
                    }

                    if(isValid) {
                        *sum += atoi(currentNumber);
                    }
                }

                // reset
                currentNumber[0] = '\0';
            }
        }
    }
}

int main(){
    int sum = 0;
    char buffer[MAX_BUFFER_LENGTH + 1];

    char engine[MAX_BUFFER_LENGTH][MAX_BUFFER_LENGTH];

    // Get input
    printf("Input:\n");
    for (int i = 0; i < MAX_BUFFER_LENGTH; i++) {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL || buffer[0] == '\n') {
            // Break if user presses enter without input or when N lines are read
            break;
        }

        // read engine
        for(int j = 0; buffer[j] != '\0'; j++){
            engine[i][j] = buffer[j];
        }
    }

    part_one(engine, &sum);

    printf("Sum equals %d \n", sum);
    return 0; 
}
