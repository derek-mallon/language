#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
vector _create_v(size_t object_size,size_t capacity){
    void* data = malloc(object_size*capacity);
    if(data == NULL){
        printf("ERROR NOT ENOUGH MEM AT:%s",__func__);
    }
    vector result = {0,capacity,object_size,data};
    return result;
}

size_t get_new_vector(vector* v){
    if(v->size >= v->capacity){
        void* new = realloc(v->data,v->object_size*v->capacity*2);
        if(new == NULL){
            printf("ERROR NOT ENOUGH MEM AT:%s",__func__);
        }
        v->capacity *=2;
        v->data = new;
    }
    return v->size++;
}




void destroy_vector(vector* v){
    if(v->capacity != 0){
        free(v->data);
        v->capacity =0;
        v->size = 0;
        v->data = NULL;
    }
}


