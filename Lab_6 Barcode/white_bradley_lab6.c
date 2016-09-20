/* 
 * Bradley White
 * Lab 6, CSCI 112
 * March 20, 2015
 */

#include <stdio.h>

// constants
#define ARRAY_LIMIT 12      // size of array to store barcode

// prototype functions
void user_menu(int []); // prompts user input
int sum_odds(int []); // sums odd indices of the barcode and multiples by 3
int sum_evens(int []); // sums even indices of the barcode
void validate(int, int[]); // calculates check digit and checks validity

// start!

int main(void) {
    int array[ARRAY_LIMIT] = {0}; // stores barcode in an array
    int odds, evens, total = 0; // stores sums of indices

    user_menu(array); // prompt user for a barcode
    odds = sum_odds(array); // get sum of odds from function
    evens = sum_evens(array); // get sum of evens from function
    total = odds + evens; // calculate total sum, then print it out
    printf("STEP 3: Total sum is %d\n", total);
    validate(total, array); // check validity

    return 0;
}

// function to prompt user for barcode and store within the array
void user_menu(int array[]) {
    int i, j; // counters for loops

    // loop to store user input into the array
    printf("Enter a bar code to check. Separate digits with a space >\n");
    for (i = 0; i < ARRAY_LIMIT; ++i) {
        scanf("%d", &array[i]);
    }

    // loop to print the barcode
    printf("\nYou entered the code: ");
    for (j = 0; j < ARRAY_LIMIT; j++) {
        printf("%d ", array[j]);
    }
}

// function to calculate the sum of odd indices of the barcode and multiply by three
int sum_odds(int array[]) {
    int sum = 0, i;

    // loop to sum that increments by two
    for (i = 0; i < ARRAY_LIMIT; i += 2) {
        sum += array[i];
    }

    sum = (sum * 3);
    printf("\nSTEP 1: Sum of odds times 3 is %d\n", sum);
    return sum;
}

// function to calculate the sum of even indices of barcode
int sum_evens(int array[]) {
    int sum = 0, i;

    // loop to sum that increments by two
    for (i = 1; i < (ARRAY_LIMIT - 1); i += 2) {
        sum += array[i];
    }

    printf("STEP 2: Sum of the even digits is %d\n", sum);
    return sum;
}

// function to calculate the check digit and test validity of the barcode
void validate(int total, int array[]) {
    int check_digit; // stores the check digit

    check_digit = (total % 10); // stores the remainder after dividing by 10

    // if check digit is NOT 0, subtract it from 10
    if (check_digit != 0) {
        check_digit = (10 - check_digit);
    }

    // display check digit
    printf("STEP 4: Calculated check digit is %d\n", check_digit);

    // tests if the calculated check digit is equal to the actual check digit from the barcode, which is the last digit of the barcode.
    // then displays the result.
    if (check_digit == array[ARRAY_LIMIT - 1]) {
        printf("STEP 5: Check digit and last digit match\n");
        printf("Barcode is VALID.\n");
    } else {
        printf("STEP 5: Check digit and last digit do NOT match\n");
        printf("Barcode is INVALID.\n");
    }
}