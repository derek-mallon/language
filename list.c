#include <stdlib.h>
#include "error.h"
#include "list.h"

list create_list(){
   list list = {0,NULL,NULL};
   return list;
}

void push_list(list* list,size_t value){
    node* item = malloc(sizeof(node));
    item->value = value;
    item->next = NULL;
    item->prev = list->tail;
    list->tail = item;
    list->size++;
    if(list->head == NULL){
        list->head = item;
    }
}

void remove_node_list(list* list,node* self){
    if(self->prev != NULL){
        node* prev = self->prev;
        prev->next = self->next;
        self->next->prev = prev;
    }else{
        self->next->prev  = NULL;
    }
    free(self);
    list->size--;
}

static void _destroy_list(node* item){
    if(item == NULL){
        return;
    }
    _destroy_list(item->next);
    free(item);
}
void destroy_list(list* list){
    _destroy_list(list->head);
}

