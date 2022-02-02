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

void test_getVectorValue(){
    vector v = createVector(3);
    v.data[0] = 1;
    v.data[1] = 4;
    v.data[2] = 16;
    v.size = 3;

    assert(getVectorValue(&v, 0) == 1);
    assert(getVectorValue(&v, 1) == 4);
    assert(getVectorValue(&v, 2) == 16);

    deleteVector(&v);
}

void test_pushBack_standardWork(){
    vector v = createVector(5);
    v.size = 2;

    pushBack(&v, 12);

    assert(v.data[2] == 12);
    assert(v.size == 3);
    assert(v.capacity == 5);

    deleteVector(&v);
}

void test_pushBack_EmptyVector(){
    vector v = createVector(0);

    pushBack(&v, 2);
    assert(v.capacity == 1);
    pushBack(&v, 3);
    assert(v.capacity == 2);
    pushBack(&v, 4);

    assert(v.data[0] == 2);
    assert(v.data[1] == 3);
    assert(v.data[2] == 4);
    assert(v.size == 3);
    assert(v.capacity == 4);

    deleteVector(&v);
}

void test_pushBack_FullVector(){
    vector v = createVector(5);
    v.size = 5;

    pushBack(&v, 1);
    assert(v.capacity == 10);
    v.size = 10;

    pushBack(&v, 1);
    assert(v.capacity == 20);
    v.size = 20;

    pushBack(&v, 1);
    assert(v.capacity == 40);
    v.size = 40;
}

void test_pushBack(){
    test_pushBack_standardWork();
    test_pushBack_EmptyVector();
    test_pushBack_FullVector();
}

void test_popBack(){
    vector v = createVector(5);
    v.size = 4;

    popBack(&v);
    assert(v.size == 3);

    popBack(&v);
    assert(v.size == 2);

    deleteVector(&v);
}

void test_atVector(){
    vector v = createVector(6);
    v.size = 6;

    assert(atVector(&v, 0) == v.data);
    assert(atVector(&v, 1) == v.data + 1);
    assert(atVector(&v, 2) == v.data + 2);
    assert(atVector(&v, 3) == v.data + 3);

    deleteVector(&v);
}

void test_back(){
    vector v = createVector(5);

    for (int i = 1; i < 6; ++i) {
        v.size = i;
        assert(back(&v) == v.data + i - 1);
    }

    deleteVector(&v);
}

void test_front(){
    for (int i = 0; i < 10; ++i) {
        vector v = createVector(2);

        assert(front(&v) == v.data);

        deleteVector(&v);
    }
}

void test() {
    test_createVector();
    printf("OK test_createVector\n");
    test_reserve();
    printf("OK test_reserve\n");
    test_clear();
    printf("OK test_clear\n");
    test_shrinkToFit();
    printf("OK test_shrinkToFit\n");
    test_deleteVector();
    printf("OK test_deleteVector\n");
    test_isEmpty();
    printf("OK test_isEmpty\n");
    test_isFull();
    printf("OK test_isFull\n");
    test_getVectorValue();
    printf("OK test_getVectorValue\n");
    test_pushBack();
    printf("OK test_pushBack\n");
    test_popBack();
    printf("OK test_popBack\n");
    test_atVector();
    printf("OK test_atVector\n");
    test_back();
    printf("OK test_back\n");
    test_front();

    printf("OK\n");
}
