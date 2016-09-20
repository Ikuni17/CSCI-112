/* 
 * Bradley White
 * Lab 7, CSCI 112
 * April 15, 2015
 */

#include <stdio.h>

// constants
#define MAX_ARRAY_SIZE 50

// prototype functions
int populate_array(int array[]); // Fill array with values from user
void print_array(int array[], int n); // Print out the array values
void swap(int array[], int index1, int index2); // Swap two array elements
void quicksort(int array[], int low, int high); // Sorting algorithm
int partition(int array[], int low, int high); // Find the partition point

// start!
int main(void) {
    int n; // stores the amount of integers specified by the user
    int array[MAX_ARRAY_SIZE]; // array of user input integers

    n = populate_array(array);
    printf("\nThe initial array contains:\n");
    print_array(array, n); // prints initial data
    quicksort(array, 0, (n - 1)); // starts quicksort recursion
    printf("\nThe array is now sorted:\n");
    print_array(array, n); // prints sorted data

    return 0;
}

// fill the array with user input
int populate_array(int array[]) {
    int n, i;
    int valid = 0; // flag for valid input, defaults to invalid

    // loops until a valid input is received
    do {
        // prompt user and store inputs
        printf("Enter the value of n > ");
        scanf("%d", &n);

        // check if input is valid
        if (n < 1) {
            printf("%d is under the minimum array size. Please try again.\n\n", n);
        } else if (n > MAX_ARRAY_SIZE) {
            printf("%d exceeds the maximum array size. Please try again.\n\n", n);
        } else {
            valid = 1;
        }

    } while (valid != 1);

    // loop to populate the array with n user specified variables
    printf("Enter %d integers (positive, negative, or zero) >\n", n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &array[i]);
    }

    return n;
}

// loop to print the array
void print_array(int array[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("%+5d\n", array[i]);
    }
}

// helper swap function
void swap(int array[], int index1, int index2) {
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

// quicksort recursion with base case when low = high
void quicksort(int array[], int low, int high) {
    int pivot;

    // continue recursion until the array is size 1
    if (low < high) {
        pivot = partition(array, low, high);    // "divide and conquer" the array
        quicksort(array, low, (pivot - 1));     // quicksort each half
        quicksort(array, (pivot + 1), high);
    }
}

// finds the pivot point
int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    int j;

    // loop to find the proper element for a pivot
    for (j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i = (i + 1);
            swap(array, i, j);
        }
    }
    
    // puts the pivot in the last element
    swap(array, (i + 1), high);
    return (i + 1);
}