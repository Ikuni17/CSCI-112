/* 
 * Bradley White
 * Lab 4, CSCI 112
 * 2/26/2015
 */

#include <stdio.h>
#include <math.h>

// constants
#define PI 3.14159
#define LOOP_LIMIT 90

// enumerated type for menu functions
typedef enum MENU {
    Sine, Cosine, Tangent, QUIT
} menu_t;

// prototype functions
int get_input(void);
menu_t user_menu(menu_t input);
double convert_radians(int degrees);
double sine(void);
double cosine(void);
double tangent(void);

// start!
int main(void) { 
    get_input();
    return 0;
}

// prompts the user until a valid input is received. user_menu function is called to check validity.
int get_input(void) {
    menu_t input;

    do {
        // prompt the user and store the input
        printf("Please choose an option: (0) Sine (1) Cosine (2) Tangent (3) QUIT\n");
        printf("Enter your choice > ");
        scanf("%d", &input);
    } while (!(user_menu(input))); // continues looping until user_menu returns true

    return 0;
}

// menu function to handle user input cases
menu_t user_menu(menu_t input) {
    switch (input) {
        case Sine:
            sine();         // calls sine function of this program
            return 0;       // returns false to continue looping get_input function

        case Cosine:
            cosine();       // calls cosine function of this program
            return 0;       // returns false to continue looping get_input function

        case Tangent:
            tangent();      // calls tangent function of this program
            return 0;       // returns false to continue looping get_input function

        case QUIT:
            printf("You chose QUIT. Thank you, come again!\n");
            return 1;       // return true to end looping get_input function

        default:
            printf("%d is an invalid option. Please try again.\n\n", input);
            return 0;       // states invalid input and continues looping get_input function
    }
}

// function to convert degrees into radians for use with math.h trigonometric functions
double convert_radians(int degrees) {
    double radians;

    return radians = (PI * degrees) / 180;

    //return radians;
}

// function to calculate increments of 15 degrees of Sine and print the results
double sine() {
    int i;              // iteration of loop and amount of degrees to be calculated
    double answer;      // calculated result

    for (i = 0; i <= LOOP_LIMIT; i += 15) {
        answer = sin(convert_radians(i));            // converts degrees to radians then passes to math.h functions
        printf("\tsin(%d) = %.4lf\n", i, answer);    // prints the result to four decimal places
    }
    printf("\n");
    return 0;
}

// function to calculate increments of 15 degrees of Cosine and print the results
double cosine() {
    int i;              // iteration of loop and amount of degrees to be calculated
    double answer;      // calculated result

    for (i = 0; i <= LOOP_LIMIT; i += 15) {
        answer = cos(convert_radians(i));           // converts degrees to radians then passes to math.h functions
        printf("\tcos(%d) = %.4lf\n", i, answer);   // prints the result to four decimal places
    }
    printf("\n");
    return 0;
}

// function to calculate increments of 15 degrees of Tangent and print the results
double tangent() {
    int i;              // iteration of loop and amount of degrees to be calculated
    double answer;      // calculated result

    for (i = 0; i <= LOOP_LIMIT; i += 15) {
        // catches special cases where tangent is undefined
        if (i == 90 || i == 270) {
            printf("\ttan(%d) is UNDEFINED\n", i);
        } else {
            answer = tan(convert_radians(i));            // converts degrees to radians then passes to math.h functions
            printf("\ttan(%d) = %.4lf\n", i, answer);   // prints the result to four decimal places
        }
    }
    printf("\n");
    return 0;
}