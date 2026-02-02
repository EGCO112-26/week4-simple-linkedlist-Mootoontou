#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --------------------------------------------------------
// ส่วนที่ 1: Struct และ Typedef
// --------------------------------------------------------
struct std_node {
    int id;
    char name[30];
    struct std_node *next;
};

typedef struct std_node* NodePtr;

// --------------------------------------------------------
// ส่วนที่ 2: Prototypes
// --------------------------------------------------------
void insert(NodePtr *head, int id, char *name);
void print_list(NodePtr head);
void delete_list(NodePtr head);

// --------------------------------------------------------
// ส่วนที่ 3: Main Function
// --------------------------------------------------------
int main(int argc, char **argv) {
    NodePtr head = NULL;
    int i;
    
    for (i = argc - 2; i > 0; i -= 2) {
        int id = atoi(argv[i]);
        char *name = argv[i + 1];
        insert(&head, id, name);
    }

    print_list(head);
    delete_list(head);

    return 0;
}

// --------------------------------------------------------
// ส่วนที่ 4: รายละเอียดฟังก์ชัน
// --------------------------------------------------------

void insert(NodePtr *head, int id, char *name) {
    NodePtr new_node = (NodePtr)malloc(sizeof(struct std_node));
    new_node->id = id;
    strcpy(new_node->name, name);
    
    new_node->next = *head;
    *head = new_node;
}

void print_list(NodePtr head) {
    NodePtr tmp = head;
    while (tmp != NULL) {
        printf("%d %s\n", tmp->id, tmp->name);
        tmp = tmp->next;
    }
}

void delete_list(NodePtr head) {
    NodePtr tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}