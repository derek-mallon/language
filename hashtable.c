#include "hashtable.h"
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "list.h"
#include "error.h"

size_t hash(const char* key){
    int len = strlen(key);
    int i;
    int sum = 0;
    for(i=0;i<len;i++){
        sum += key[i];
    }
    return sum % PRIME;
}

hashtable create_hashtable(){
    list array[PRIME];
    int i;
    vector items = create_vector(item,10);
    hashtable table;
    table.items = items;
    for(i=0;i<PRIME;i++){
        table.array[i] = create_list();
    }
    return table;
}

uint8_t insert_hashtable(hashtable* table,const char* key,size_t value){
    size_t pos  = hash(key);
    if(table->array[pos].size != 0){
        node* look = table->array[pos].head;
        while(look->next != NULL){
            if(strcmp(key,get_vector(item,&table->items,look->value).key) == 0){
                return 0;
            }
            look = look->next;
        }
    }
    item i;
    strcpy(i.key,key);
    i.value = value;
    size_t index = push_vector(item,&table->items,i);
    push_list(&table->array[pos],index);
    return 1;
}

uint8_t has_key_hashtable(hashtable* table,const char* key){
    size_t pos = hash(key);
    if(table->array[pos].size == 0){
        return 0;
    }
    node* look = table->array[pos].head;
    while(look->next != NULL){
        if(strcmp(key,get_vector(item,&table->items,look->value).key) == 0){
            return 1;
        }
        look = look->next;
    }
    return 0;
}

size_t get_value(hashtable* table,const char* key){
    size_t pos = hash(key);
    node* look = table->array[pos].head;
    while(look->next != NULL){
        if(strcmp(key,get_vector(item,&table->items,look->value).key) == 0){
            return get_vector(item,&table->items,look->value).value;
        }
        look = look->next;
    }
    ERR_ASSERT(has_key_hashtable(table,key),"key not found");
    return 0;
}

void destroy_hashtable(hashtable* table){
    int i;
    for(i=0;i<PRIME;i++){
        destroy_list(&table->array[i]);
    }
    destroy_vector(&table->items);
}
