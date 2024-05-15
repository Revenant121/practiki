#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 50

struct Student {
    char surname[MAX_NAME_LENGTH];
    char name[MAX_NAME_LENGTH];
    char gender;
    int age;
    char group[MAX_NAME_LENGTH];
    int math_grade;
    int physics_grade;
    int chemistry_grade;
};

struct TreeNode {
    struct Student* student;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct ContainerNode {
    struct Student students[2];
    int size;
    struct ContainerNode* next;
};

void increase_physics_grade(struct Student *student) {
    if (student->physics_grade < 5) {
        student->physics_grade++;
    }
}

void print_student_info(struct Student *student) {
    printf("Surname: %s\n", student->surname);
    printf("Name: %s\n", student->name);
    printf("Gender: %c\n", student->gender);
    printf("Age: %d\n", student->age);
    printf("Group: %s\n", student->group);
    printf("Math grade: %d\n", student->math_grade);
    printf("Physics grade: %d\n", student->physics_grade);
    printf("Chemistry grade: %d\n", student->chemistry_grade);
}

void generate_random_grades(struct Student *student) {
    student->math_grade = rand() % 5 + 1;
    student->physics_grade = rand() % 5 + 1;
    student->chemistry_grade = rand() % 5 + 1;
}

struct TreeNode* insert_student(struct TreeNode* root, struct Student* student) {
    if (root == NULL) {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->student = student;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (strcmp(student->surname, root->student->surname) < 0) {
        root->left = insert_student(root->left, student);
    } else {
        root->right = insert_student(root->right, student);
    }

    return root;
}

void print_students_in_order(struct TreeNode* root) {
    if (root != NULL) {
        print_students_in_order(root->right);
        print_student_info(root->student);
        printf("\n");
        print_students_in_order(root->left);
    }
}

void add_students_to_tree(struct TreeNode** root, struct ContainerNode* container) {
    while (container != NULL) {
        for (int i = 0; i < container->size; i++) {
            struct Student* student = &(container->students[i]);
            *root = insert_student(*root, student);
        }
        container = container->next;
    }
}

int main() {
    srand(time(NULL));

    struct ContainerNode* head = NULL;
    struct ContainerNode* current = NULL;

    for (char group = 'A'; group <= 'C'; group++) {
        struct ContainerNode* newContainer = (struct ContainerNode*)malloc(sizeof(struct ContainerNode));
        newContainer->size = 2;

        for (int i = 0; i < newContainer->size; i++) {
            struct Student* student = &(newContainer->students[i]);
            snprintf(student->group, sizeof(student->group), "Group %c", group);
            snprintf(student->surname, sizeof(student->surname), "Surname_%c_%d", group, i+1);
            snprintf(student->name, sizeof(student->name), "Name_%c_%d", group, i+1);
            student->gender = (i % 2 == 0) ? 'M' : 'F';
            student->age = 18 + (rand() % 5);
            generate_random_grades(student);
        }

        newContainer->next = NULL;
        if (head == NULL) {
            head = newContainer;
            current = head;
        } else {
            current->next = newContainer;
            current = current->next;
        }
    }

    struct TreeNode* root = NULL;

    add_students_to_tree(&root, head);

    printf("Student information with initial grades:\n");
    print_students_in_order(root);

    increase_physics_grade(root->student);

    printf("\nStudent information after increasing physics grade:\n");
    print_students_in_order(root);

    while (head != NULL) {
        struct ContainerNode* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
