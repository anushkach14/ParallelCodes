#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define SIZE 1000  // Array size

int main() {
    int arr[SIZE];
    int i;
    int max_value;

    // Seed the random number generator
    srand(time(NULL));

    // Fill the array with random integers between 1 and 10000
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 10000 + 1;
    }

    // Initialize the max_value variable
    max_value = arr[0];

    // Use OpenMP to parallelize the search for the maximum value
    #pragma omp parallel for reduction(max:max_value)
    for (i = 1; i < SIZE; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }

    // Print the maximum value found
    printf("Maximum value in the array: %d\n", max_value);

    return 0;
}
