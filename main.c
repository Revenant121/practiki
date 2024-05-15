#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char surname[50];
    char name[50];
    char gender;
    int age;
    char group[10];
    int math_grade;
    int physics_grade;
    int chemistry_grade;
};

struct Node {
    struct Student data;
    struct Node* next;
};

struct AppendArgument {
    struct Node **head_ref;
    struct Student *student;
};

void print_student(struct Student *student);
void increase_physics_grade(struct Student *student);
struct Node* create_node(struct Student* student);
void append(struct AppendArgument *arg);
void print_list(struct Node* head);
void free_list(struct Node* head);

int main() {
    struct Node* head = NULL;

    struct Student student1 = {"Ivanov", "Ivan", 'M', 20, "Group 1", 4, 3, 5};
    struct Student student2 = {"Petrov", "Petr", 'M', 21, "Group 2", 3, 4, 5};

    struct AppendArgument arg1 = {&head, &student1};
    append(&arg1);

    struct AppendArgument arg2 = {&head, &student2};
    append(&arg2);

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

struct Node* create_node(struct Student* student) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->data = *student;
    node->next = NULL;
    return node;
}

void append(struct AppendArgument *arg) {
    struct Node *new_node = create_node(arg->student);
    if (*(arg->head_ref) == NULL) {
        *(arg->head_ref) = new_node;
        return;
    }
    struct Node *last = *(arg->head_ref);
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
