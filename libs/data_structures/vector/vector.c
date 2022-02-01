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

void reserve(vector *v, size_t newCapacity) {
    if (v->data == NULL) {
        *v = createVector(newCapacity);

        return;
    }

    if (newCapacity == 0) {
        deleteVector(v);

        return;
    }

    void *new = realloc(v->data, newCapacity * sizeof(int));

    if (new == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    v->data = (int *) new;
    if (v->size > newCapacity) v->size = newCapacity;
    v->capacity = newCapacity;

}

void clear(vector *v){
    v->size = 0;
}

void shrinkToFit(vector *v){
    reserve(v, v->size);
}

void deleteVector(vector *v){
    if (isEmpty(v)) return;

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
    if (v->size <= i){
        fprintf(stderr, "IndexError: v[%d] is not exists", i);
        exit(1);
    }

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

// access functions

int* atVector(vector *v, size_t index){
    if (v->size <= index){
        fprintf(stderr, "IndexError: v[%d] is not exists", index);
        exit(1);
    }

    return v->data + index;
}

int* back(vector *v){
    return v->data + v->size - 1;
}

int* front(vector *v){
    return v->data;
}
