#include <iostream>
#include <vector>
#include "Heap.h"
#include "util.h"
#include <fstream>
#include <climits>
#include <string>
#include <sstream>

using namespace std;

// Initialize a new MinHeap with a given capacity 'n' and return a pointer to it.
MinHeap * Initialize(int n){

    // Create a new MinHeap object with capacity 'n' and initialize its properties.
    MinHeap * heap = new MinHeap(n);
    heap->capacity = n;
    heap->heap_size = 0;

    // Return the pointer to the created MinHeap.
    return heap;
}

// Build a MinHeap object using an array of ELEMENT objects and return a pointer to it.
MinHeap* buildheap(MinHeap* MHeap, ELEMENT e[], int size, int cap){

    // Create a new MinHeap object with capacity 'cap' and initialize its properties using the given array of ELEMENT objects and 'size'.
    MinHeap * heap = new MinHeap(e, size, cap);

    // Perform the MinHeapify operation on all internal nodes in the MinHeap object to ensure the MinHeap property is satisfied.
    for(int i=(size/2)+1;i>=0;i--){
        heap->MinHeapify(i);
    }

    // Return the pointer to the created MinHeap object.
    return heap;
}

// Print the current state of the given MinHeap object.
string printHeap(MinHeap* MHeap) {

    // Create a string stream object to accumulate the heap state information.
    stringstream ss;

    // Print the capacity and size of the MinHeap object.
    ss << "\nThe capacity is " << MHeap->capacity;
    ss << "\nSize is " << MHeap->heap_size;

    // Print the key values of all the elements in the MinHeap.
    for (int i = 0; i < MHeap->heap_size; i++) {
        ss << "\n";
        ss << MHeap->element_array[i].getKey(); 
    }
    
    // Return the accumulated string containing the heap state information.
    return ss.str();
}

// Decrease the key value of an element at a given index in the MinHeap object.
void DecreaseKey(MinHeap*  heap, int flag, int index, int value) {

     // Check if the new value is less than or equal to the current value at the given index.
    if (value > heap->element_array[index].getKey()) {
        cout << "Error: new value is greater than current value" << endl;
        return;
    }

    // If flag is set to 2, print the MinHeap object before decreasing the key value.
    if (flag == 2) {
        cout << "Heap before decrease key: " << printHeap(heap) << endl;
    }

    // Update the key value at the given index and bubble up the element until the MinHeap property is restored.
    heap->element_array[index].setKey(value);
    while (index > 0 && heap->element_array[index].getKey() < heap->element_array[(index - 1) / 2].getKey()) {
        swap(heap->element_array[index], heap->element_array[(index - 1) / 2]);
        index = (index - 1) / 2;
    }

    // If flag is set to 2, print the MinHeap object after decreasing the key value.
    if (flag == 2) {
        cout << "Heap after decrease key: " << printHeap(heap) << endl;
    }
}

// Insert a new element with a given key value into the MinHeap object.
void Insert(MinHeap* MHeap, int flag, int k){
        
       
    // Print heap contents before insertion, if requested.
    if(flag == 2){
        cout << "Heap Before Insert: "<< printHeap(MHeap) << endl;
    }

    // Insert the new key at the end of the heap.
    MHeap->insertKey(k);

    // Print heap contents after insertion, if requested.
    if(flag == 2){
        cout << "Heap After Insert: "<< printHeap(MHeap) << endl;
    }
}

    //given nextCommand function that determins input flow
    int nextCommand(int *i, int *v, int *f)
    {
    char c;
    while(1){

    scanf("%c", &c);

    if (c == ' ' || c == '\t' || c == '\n'){ continue;
    }
    if (c == 'S' || c=='C' || c == 'R' || c == 'W' || c == 'I' || c == 'D' || c == 's' || c == 'r' || c == 'w' || c == 'i' || c == 'd' || c == 'c' ){ break;
    }

    if (c == 'K' || c == 'k' ){
//get f
   scanf("%d", f);  
//get i
    scanf("%d", i); 
//get v
    scanf("%d", v); 
    break;
    }

    printf("Invalid Command\n");
    }
    return c;
    }


//Function to get  a minheap from file data
MinHeap* createFromFile(string file, MinHeap* theHeap) {
        //get file info
    ifstream infile(file);

//error checking if file exists
    if (!infile) {
       cout << "There was a problem opening file " + file + " for reading." << endl;
    }

    int num;
    //get size of array
    infile >> num;
   
//error checking
if(theHeap->capacity < num){
    printf("Please increase capacity of heap first.");
    return theHeap;
}

    //create new element array
    int size = num;
    ELEMENT *e_arr = new ELEMENT[size];

    //loop to add each int key to an element in the element array
    int i = 0;
    while (infile >> num || !infile.eof()) {
        e_arr[i].setKey(num);
        i++;
    }

    if(size > i){
            printf("The number of elements is > specified in the file.");
            return theHeap;
        }

        if(size < i){
            printf("The number of elements is < specified in the file.");
            return theHeap;
        }
    
    infile.close();
    
    
    int cap = theHeap->capacity;
    if(cap < size){
        cap = size;
    }
    theHeap->heap_size = 0;

    //return the heap build using the array of elements
   return buildheap(theHeap, e_arr, size, cap);
}


// This function deletes the minimum key (i.e., the root node) from the heap and returns its value.
int DeleteMin(MinHeap* Heap, int flag){

    // Print heap contents before deletion, if requested.
    if(flag == 2){
        cout << "Heap Before DeleteMin: "<< printHeap(Heap) << endl;
    }

    // Extract the minimum key and remove it from the heap.
    int i = Heap->extractMin();

    // Print heap contents after deletion, if requested.
    if(flag == 2){
        cout << "Heap After DeleteMin: "<< printHeap(Heap) << endl;
    }

    // Return the value of the deleted key.
    return i;
}
  


  
   


