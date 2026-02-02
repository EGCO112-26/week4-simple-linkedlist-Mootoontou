//
//  node.h
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#ifndef stdnode_h
#define stdnode_h

#include <string.h> 

struct std_node {
    int id;
    char name[30];
    struct std_node *next;
};

typedef struct std_node Node;
typedef Node* NodePtr; // <--- แก้จาก STD เป็น Node* หรือ struct std_node*

// เพิ่ม Prototype ของฟังก์ชันไว้ที่นี่ เพื่อให้ main.c เรียกใช้ได้
void insert(NodePtr *head, int id, char *name);
void print_list(NodePtr head);
void delete_list(NodePtr head);

#endif /* node_h */