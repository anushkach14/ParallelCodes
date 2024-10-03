#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define SIZE 1000

int main() {
    int array[SIZE];
    int max_val;

    // Parallel region for generating random numbers
    #pragma omp parallel
    {
        // Get the thread ID
        int thread_id = omp_get_thread_num();
        
        // Set a unique seed for each thread using time and thread_id with an offset
        unsigned int seed = time(NULL) + thread_id * 100;
        srand(seed);

        #pragma omp for
        for (int i = 0; i < SIZE; i++) {
            array[i] = rand() % 10000;  // Random number between 0 and 9999
        }
    }

    // Set initial maximum to the first element of the array
    max_val = array[0];

    // Parallel region to find the maximum value using OpenMP
    #pragma omp parallel for reduction(max:max_val)
    for (int i = 0; i < SIZE; i++) {
        if (array[i] > max_val) {
            max_val = array[i];
        }
    }

    // Print the maximum value
    printf("The maximum value in the array is: %d\n", max_val);

    return 0;
}
