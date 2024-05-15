#include <stdio.h>
#include "student.h"

void print_student(struct Student *student) {
    printf("Surname: %s\n", student->surname);
    printf("Name: %s\n", student->name);
    printf("Gender: %c\n", student->gender);
    printf("Age: %d\n", student->age);
    printf("Group: %s\n", student->group);
    printf("Math Grade: %d\n", student->math_grade);
    printf("Physics Grade: %d\n", student->physics_grade);
    printf("Chemistry Grade: %d\n", student->chemistry_grade);
    printf("\n");
}

void increase_physics_grade(struct Student *student) {
    if (student->physics_grade < 5) {
        student->physics_grade++;
    }
}
