#ifndef LINKED_LIST_H
#define LINKED_LIST_H
typedef struct node node;
typedef struct list list;

struct node{
    node* next;
    node* prev;
    size_t value;
};

struct list{
    size_t size;
    node* head;
    node* tail;
};

list create_list();
void push_list(list* list,size_t value);
void remove_node_list(list* list,node* self);
void destroy_list(list* list);
#endif
