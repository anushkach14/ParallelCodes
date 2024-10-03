#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define SIZE 1000

int main() {
    int vector_a[SIZE], vector_b[SIZE], result[SIZE];

    srand(time(NULL));

    // Initialize the vectors with random values between 0 and 100
    for (int i = 0; i < SIZE; i++) {
        vector_a[i] = rand() % 100; 
        vector_b[i] = rand() % 100; 
    }

    #pragma omp parallel for
    for (int i = 0; i < SIZE; i++) {
        result[i] = vector_a[i] - vector_b[i];  
    }

    printf("Vector A\tVector B\tResult\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d\t\t%d\t\t%d\n", vector_a[i], vector_b[i], result[i]);
    }

    return 0;
}
