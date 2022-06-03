#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RADIUS (double) 1.0
#define SQUARE_AREA 4

double calculateMonteCarloProbability(int points) {
    int insideCircle = 0;
    int outSideCircle = 0;
    for (int i = 0; i < points; i++) {
        double x = (rand() % RAND_MAX) / (double) RAND_MAX;
        double y = (rand() % RAND_MAX) / (double) RAND_MAX;
        if ((x * x) + (y * y) <= RADIUS) {
            insideCircle++;
        } else {
            outSideCircle++;
        }
    }

    printf("Inside: %d - Outside: %d\n", insideCircle, outSideCircle);
    return insideCircle / (double) (insideCircle + outSideCircle);
}

int argvToInteger(char **argv) {
    int i = 0;

    while (argv[1][i] != '\0') {
        i++;
    }

    char *stringNumber = (char*) malloc(i * sizeof(char));

    for (int j = 0; j < i; j++) {
        stringNumber[j] = argv[1][j];
    }

    int number = atoi(stringNumber);
    free(stringNumber);

    return number;
}

int main(int argc, char** argv) {
    srand(time(NULL));

    if (argc != 2) {
        printf("Enter the amount of points\n");
        return 1;
    }

    printf("Pi: %lf\n", SQUARE_AREA * calculateMonteCarloProbability(argvToInteger(argv)));

    return 0;
}
