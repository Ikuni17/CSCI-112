/* 
 * Bradley White
 * Lab 9, CSCI 112
 * April 30, 2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// constants
#define LINE_SIZE 100

// global variable
const char delim[2] = ",";

// prototype functions
void merge_files();     //merge periodic table to one file
void find_element();    //search merged file for specific element

// start!
int main(int argc, char *argv[]) {
    FILE *inp, *inp2, *outp;  // pointers to inputs and output
    int i; //loop counter

    //open files
    inp = fopen("elements_file1.csv", "r");
    inp2 = fopen("elements_file2.csv", "r");
    outp = fopen("elements.csv", "w");

    //check pointers are reaching files
    if (inp == NULL || inp2 == NULL || outp == NULL) {
        printf("Error loading file.");
        exit(1); // exit with an error if file not found
    }

    //call helper function to merge periodic table into one file
    merge_files(inp, inp2, outp);

    //close file pointers
    fclose(inp);
    fclose(inp2);
    fclose(outp);
    
    //loop through program arguments searching for specific elements
    for (i = 1; i < argc; i++){
        find_element(argv[i]);
    }

    //exit without errors
    return 0;
}

//helper function to merge two csv files into one
void merge_files(FILE *inp, FILE *inp2, FILE *outp) {
    char string1[LINE_SIZE], string2[LINE_SIZE];    //stores an element from each file
    char copy_string1[LINE_SIZE], copy_string2[LINE_SIZE]; //stores a copy for output
    int token1, token2;     //stores atomic number for sorting

    //get an element from each file and create a token from each
    fgets(string1, LINE_SIZE, inp);
    strcpy(copy_string1, string1);
    fgets(string2, LINE_SIZE, inp2);
    strcpy(copy_string2, string2);
    token1 = atoi(strtok(string1, delim));
    token2 = atoi(strtok(string2, delim));

    //loop until EOF is reached for either input file, sorting and writing to output
    while (!feof(inp) && !feof(inp2)) {
        //check which token is smaller, then write it to output file
        if (token1 < token2) {
            fprintf(outp, "%s", copy_string1);  //write to output
            fgets(string1, LINE_SIZE, inp);     //get new string
            strcpy(copy_string1, string1);      //create copy of new string
            token1 = atoi(strtok(string1, delim));  //create new token
        } else if (token2 < token1) {
            fprintf(outp, "%s", copy_string2);
            fgets(string2, LINE_SIZE, inp2);
            strcpy(copy_string2, string2);
            token2 = atoi(strtok(string2, delim));
        }
    }
    
    //finish writing remainder of either file
    if (feof(inp)) {
        while (!feof(inp2)) {
            fprintf(outp, "%s", copy_string2);
            fgets(string2, LINE_SIZE, inp2);
            strcpy(copy_string2, string2);
            token2 = atoi(strtok(string2, delim));
        }
    } else if (feof(inp2)) {
        while (!feof(inp)) {
            fprintf(outp, "%s", copy_string1);
            fgets(string1, LINE_SIZE, inp);
            strcpy(copy_string1, string1);
            token1 = atoi(strtok(string1, delim));
        }
    }

    printf("File merging complete.\n");
}

//search merged file for specific element
void find_element(char input[]) {
    FILE *inp; //pointer to merged file
    char string[LINE_SIZE];     //store string to check against
    char *atomic_number, *atomic_weight, *name, *symbol, *year, *category; //store info about element

    //open input file
    inp = fopen("elements.csv", "r");
    
    //check pointer is populated
    if (inp == NULL) {
        printf("Error loading file.");
        exit(1); // exit with an error if file not found
    }

    //loop until EOF is reached searching for specific element
    while (!feof(inp)) {
        if ((fgets(string, LINE_SIZE, inp) == NULL)) {
            continue;
        } else {
            //split and store each piece of information about an element
            atomic_number = strtok(string, delim);
            atomic_weight = strtok(NULL, delim);
            name = strtok(NULL, delim);
            symbol = strtok(NULL, delim);
            year = strtok(NULL, delim);
            category = strtok(NULL, delim);
        }
        //if the element is found, print the results
        if (strcmp(symbol, input) == 0) {
            printf("\nElement: %s\n", name);
            printf(" Symbol: %s\n", symbol);
            printf(" Atomic Number: %s\n", atomic_number);
            printf(" Atomic Weight: %s\n", atomic_weight);
            //if the year discover is numeric, print the year
            if (strcmp(year, "ancient") != 0) {
                printf(" Discovered in: %s\n", year);
            }
        }
    }

    //close file pointer
    fclose(inp);
}
