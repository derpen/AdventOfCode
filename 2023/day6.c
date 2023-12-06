#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BUFFER_LENGTH 1000
#define RACE_AMOUNT 4 //  !!!!!!!!!!!--- change to 4 for real data --- !!!!!!!!!!!
#define MAX_ROW 2 // time and distance

// gave up on part 2
// PART 2 NEED THIS TO BE LONG INSTEAD OF INT. THEY GOT ME. RAAAAAAAAAAAAAGH
int racetime[MAX_ROW][RACE_AMOUNT];

int row = 0;
void inputToArray(char* buffer, int* sum){
    char *firstsplit, *secondsplit;
    char *line = strtok_r(buffer, "\n", &secondsplit);
    while(line != NULL){
        char * currentNum = strtok(line, " ");
        int idx = 0;
        while(currentNum != NULL){
            racetime[row][idx] = atoi(currentNum);
            idx += 1;
            currentNum = strtok(NULL, " ");
        }
        row += 1;
        line = strtok_r(NULL, "\n", &secondsplit);
    }
}

int main(){
    int sum = 1;
    char buffer[MAX_BUFFER_LENGTH];

    // Get input from file
    FILE *file;
    char filename[] = "input6";

    file = fopen(filename, "r");
    if(file == NULL){
        printf("Filename of %s does not exist", filename);
        return 1;
    }

    char currentLine[MAX_BUFFER_LENGTH];
    while(fgets(currentLine, MAX_BUFFER_LENGTH, file)){
        inputToArray(currentLine, &sum);
    }

    fclose(file);

  //  // Part One
  //  // Do stuff here
  //  for(int column = 0; column < RACE_AMOUNT; column++) {
  //      for(int row = 0; row < MAX_ROW - 1; row++){
  //          int winning = 0;
  //          int firstNum = racetime[row][column];
  //          int secondNum = racetime[row+1][column];

  //          for(int i = 1; i < firstNum; i++){
  //              int d = i * (firstNum - i);
  //              if(d > secondNum){
  //                  winning += 1;
  //              }
  //          }

  //          sum *= winning;
  //      }
  //  }

  //  printf("Part one Sum is %d", sum);

    // Part two
    // Assign to array first
    int xd[2];
    int xd_index = 0;
    for(int row = 0; row < MAX_ROW; row++){
        char combined[15];
        int idx = 0;
        for(int column = 0; column < RACE_AMOUNT; column++) {
            int a = racetime[row][column];
            idx += sprintf(combined + idx, "%d", a);
        }
        xd[xd_index] = atoi(combined);
        xd_index += 1;
    }

    printf("%d \n", xd[0]);
    printf("%d \n", xd[1]);

 //  int winning = 0;
 //  int sum2 = 1;
 //  for(int i = 1; i < xd[0]; i++){
 //      int d = i * (xd[0] - i);
 //      if(d > xd[1]){
 //          winning += 1;
 //      }

 //  }
 //  
 //  sum2 *= winning;

//   printf("Part two Sum is %d", sum2);

    return 0;
}
