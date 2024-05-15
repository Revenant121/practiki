#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void append(struct Node** head_ref, struct Student* student) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = *student;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    struct Node *last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void print_list(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        print_student(&(current->data));
        current = current->next;
    }
}

void free_list(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

void save_students_to_file(struct Node* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Could not open file %s for writing\n", filename);
        return;
    }

    struct Node* current = head;
    while (current != NULL) {
        struct Student* student = &(current->data);
        fprintf(file, "%s %s %c %d %s %d %d %d\n",
                student->surname,
                student->name,
                student->gender,
                student->age,
                student->group,
                student->math_grade,
                student->physics_grade,
                student->chemistry_grade);
        current = current->next;
    }

    fclose(file);
    printf("File %s saved successfully.\n", filename);  // Добавлено для отладки
}

struct Node* load_students_from_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s for reading\n", filename);
        return NULL;
    }

    struct Node* head = NULL;
    struct Student student;

    while (fscanf(file, "%s %s %c %d %s %d %d %d",
                  student.surname,
                  student.name,
                  &student.gender,
                  &student.age,
                  student.group,
                  &student.math_grade,
                  &student.physics_grade,
                  &student.chemistry_grade) == 8) {
        append(&head, &student);
    }

    fclose(file);
    return head;
}
