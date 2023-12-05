#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BUFFER_LENGTH 1000

int seeds[10000] = { -1 };
int seedToSoil[10000] = { -1 };
int soilToFert[10000] = { -1 };
int fertToWater[10000] = { -1 };
int waterToLight[10000] = { -1 };
int lightToTemp[10000] = { -1 };
int tempToHum[10000] = { -1 };
int humToLocation[10000] = { -1 };

int a_index = 0;
int s_index = 0;
int d_index = 0;
int f_index = 0;
int g_index = 0;
int h_index = 0;
int j_index = 0;
int k_index = 0;

void partone(char* currentLine, int learray[], int* idx){
    char *stringEnd;
    char *now = strtok_r(currentLine, "\n", &stringEnd);
    while(now != NULL){
        char * xd = strtok(now, " ");
        while(xd != NULL){
            // do stuff here
            
            // -1 as delimiter
            learray[*idx] = atoi(xd);
            *idx += 1;
            learray[*idx] = -1;

            xd = strtok(NULL, " ");
        }
        now = strtok_r(NULL, "\n", &stringEnd);
    }
}

int main(){
    int lowest = 0;
    char buffer[MAX_BUFFER_LENGTH];

    // Get input from file
    FILE *file;
    char filename[] = "input5test";

    file = fopen(filename, "r");
    if(file == NULL){
        printf("Filename of %s does not exist", filename);
        return 1;
    }

    char currentLine[MAX_BUFFER_LENGTH];
    while(fgets(currentLine, MAX_BUFFER_LENGTH, file)){
        // do stuff here
        if(currentLine[0] == 'a'){
            char newLine[MAX_BUFFER_LENGTH];
            while(fgets(newLine, MAX_BUFFER_LENGTH, file) && newLine[0] != '\n'){
                partone(newLine, seeds, &a_index);
            }
        }
        if(currentLine[0] == 's'){
            char newLine[MAX_BUFFER_LENGTH];
            while(fgets(newLine, MAX_BUFFER_LENGTH, file) && newLine[0] != '\n'){
                partone(newLine, seedToSoil, &s_index);
            }
        }
        if(currentLine[0] == 'd'){
            char newLine[MAX_BUFFER_LENGTH];
            while(fgets(newLine, MAX_BUFFER_LENGTH, file) && newLine[0] != '\n'){
                partone(newLine, soilToFert, &d_index);
            }
        }
        if(currentLine[0] == 'f'){
            char newLine[MAX_BUFFER_LENGTH];
            while(fgets(newLine, MAX_BUFFER_LENGTH, file) && newLine[0] != '\n'){
                partone(newLine, fertToWater, &f_index);
            }
        }
        if(currentLine[0] == 'g'){
            char newLine[MAX_BUFFER_LENGTH];
            while(fgets(newLine, MAX_BUFFER_LENGTH, file) && newLine[0] != '\n'){
                partone(newLine, waterToLight, &g_index);
            }
        }
        if(currentLine[0] == 'h'){
            char newLine[MAX_BUFFER_LENGTH];
            while(fgets(newLine, MAX_BUFFER_LENGTH, file) && newLine[0] != '\n'){
                partone(newLine, lightToTemp, &h_index);
            }
        }
        if(currentLine[0] == 'j'){
            char newLine[MAX_BUFFER_LENGTH];
            while(fgets(newLine, MAX_BUFFER_LENGTH, file) && newLine[0] != '\n'){
                partone(newLine, tempToHum, &j_index);
            }
        }
        if(currentLine[0] == 'k'){
            char newLine[MAX_BUFFER_LENGTH];
            while(fgets(newLine, MAX_BUFFER_LENGTH, file) && newLine[0] != '\n'){
                partone(newLine, humToLocation, &k_index);
            }
        }
    }

    for(int i = 0; seeds[i] != -1; i++){
        printf("%d \n", seeds[i]);
    }

    printf("----------------------------- \n");

    for(int i = 0; seedToSoil[i] != -1; i++){
        printf("%d \n", seedToSoil[i]);
    }

    printf("----------------------------- \n");

    for(int i = 0; soilToFert[i] != -1; i++){
        printf("%d \n", soilToFert[i]);
    }

    printf("----------------------------- \n");

    for(int i = 0; fertToWater[i] != -1; i++){
        printf("%d \n", fertToWater[i]);
    }

    printf("----------------------------- \n");
    for(int i = 0; waterToLight[i] != -1; i++){
        printf("%d \n", waterToLight[i]);
    }

    printf("----------------------------- \n");
    for(int i = 0; lightToTemp[i] != -1; i++){
        printf("%d \n", lightToTemp[i]);
    }

    printf("----------------------------- \n");
    for(int i = 0; tempToHum[i] != -1; i++){
        printf("%d \n", tempToHum[i]);
    }

    printf("----------------------------- \n");
    for(int i = 0; humToLocation[i] != -1; i++){
        printf("%d \n", humToLocation[i]);
    }

    fclose(file);

    //printf("Sum is %d", lowest);

    return 0;
}
