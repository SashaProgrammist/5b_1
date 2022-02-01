//
// Created by PC on 01.02.2022.
//

#include "vector.h"
#include <assert.h>

void test_createVector_createEmptyVector(){
    vector v = createVector(0);

    assert(v.data == NULL);
    assert(v.size == 0);
    assert(v.capacity == 0);

    deleteVector(&v);
}

void test_createVector_memoryAllocation(){
    vector v = createVector(3);

    assert(v.data != NULL);
    assert(v.size == 0);
    assert(v.capacity == 3);

    deleteVector(&v);
}

void test_createVector(){
    test_createVector_createEmptyVector();
    test_createVector_memoryAllocation();
}

void test_reserve_EmptyVector(){
    vector v = createVector(0);

    reserve(&v, 10);

    assert(v.data != NULL);
    assert(v.size == 0);
    assert(v.capacity == 10);

    deleteVector(&v);
}

void test_reserve_EmptyNewVector(){
    vector v = createVector(10);

    reserve(&v, 0);

    assert(v.data == NULL);
    assert(v.size == 0);
    assert(v.capacity == 0);

    deleteVector(&v);
}

void test_reserve_standardWork(){
    vector v = createVector(10);

    v.size = 5; // да жёстко

    reserve(&v, 3);

    assert(v.data != NULL);
    assert(v.size == 3);
    assert(v.capacity == 3);

    deleteVector(&v);
}

void test_reserve(){
    test_reserve_EmptyVector();
    test_reserve_EmptyNewVector();
    test_reserve_standardWork();
}

void test_clear(){
    vector v = createVector(10);
    v.size = 5;

    clear(&v);

    assert(v.size == 0);
}

void test_shrinkToFit_standardWork(){
    vector v = createVector(10);
    v.size = 5;

    shrinkToFit(&v);

    assert(v.data != NULL);
    assert(v.size == 5);
    assert(v.capacity == 5);

    deleteVector(&v);
}

void test_shrinkToFit_EmptyVector(){
    vector v = createVector(10);

    shrinkToFit(&v);

    assert(v.data == NULL);
    assert(v.size == 0);
    assert(v.capacity == 0);

    deleteVector(&v);
}

void test_shrinkToFit_FullVector(){
    vector v = createVector(10);
    v.size = 10;

    shrinkToFit(&v);

    assert(v.data != NULL);
    assert(v.size == 10);
    assert(v.capacity == 10);

    deleteVector(&v);
}

void test_shrinkToFit(){
    test_shrinkToFit_standardWork();
    test_shrinkToFit_EmptyVector();
    test_shrinkToFit_FullVector();
}

void test_deleteVector(){
    vector v = createVector(7);

    deleteVector(&v);

    assert(v.data == NULL);
    assert(v.size == 0);
    assert(v.capacity == 0);
}

void test_isEmpty_yes() {
    vector v = createVector(0);

    assert(isEmpty(&v) == true);
}

void test_isEmpty_not(){
    vector v = createVector(3);

    assert(isEmpty(&v) != true);
}

void test_isEmpty(){
    test_isEmpty_yes();
    test_isEmpty_not();
}

void test_isFull_yes(){
    {
        vector v = createVector(0);

        assert(isFull(&v) == true);
    }
    {
        vector v = createVector(5);
        v.size = 5;

        assert(isFull(&v) == true);
    }
}

void test_isFull_not(){
    vector v = createVector(3);

    assert(isFull(&v) != true);
}

void test_isFull(){
    test_isFull_yes();
    test_isFull_not();
}

void test_getVectorValue(){}

void test_pushBack(){}

void test_popBack(){}

void test_atVector(){}

void test_back(){}

void test_front(){}

void test(){
    test_createVector();
    test_reserve();
    test_clear();
    test_shrinkToFit();
    test_deleteVector();
    test_isEmpty();
    test_isFull();
    test_getVectorValue();
    test_pushBack();
    test_popBack();
    test_atVector();
    test_back();
    test_front();
}
