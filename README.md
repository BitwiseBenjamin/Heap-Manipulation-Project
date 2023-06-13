
** Heap Manipulator Project
* Language: C++
*
 ** MinHeap - A program that creates a MinHeap class and utilizes it to store ELEMENTS in a min heap fashion based on their key.
 *           The program also includes a util file that implements functions to add and edit elements within the MinHeap.
 *           Additionally, there is a run file that takes user input characters to determine which functions in util will be 
 *           used to create and edit the MinHeap. The program also reads from a file when the user input is R.
 * 
 * Programmers: Zachary Rundstrom
 * 
 ** How to Run:
 *   1. Compile the program using the provided Makefile and run "make" in the terminal.
 *   2. Then run the program: "./run".
 * 
 ** How to Use:
 *   1. Upon running the program, the user will be prompted to enter input:
 *      a. "S" stops the program
 *      b. "C n" will delete the minimum element from the MinHeap and print out values if n is 2
 *      c. "R" reads the input from the Heapinput.txt file and puts it in a heap
 *      d. "W" displays the values and variables of the heap
 *      e. "I f k" will insert a value k into the minheap and display the value of the heap based on the flag k
 *      f. "K f i v" will decrease the value of the ith element in the heap to the value v
 *             
 *          -decreases the key of element at index i
 *          void decreaseKey(int i, int new_val);
 * 
 *          -returns "element_array[0]"
 *          int getMin();
 *
  *          -deletes element with key = i
   *         void deleteKey(int i);
*
 *           -creates new element with key k and inserts it into the heap
  *          void insertKey(int k);
*
 *           -heapifies the index in the array
  *          void MinHeapify(int i);
*
 *           -returns the new MinHeap that is created from the file
  *          MinHeap* createFromFile(string file, MinHeap* theHeap);
*
 *         -returns new minheap
  *        MinHeap * Initialize(int n);
*
 *           -decreases the value of index to value of the minheap
  *          void DecreaseKey(MinHeap*  theHeap, int flag, int index, int value);
*
 *           -returns new minheap based on array of ELEMENTS A
  *          MinHeap* buildheap(MinHeap* theHeap, int A[],int size, int cap);
**           -inserts a new element with key k
            void Insert(MinHeap* theHeap, int flag, int k);

            -looks for next input char by user
            int nextCommand(int *i, int *v, int *f);

            -deletes minimum element and returns the int to user
            int DeleteMin(MinHeap* theHeap, int flag);

            -returns string of 
            string printHeap(MinHeap* theHeap);

 * 
 ** Files:
 *   1. run.cpp - The main driver file that runs the program.
 *   2. Heap.h - The header file for the MinHeap class.
 *   3. Heap.cpp - The implementation file for the MinHeap class.
 *   4. util.h - The header file for the utility functions to add and edit elements in the MinHeap.
 *   5. util.cpp - The implementation file for the utility functions.
 *   7. Heapinput.txt - An example file that contains data to be read by the program.
 *   8. ELEMENT.cpp - create the element class to be stored in the heap
 * 
 ** Contributing:
 * 
 * Personal project, no contributions or pulls allowed.
 * 
 *
 
 
 
