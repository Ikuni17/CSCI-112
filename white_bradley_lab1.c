/*
 * Bradley White
 * Lab 1, CSCI 112
 * 01/28/2015
 */

#include <stdio.h>

int main(void){
	double fahrenheit, // temperature in Fahrenheit
	       celsius;    // temperature in Celsius

	// get the temperature in Fahrenheit
	printf("Enter a temperature in degrees Fahrenheit > ");
	scanf("%lf", &fahrenheit);

	// convert the temperature to Celsius
	celsius = (fahrenheit - 32) * (5.0/9);

	// display the temperature in Celsius
	printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", 
		fahrenheit, celsius);
	
	printf("\n"); // blank line for read ability

	// get the temperature in Celsius
	printf("Enter a temperature in degrees Celsius > ");
	scanf("%lf", &celsius);

	// covert the temperature to Fahrenheit
	fahrenheit = (celsius * (9.0/5)) + 32;

	// display the temperature in Fahrenheit
	printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n",
		celsius, fahrenheit);

	return(0);
}
