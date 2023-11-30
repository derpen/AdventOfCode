#include <stdio.h>

int main(){
    char buffer[256];

    printf("Enter your text (press Enter twice to finish):\n");

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (buffer[0] == '\n') {
            break;
        }
        printf("You entered: %s", buffer);
    }

    return 0; 
}
