#ifndef MaxHeap_h
#define MaxHeap_h

#include "ElementType.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
#define LOAD_FACTOR 0.6
#define PRINT_SPACING 5

class Heap {
    ElementType *data;
    size_t size, count;
    void swap(size_t parent, size_t child);
    void heapify(size_t index);
    void print_util(size_t index, int spacing = 0);
public:
    Heap(size_t size = 8);
    ~Heap();

    void insert(ElementType element);
    ElementType max();
    ElementType popMax();
    void print();
    void shrink_to_fit();
};

#endif
#pragma once
