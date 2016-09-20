/* 
 * Bradley White
 * Lab 2, CSCI 112
 * 2/6/2015
 */

#include <stdio.h>

// gets the input value from the user
double get_input(void) {
    double input;   // stores the input in a variable

    // prompt the user and store the input
    printf("Enter a value > ");
    scanf("%lf", &input);

    return input;
}

// calculates the next value in the sequence based on the previous two values
double get_next(double first, double second){
    double third;  // stores the result in a variable
    
    // algorithm for finding the next value
    third = (first/2)+(3*second);
    
    return third;
}

// outputs the specified value in the sequence
double print_result(double input){
    
    // prints the desired value formated to two decmal places
    printf("The result is %.2lf\n", input);
    
    return (0);
}

// main function that creates a sequence of five values and prints the last value.
int main(void) {
    double x_1, x_2, x_3, x_4, x_5; // stores the values of the sequence in variables
    
    // prompts the user for the first two values, then calculates the next three.
    x_1 = get_input();
    x_2 = get_input();
    x_3 = get_next(x_1, x_2);
    x_4 = get_next(x_2, x_3);
    x_5 = get_next(x_3, x_4);
    print_result(x_5);  // prints the last value in the sequence.

    return(0);
}