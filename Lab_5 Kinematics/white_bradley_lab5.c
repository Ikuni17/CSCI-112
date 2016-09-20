/* 
 * Bradley White
 * Lab 5, CSCI 112
 * March 16, 2015
 */

#include <stdio.h>
#include <math.h>

// prototype functions

// Displays user menu, reads input, and validates the input
int user_menu();

// Equation functions are pass by reference
void equation1(float *); // Calculate motion equation 1
void equation2(float *); // Calculate motion equation 2
void equation3(float *); // Calculate motion equation 3
void equation4(float *); // Calculate motion equation 4

// User input functions return a value from user
float get_position_initial(void); // Prompts user for x0
float get_position_final(void); // Prompts user for xf
float get_velocity_initial(void); // Prompts user for v0
float get_velocity_final(void); // Prompts user for vf
float get_acceleration(void); // Prompts user for a
float get_time(void); // Prompts user for t

int main(void) {
    // Print welcome message
    printf("Welcome to the MOTION EQUATION CALCULATOR\n\n");

    int user_choice; // Variable for the user choice from menu
    
    do {
        user_choice = user_menu(); // Print menu , validate choice is between 1 and 5

        // You will pass the address of this variable to your equation functions
        float result; // Variable to hold calculated result

        // Handle menu choice selected by user
        switch (user_choice) {
            case 1:
                equation1(&result);
                break;
            case 2:
                equation2(&result);
                break;
            case 3:
                equation3(&result);
                break;
            case 4:
                equation4(&result);
                break;
            case 5:
                // Exit program if user selects QUIT
                printf("Thank you for using the MOTION EQUATION CALCULATOR. Goodbye.\n");
                return 0;
                break;
        }

        // Print out the calculated result with four digits after the decimal point
        printf("Your result is %.4f.\n\n", result);
    } while (user_choice != 5); // Repeat until user chooses QUIT

    return 0; // Return without error
}

// function to prompt user input, and check validation
int user_menu() {
    int input;          // stores user input
    int valid = 0;      // flag for valid input, defaults to invalid

    do {
        // prompt user and store inputs
        printf("Choose a motion equation 1-4 or choose 5 to QUIT > ");
        scanf("%d", &input);

        // check if input is between 1 and 5, otherwise ask again
        if (input >= 1 && input <= 5) {
            valid = 1;
        } else
            printf("Invalid option. Please try again.\n\n");

    } while (valid != 1);
    
    // returns valid input
    return input;
}

// six functions to prompt the user for variables for use in equation functions
// prompt user for initial position
float get_position_initial(void) {
    float input;

    printf("\tEnter initial position > ");
    scanf("%f", &input);

    return input;
}

// prompt user for final position
float get_position_final(void) {
    float input;

    printf("\tEnter final position > ");
    scanf("%f", &input);

    return input;
}

// prompt user for initial velocity
float get_velocity_initial(void) {
    float input;

    printf("\tEnter initial velocity > ");
    scanf("%f", &input);

    return input;
}

// prompt user for final velocity
float get_velocity_final(void) {
    float input;

    printf("\tEnter final velocity > ");
    scanf("%f", &input);

    return input;
}

// prompt user for acceleration
float get_acceleration(void) {
    float input;

    printf("\tEnter acceleration > ");
    scanf("%f", &input);

    return input;
}

// prompt user for time
float get_time(void) {
    float input;

    printf("\tEnter time > ");
    scanf("%f", &input);

    return input;
}

// calculates final velocity
void equation1(float *result) {
    // prompt user for needed variables
    float v0 = get_velocity_initial();
    float acc = get_acceleration();
    float time = get_time();

    // stores final velocity in memory where result is pointing
    *result = v0 + (acc * time);
}

// calculates final position
void equation2(float *result) {
    // prompt user for needed variables
    float x0 = get_position_initial();
    float v0 = get_velocity_initial();
    float time = get_time();
    float acc = get_acceleration();

    // stores final position in memory where result is pointing, math.h function is called for squaring
    *result = x0 + (v0 * time) + (0.5 * acc * pow(time, 2));
}

// calculates final velocity with different variables
void equation3(float *result) {
    // prompt user for needed variables
    float v0 = get_velocity_initial();
    float acc = get_acceleration();
    float xf = get_position_final();
    float x0 = get_position_initial();

    // stores final velocity in memory where result is pointing, math.h function is called for square root and squaring
    *result = sqrt(pow(v0, 2) + (2 * acc * (xf - x0)));
}
// calculates final position
void equation4(float *result) {
    // prompt user for needed variables
    float x0 = get_position_initial();
    float vf = get_velocity_final();
    float v0 = get_velocity_initial();
    float time = get_time();

    // stores final position in memory where result is pointing
    *result = x0 + (0.5 * (vf + v0)) * time;
}