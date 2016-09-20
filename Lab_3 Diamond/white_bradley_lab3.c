/* 
 * Bradley White
 * Lab 3, CSCI 112
 * 2/23/2015
 */

#include <stdio.h>

// prototype functions
int get_input(void);
int is_valid(int input);
int print_pattern(int input);

int main(void) {
    int valid_input;

    valid_input = get_input();      // calls the get_input function and stores the result
    print_pattern(valid_input);     // calls the print_pattern function with the result
    return (0);
}

// prompts the user until a valid input is received. is_valid function is called to check validity.
int get_input(void) {
    int input;

    do {
        // prompt the user and store the input
        printf("Enter an odd number less than or equal to 9 and greater than 0 > ");
        scanf("%d", &input);
    } while (!(is_valid(input)));   // continues looping until is_valid returns true
    printf("\n");

    return input;
}

// series of if statements to check if the user input is within the acceptable range.
int is_valid(int input) {
    if ((input % 2) == 0) {
        printf("You have entered an even number. Please try again.\n");
        return 0;
    } else if (input > 9) {
        printf("You have entered a number greater than 9. Please try again.\n");
        return 0;
    } else if (input < 1) {
        printf("You have entered a number less than 1. Please try again.\n");
        return 0;
    } else {
        return 1;       // returns true if the input passes the previous arguments
    }
}

// dynamically prints a diamond pattern based on the users valid input. 
int print_pattern(int input) {
    int i, j;       // counters for each loop
    
    // nested loop to print the top half and middle row of the diamond
    for (i = 1; i <= input; i += 2) {
        printf("%*s", (input - i), "");     // creates appropriate white space based on the current row
        j = 1;                              // resets the first number of each row to 1
        while (j <= i) {                    // while loop to print the numbers for each row
            printf("%d ", j);
            j++;
        }
        printf("\n");
    }

    // nested loop to print the bottom half of the diamond
    for (i = (input - 2); i >= 1; i -= 2) {
        printf("%*s", (input - i), "");     // creates appropriate white space based on the current row
        j = 1;                              // resets the first number of each row to 1
        while (j <= i) {                    // while loop to print the numbers for each row
            printf("%d ", j);
            j++;
        }
        printf("\n");
    }
    
    return (0);
}