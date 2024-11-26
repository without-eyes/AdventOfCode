#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    unsigned int length;
    unsigned int width;
    unsigned int height;
} PresentSides;

void convertDimensionsToNumbers(const char* dimensions, PresentSides* presentSides) {
    unsigned int sides[3] = {0};
    int currentSide = 0;

    for (int i = 0; i < strlen(dimensions); i++) {
        if (isdigit(dimensions[i])) sides[currentSide] = sides[currentSide] * 10 + dimensions[i] - '0';
        else currentSide++;
    }

    presentSides->length = sides[0];
    presentSides->width = sides[1];
    presentSides->height = sides[2];
}

unsigned int maxOfThree(const unsigned int first, const unsigned int second, const unsigned int third) {
    if (first >= second && first >= third) return first;
    else if (second >= first && second >= third) return second;
    else return third;
}

void calculateAndAddToWrappingPaperLength(unsigned int* wrappingPaperLength, const PresentSides presentSides) {
    *wrappingPaperLength += 2 * presentSides.length * presentSides.width;
    *wrappingPaperLength += 2 * presentSides.width * presentSides.height;
    *wrappingPaperLength += 2 * presentSides.height * presentSides.length;
    *wrappingPaperLength += presentSides.length * presentSides.width * presentSides.height / maxOfThree(presentSides.length, presentSides.width, presentSides.height);
}

void calculateAndAddToRibbonLength(unsigned int* ribbonLength, const PresentSides presentSides) {
    *ribbonLength += 2 * (presentSides.length + presentSides.width + presentSides.height - maxOfThree(presentSides.length, presentSides.width, presentSides.height));
    *ribbonLength += presentSides.length * presentSides.width * presentSides.height;
}

int main(void) {
    FILE* input = fopen("./input/2015/2.txt", "r");
    char dimensions[20];

    unsigned int wrappingPaperLength = 0;
    unsigned int ribbonLength = 0;
    while (fgets(dimensions, sizeof(dimensions), input)) {
        PresentSides presentSides;
        convertDimensionsToNumbers(dimensions, &presentSides);
        calculateAndAddToWrappingPaperLength(&wrappingPaperLength, presentSides);
        calculateAndAddToRibbonLength(&ribbonLength, presentSides);
    }

    printf("Wrapping paper length: %d\n", wrappingPaperLength);
    printf("Ribbon length: %d\n", ribbonLength);
    return 0;
}