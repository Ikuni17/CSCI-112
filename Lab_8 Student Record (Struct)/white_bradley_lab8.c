/* 
 * Bradley White
 * Lab 8, CSCI 112
 * April 23, 2015
 */

#include <stdio.h>
#include <stdlib.h>

// constants
#define NAME_SIZE 25

// type definition
typedef struct{
    int sid;                // student ID
    char last[NAME_SIZE];   // student last name
    char first[NAME_SIZE];  // student first name
    float* grades;          // student grades
    float gpa;              // student GPA
} student;

// prototype functions
student get_info(int num_grades);   // prompt user to enter student info
float get_gpa(student record, int num_grades);  // calculates student's GPA
void print_records(student*, int num_students, int num_grades); // print all student records stored

// start!
int main(void) {
    int num_students, num_grades, i;
    student* student_array;         // pointer to the beginning of the student array

    // prompt the user for the number of students
    printf("Enter the number of students:> ");
    scanf("%d", &num_students);
    
    // prompt the user for the number of grades per student
    printf("Enter the number of grades to track:> ");
    scanf("%d", &num_grades);
    
    // allocate memory for student array
    student_array = (student *) malloc(num_students * sizeof(student));
        
    // print user defined amounts
    printf("\nThere are %d students.\n", num_students);
    printf("There are %d grades.\n", num_grades);
    
    // loop for getting students specific data and store into the array of students
    for(i = 0; i < num_students; i++){
        *(student_array + i) = get_info(num_grades);
    }
    
    // print all student records
    print_records(student_array, num_students, num_grades);
    
    // free student array memory
    free(student_array);
    
    return 0;
}

// prompt user to enter student info
student get_info(int num_grades){
    student temp;       // temp variable to store info until main stores in student array
    int i;
    
    // prompt user for info and store in proper place of temp student
    printf("\nEnter information for student:\n");
    printf("\tEnter SID:> ");
    scanf("%d", &temp.sid);
    printf("\tEnter last name:> ");
    scanf("%s", &temp.last);
    printf("\tEnter first name:> ");
    scanf("%s", &temp.first);
    
    // allocate memory for each students grade array
    temp.grades = (float *) malloc(num_grades * sizeof(float));
    
    // loop to store grades, dynamic based on user needs
    printf("\tEnter grades (separated by space):> ");
    for (i = 0; i < num_grades; ++i) {
        scanf("%f", &temp.grades[i]);
    }
    
    // helper function to calculate students GPA and store in proper place
    temp.gpa = get_gpa(temp, num_grades);
    
    // return temp student to be stored in student array
    return temp;
}

// calculates student's GPA
float get_gpa(student record, int num_grades){
    float sum = 0;
    int i;
    
    // loop through grades and store in a sum
    for (i = 0; i < num_grades; i++){
        sum = sum + record.grades[i];
    }
    
    // return GPA
    return (sum/num_grades);
}

// print all student records stored
void print_records(student* student_array, int num_students, int num_grades){
    int i, j;
    
    // outer loop to print each student and basic information, in specified format
    for(i = 0; i < num_students; i++){
        printf("\nStudent ID #%d:\n", student_array[i].sid);
        printf("\tName:\t%s %s\n", student_array[i].first, student_array[i].last);
        printf("\tGrades:\t");
        
        // inner to loop to print each grade for each student
        for(j = 0; j < num_grades; j++){
            printf("%.1f ", student_array[i].grades[j]);
        }
        
        printf("\n\tGPA:\t%.2f", student_array[i].gpa);
    }
}