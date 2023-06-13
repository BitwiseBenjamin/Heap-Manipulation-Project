#ifndef UTIL_H
#define UTIL_H
#include <string>
#include <sstream>
#include "Heap.h"
#include <iostream>
#include <vector>

using namespace std;

//Initialize functions
MinHeap* createFromFile(string file, MinHeap* theHeap);
MinHeap * Initialize(int n);
void DecreaseKey(MinHeap*  theHeap, int flag, int index, int value);
MinHeap* buildheap(MinHeap* theHeap, int A[],int size, int cap);
void Insert(MinHeap* theHeap, int flag, int k);
int nextCommand(int *i, int *v, int *f);
int DeleteMin(MinHeap* theHeap, int flag);
string printHeap(MinHeap* theHeap);
#endif