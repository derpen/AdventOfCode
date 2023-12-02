#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_BUFFER_LENGTH 150
#define MAX_RED 12
#define MAX_GREEN 13
#define MAX_BLUE 14

// part one input has been modified slightly manually with regex and vim to make life easier :3
// of course, I can't do part two cause this already take an hour or so, holy shit C is fkin hard

void part_one(char* buffer, int* sum, int i){
    char *split1, *split2;
    split1 = strtok_r(buffer, ";", &split2);

    bool shouldBeCounted;

    while(split1 != NULL){
       char * new = strtok(split1, " , ");
       int currentValue = 0;
       bool isValid = true;

       while(new != NULL) {
           for(int x = 0; new[x] != '\0'; x++){
               if(isdigit(new[x])){
                   currentValue = atoi(&new[x]);
                   break;
               }  else {
                  if(new[0] == 'r'){
                      if(currentValue > MAX_RED){
                          isValid = false;
                          break;
                      }
                  }
                  if(new[0] == 'g'){
                      if(currentValue > MAX_GREEN){
                          isValid = false;
                          break;
                      }
                  }
                  if(new[0] == 'b'){
                      if(currentValue > MAX_BLUE){
                          isValid = false;
                          break;
                      }
                  }
               }
           }
           
           new = strtok(NULL, " , ");
       }

       if(!isValid){
           shouldBeCounted = false;
           return;
       }
        
       // go to next element
       split1 = strtok_r(NULL, ";", &split2);
    }

    *sum += i + 1;
}

int main(){
    int sum = 0;
    char buffer[MAX_BUFFER_LENGTH + 1];

    // Get input
    printf("Input:\n");
    for (int i = 0; i < MAX_BUFFER_LENGTH; i++) {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL || buffer[0] == '\n') {
            // Break if user presses enter without input or when N lines are read
            break;
        }

        part_one(buffer, &sum, i);
    }

    printf("Sum equals %d \n", sum);
    return 0; 
}
