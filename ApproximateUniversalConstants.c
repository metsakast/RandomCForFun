#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float randomNumberGen(float l, float h) {

    float randomNum = l + (float)rand() / RAND_MAX * (h - l);
    return randomNum;
}

float eApproximation(int simulatedIterations) {

    float trials = 0.0f;
    float totalNumbers = 0.0f;

    for (int i = 0; i < simulatedIterations; i++) {
        float sum = 0.0f;
        while (1) {
            totalNumbers++;
            sum += randomNumberGen(0.0f, 1.0f);
            if (sum >= 1) break;
        }
        trials++;
    }
    return (totalNumbers/trials);
}

float piApproximation(int simulatedPoints) {
    int insidePoints = 0;

    for (int i = 0; i < simulatedPoints; i++) {
        float x = randomNumberGen(0.0f, 1.0f);
        float y = randomNumberGen(0.0f, 1.0f);
        if (x*x + y*y <= 1) insidePoints++;
    }
    return 4.0f * insidePoints / simulatedPoints;
}

float sqrtTwoApproximation(int simulatedIterations) {
    float starter = 1.5f;
    float average;
    for (int i = 0; i < simulatedIterations; i++) {
        float tempValue = 2.0f / starter;
        average = (starter + tempValue)/2.0f;
        starter = 2.0f / starter;
    }
    return average;
}

int main() {
    srand(time(NULL));

    int userChoice;
    int simulatedIterations;
    int simulatedPoints;

    while (1) {
        printf("What would you like to approximate?\n1) e\n2) pi\n3) sqrt(2)\n4) quit\n");
        scanf(" %d", &userChoice);
        switch (userChoice) {
            case 4:
                return 1;
            case 1:
                printf("Enter the simulated iterations count: ");
                scanf(" %d", &simulatedIterations);
                printf("e approximation using %d iterations is: %f\n", simulatedIterations, eApproximation(simulatedIterations));
                break;
            case 2:
                printf("Enter the simulated points count: ");
                scanf(" %d", &simulatedPoints);
                printf("Pi approximation using %d points is: %f\n", simulatedPoints, piApproximation(simulatedPoints));
                break;
            case 3:
                printf("Enter the simulated iterations count: ");
                scanf(" %d", &simulatedIterations);
                printf("sqrt(2) approximation using %d iterations is: %f\n", simulatedIterations, sqrtTwoApproximation(simulatedIterations));
                break;
        }
    }
}
