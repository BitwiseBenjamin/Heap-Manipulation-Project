#include "util.h"
#include "Heap.h"
#include <climits>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

//Main method to run code
int main()
{

//initialize numbers
int n = 0;
int k = 0;
int i = 0;
int v = 0;
int f = 0;

//Create file string for input
string file = "HEAPinput.txt";

//Initialize NULL Heap
MinHeap * currHeap = NULL;

//While loop for input
while(1){

//Request Input
printf("\n\nInput:\n");

//Get Command from user
char c = nextCommand(&i, &v, &f);


//Switch statment to determine what to do based on command*********************************************
switch (c) {


//Command I/i***********************************************************************************************************************
case 'i': 

 scanf("%d", &f); 
 scanf("%d", &k); 

 printf("\nCOMMAND: %c, %d, %d\n", c, f, k);

 if(f != 1 && f != 2){
        printf(" This is not a valid flag, please use 1 or 2");
        break;
    }

 if(currHeap == NULL){
    printf("Please initialize the MinHeap before using the command.");
    break;
 }
 Insert(currHeap, f, k); break;



case 'I': 

 scanf("%d", &f); 
 scanf("%d", &k);

 printf("\nCOMMAND: %c, %d, %d\n", c, f, k);

  if(currHeap == NULL){
    printf("Please initialize the MinHeap before using the command.");
    break;  
    }   

 if(f != 1 && f != 2){
        printf("This is not a valid flag. put in 1 or 2");
        break;
    }
   Insert(currHeap, f, k); break;
//**************************************************************************************************************************************



//Command D/d*******************************************************************************************************************
case 'd':

printf("\nCOMMAND: %c\n", c);

if(currHeap == NULL){
    printf("Please initialize the MinHeap or add an element to the MinHeap before using the command");
    break;
}

//Scan flag
 scanf("%d", &f);

  if(f != 1 && f != 2){
        printf(" This is not a valid flag, please use 1 or 2");
        break;
    }
DeleteMin(currHeap, f); break;


case 'D': 

printf("\nCOMMAND: %c\n", c);

if(currHeap == NULL || currHeap->heap_size == 0){
    printf("Please initialize the MinHeap! or add some element to MinHeap before using the command");
    break;
} 

//find flag
 scanf("%d", &f);
 
if(f != 1 && f != 2){
 printf(" This is not a valid flag, please put 1 or 2");
break;
}
    
DeleteMin(currHeap, f); break;
//**************************************************************************************************************************************



//Command W/w*********************************************************************************************************************
case 'w': printf("\nCOMMAND: %c\n", c);

if(currHeap == NULL){
    printf("Please initialize the MinHeap before using the command.");
    break;
}
 cout << printHeap(currHeap); break;

case 'W':  

printf("\nCOMMAND: %c\n", c);
if(currHeap == NULL){
 printf("Please initialize the MinHeap before using the command.");
 break;
}
cout << printHeap(currHeap); break;
//**************************************************************************************************************************************



//Command K/k**************************************************************************************************************************
case 'k': printf("\nCOMMAND: %c %d %d %d\n", c, f, i , v); 

if(currHeap == NULL || currHeap->heap_size == 0){
    printf("Please initialize the MinHeap! or add the element before using this the command.");
    break;
}
if(i + 1  > currHeap->heap_size || i < 0){
    printf("The heap is too small enough! or no index i in it.");
    break;
}

DecreaseKey(currHeap, f, i, v); break;

case 'K': printf("\nCOMMAND: %c %d %d %d\n", c, f, i, v); 

if(currHeap == NULL || currHeap->heap_size == 0){
printf("Please initialize the MinHeap or add an element to the MinHeap before using the command.");
 break;
 }

if(i + 1  > currHeap->heap_size || i < 0){
printf("This heap is not big enough! and or does not have index i in it.");
break;
}

DecreaseKey(currHeap, f, i, v); break;
//**************************************************************************************************************************************



//Command R/r**************************************************************************************************************************
case 'r': 
printf("\nCOMMAND: %c\n", c);  

if(currHeap == NULL){
    printf("Please initialize the MinHeap before using the command");
    break;
}
currHeap = createFromFile(file, currHeap); break;

case 'R': 
printf("\nCOMMAND: %c\n", c);  

if(currHeap == NULL){
printf("Please initialize the MinHeap before using the command");
break;
}
currHeap = createFromFile(file, currHeap); break;
//**************************************************************************************************************************************



//Command C/c*************************************************************************************************************************
case 'c': 
scanf("%d", &n);
printf("\nCOMMAND: %c %d\n", c, n);

currHeap = Initialize(n); break;


case 'C': 
scanf("%d", &n);
printf("\nCOMMAND: %c %d\n", c, n);

    
currHeap = Initialize(n); break;
//**************************************************************************************************************************************



//Command S/s******************************************************************************************************************************
case 's': printf("\nCOMMAND: %c\n", c); printf("Program Terminated"); exit(0);
case 'S': printf("\nCOMMAND: %c\n", c); printf("Program Terminated"); exit(0);
//**************************************************************************************************************************************


default: break;
}
}
exit(0);
}