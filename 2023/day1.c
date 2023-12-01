#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_BUFFER_LENGTH 1003 // This refers to the line amount, not character

/* gave up after the first star, my god C is hard lmao */

struct lookup {
    char digit[5];
    int value;
};

struct lookup lookuptable[] = {
    {"zero", 0},
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9}
};

int getValue(int key){
    // get value

    return -1;
}

void firstPart(char* buffer, int* firstDigit, int* secondDigit, int* sum){
    *firstDigit = -1;
    *secondDigit = -1;

    // Get first digit
    for(int i = 0; buffer[i] != '\0'; i++){
        if(isdigit(buffer[i])){
            //*firstDigit = atoi(&buffer[i]); /* this fucker does not work */
            *firstDigit = buffer[i] - '0';
            //*firstDigit = buffer[i] - 48;
            break;
        }
    }

    // Get second digit
    for(int i = 0; buffer[i] != '\0'; i++){
        if(isdigit(buffer[i])){
            *secondDigit = buffer[i] - '0';
            //*secondDigit = atoi(&buffer[i]);
        }
    }

    // wtf?
    char combinedValue[3];
    combinedValue[0] = *firstDigit + '0';
    combinedValue[1] = *secondDigit + '0';
    combinedValue[2] = '\0';

    int currentNumber = atoi(combinedValue);
    *sum = *sum + currentNumber;
}

void secondPart(char* buffer, int* firstValue, int* secondValue, int* sum){
    *firstValue = -1;
    *secondValue = -1;

    // Get first digit
    for(int i = 0; buffer[i] != '\0'; i++){
        if(isdigit(buffer[i])){
            //*firstDigit = atoi(&buffer[i]); /* this fucker does not work */
            *firstDigit = buffer[i] - '0';
            //*firstDigit = buffer[i] - 48;
            break;
        }
    }

}

int main(){
    int sum = 0;
    int firstValue, lastValue;
    char buffer[MAX_BUFFER_LENGTH + 1];

    // Get input
    printf("Input:\n");
    for (int lineCount = 0; lineCount < MAX_BUFFER_LENGTH; lineCount++) {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL || buffer[0] == '\n') {
            // Break if user presses enter without input or when N lines are read
            break;
        }

        firstPart(buffer, &firstValue, &lastValue, &sum);
    }

    printf("Sum equals %d \n", sum);
    return 0; 
}
