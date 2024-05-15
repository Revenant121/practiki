// main.c

#include <stdio.h>
#include "student.h"
#include "node.h"




int main() {
    struct Node* head = NULL;

    struct Student student1 = {"Ivanov", "Ivan", 'M', 20, "Group 1", 4, 3, 5};
    struct Student student2 = {"Petrov", "Petr", 'M', 21, "Group 2", 3, 4, 5};

    append(&head, &student1);
    append(&head, &student2);

    printf("Initial information of students in the list:\n");
    print_list(head);

    printf("\nIncreasing physics grade for all students...\n");

    struct Node* current = head;
    while (current != NULL) {
        increase_physics_grade(&(current->data));
        current = current->next;
    }

    printf("\nUpdated information of students in the list:\n");
    print_list(head);

    free_list(head);

    return 0;
}
