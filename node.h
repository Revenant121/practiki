#ifndef NODE_H
#define NODE_H

#include "student.h"

struct Node {
    struct Student data;
    struct Node* next;
};

void append(struct Node** head_ref, struct Student* student);
void print_list(struct Node* head);
void free_list(struct Node* head);
void save_students_to_file(struct Node* head, const char* filename);
struct Node* load_students_from_file(const char* filename);

#endif /* NODE_H */
