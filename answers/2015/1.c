#include <stdio.h>
#include <string.h>
#define MAX_STRING_SIZE 10000

int main(void) {
    FILE* input = fopen("./input/2015/1.txt", "r");
    char buffer[MAX_STRING_SIZE];
    fgets(buffer, MAX_STRING_SIZE, input);

    int floor = 0;
    int basementEntrance = -1;
    for (int i = 0; i < strlen(buffer); i++) {
        if (buffer[i] == '(') {
            floor++;
        }
        else if (buffer[i] == ')') {
            floor--;
        }

        if (floor == -1 && basementEntrance == -1) {
            basementEntrance = i + 1;
        }
    }

    printf("Final floor: %d\n", floor);
    printf("Basement entrance: %d\n", basementEntrance);

    fclose(input);
    return 0;
}
