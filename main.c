#include <stdio.h>
#include "student.h"
#include "node.h"

void save_students_to_file(struct Node* head, const char* filename);
struct Node* load_students_from_file(const char* filename);

int main() {
    struct Node* head = NULL;

    // Загрузка студентов из файла
    head = load_students_from_file("students.txt");

    if (head == NULL) {
        struct Student student1 = {"Ivanov", "Ivan", 'M', 20, "Group 1", 4, 3, 5};
        struct Student student2 = {"Petrov", "Petr", 'M', 21, "Group 2", 3, 4, 5};

        append(&head, &student1);
        append(&head, &student2);
    }

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

    // Сохранение студентов в файл
    save_students_to_file(head, "students.txt");

    free_list(head);

    return 0;
}
