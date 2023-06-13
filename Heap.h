#ifndef HEAP_H
#define HEAP_H
#include "ELEMENT.cpp"

using namespace std;

class MinHeap {
public:

    ELEMENT* element_array; // Pointer to array 
    int capacity; // Maximum size
    int heap_size; // Current number of elements 

    //Constructors and destructors
    MinHeap(int capacity);
    MinHeap(ELEMENT e[], int n, int length);
    ~MinHeap();

    //Methods
    void decreaseKey(int i, int new_val);
    int getMin();
    void deleteKey(int i);
    void insertKey(int k);
    void MinHeapify(int i);
    int parent(int i);
    int left(int i);
    int right(int i);
    int extractMin();
};
#endif