#ifndef DATA_H
#define DATA_H
#include <stdlib.h>

typedef struct vector vector;
typedef struct vector stack;

struct vector{
    size_t size;
    size_t capacity;
    size_t object_size;
    void* data;
};

vector _create_v(size_t object_size,size_t capacity);

#define create_vector(type,capacity) _create_v(sizeof(type),capacity) 

#define push_vector(type,v,item) (v)->size;*(type*)(&((v)->data[get_new_vector(v)*(v)->object_size])) = item;

#define get_vector(type,v,index) (*(type*)(&(v)->data[(v)->object_size*index]))

size_t get_new_vector(vector* v);

void destroy_vector(vector* v);
#endif
