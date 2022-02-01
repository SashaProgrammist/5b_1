//
// Created by PC on 01.02.2022.
//

#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef GIT_VECTOR_H
#define GIT_VECTOR_H

typedef struct vector {
    int *data;         // указатель на элементы вектора
    size_t size;       // размер вектора
    size_t capacity;   // вместимость вектора
} vector;

// memory usage of vector

vector createVector(size_t n);

void reserve(vector *v, size_t newCapacity);

void clear(vector *v);

void shrinkToFit(vector *v);

void deleteVector(vector *v);

// boolean functions

bool isEmpty(vector *v);

bool isFull(vector *v);

//  the simplest interaction with the structure

int getVectorValue(vector *v, size_t i);

void pushBack(vector *v, int x);

void popBack(vector *v);

#endif //GIT_VECTOR_H
