#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <stdlib.h>
#include "list.h"
#include "vector.h"
#define PRIME 2999
#define MAX_KEY_SIZE 256

typedef struct hashtable hashtable;
typedef struct item item;

char key[MAX_KEY_SIZE];

struct item{
    char key[MAX_KEY_SIZE];
    size_t value;
};

struct hashtable{
    list array[PRIME];
    vector items;
};

size_t hash(const char* key);
hashtable create_hashtable();
uint8_t insert_hashtable(hashtable* table,const char* key,size_t value);
uint8_t has_key_hashtable(hashtable* table,const char* key);
size_t get_value(hashtable* table,const char* key);
#endif
