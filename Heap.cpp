#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Heap.h"
#include <climits>

using namespace std;

// - MinHeap(): Constructor to initialize a capacity and element_array
    MinHeap::MinHeap(int n){
        element_array = new ELEMENT[n];
        capacity = n;
        heap_size = 0;
    }

// - MinHeap(ELEMENT[], int, int): Constructor to initialize with an array of ELEMENT
    MinHeap::MinHeap(ELEMENT e[], int n, int length){
        element_array = e;
        capacity = length;
        heap_size = n;
    }
    
// - ~MinHeap(): Destructor to delete the element_array
   MinHeap::~MinHeap() {
    delete[] element_array;
}
   
    // method to get index of parent of node at index i
    int MinHeap::parent(int i){ return (i-1)/2; }

    // method to get index of left child of node at index i
    int MinHeap::left(int i){ return (2*i + 1); }

    // method to get index of right child of node at index i
    int MinHeap::right(int i){ return (2*i + 2); }

    // - MinHeapify(int): A recursive method to heapify the element_array
    void MinHeap::MinHeapify(int i){

        //Define child nodes
        int r = right(i);
        int l = left(i);
       
       //Find the smallest
        int smallest = i;
        if (l < heap_size && element_array[l].getKey() < element_array[i].getKey())
            smallest = l;
        if (r < heap_size && element_array[r].getKey() < element_array[smallest].getKey())
            smallest = r;

        //Swap if the node is smaller than parent
        if (smallest != i){
            swap(element_array[i], element_array[smallest]);
            MinHeapify(smallest);
        }
    }

   // - extractMin(): Method to remove the minimum element (root) from the min heap
    int MinHeap::extractMin(){

        if (heap_size <= 0)
            return INT_MAX;
        if (heap_size == 1){
            heap_size--;
            return element_array[0].getKey();
        }

        //Remove the minimum value from the heap
        int root = element_array[0].getKey();
        element_array[0].setKey(element_array[heap_size-1].getKey());
        heap_size--;
        MinHeapify(0);

        //return the min root
        return root;
    }

    // - decreaseKey(int, int): Method to decrease the key value of a given node to a new value 
    void MinHeap::decreaseKey(int index, int val){

        //set value
        element_array[index].setKey(val);

        //place in correct spot
        while (index != 0 && element_array[parent(index)].getKey() > element_array[index].getKey()){
            swap(element_array[index], element_array[parent(index)]);
            index = parent(index);
        }
    }

  // - getMin(): Method to get the minimum key (root) from the min heap
    int MinHeap::getMin(){ 
        return element_array[0].getKey(); 
        }

   
    // - deleteKey(int): Method to delete the key at a given index
    void MinHeap::deleteKey(int i){
        decreaseKey(i, INT_MIN);
        extractMin();
    }

  // - insertKey(int): Method to insert a new key into the min heap
    void MinHeap::insertKey(int key){

        if (heap_size >= capacity){
            capacity = capacity + 10;
        }

       //create new element to hold key
        ELEMENT* e = new ELEMENT(key);

        //get i
        int i = heap_size;

        // Inserting the new key at the end
        element_array[heap_size++] = *e;

        //place in correct position
        while (i != 0 && element_array[parent(i)].getKey() > element_array[i].getKey()){
                swap(element_array[i], element_array[parent(i)]);
            i = parent(i);
        }
    }






