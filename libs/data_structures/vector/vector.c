//
// Created by PC on 01.02.2022.
//

#include "vector.h"

// memory usage of vector

vector createVector(size_t n){
    vector result;
    result.size = 0;
    result.capacity = n;
    if (n) {
        result.data = malloc(n * sizeof(int));

        if (result.data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
    } else
        result.data = NULL;

    return result;
}

void reserve(vector *v, size_t newCapacity){
    if (newCapacity == 0){
        deleteVector(v);

        return;
    }

    void *new = realloc(v->data, newCapacity * sizeof(int));

    if (new == NULL){
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    v->data = (int *)new;
    if (v->size > newCapacity) v->size = newCapacity;
    v->capacity = newCapacity;
}

void clear(vector *v){
    v->size = 0;
}

void shrinkToFit(vector *v){
    v->data = realloc(v->data, v->size * sizeof(int)), v->capacity = v->size;
}

void deleteVector(vector *v){
    free(v->data);
    v->data = NULL;
    v->capacity = 0;
    v->size = 0;
}

// boolean functions

bool isEmpty(vector *v){
    return v->data == NULL;
}

bool isFull(vector *v){
    return v->size == v->capacity;
}

//  the simplest interaction with the structure

int getVectorValue(vector *v, size_t i){
    return v->data[i];
}

void pushBack(vector *v, int x){
    if (isEmpty(v))
        *v = createVector(1);

    if (isFull(v))
        reserve(v, v->capacity * 2);

    v->data[v->size++] = x;
}

void popBack(vector *v){
    if (v->size == 0){
        fprintf(stderr, "vector = NULL");
        exit(1);
    }

    v->size--;
}
