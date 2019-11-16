#include "stack.h"


#define STACK_SIZE 3

// Backing store
int StackStore[STACK_SIZE];

// Pointer to stack elements for adding and retrieving
int* stackPtr;


// Initialize internals of the stack
void stack_init(void)
{
    stackPtr = 0;
    for(int i=0; i<STACK_SIZE; i++)
    {
        StackStore[i] = 0;
    }
}

// LIFO Stack is Empty if stackPtr==0;
int stack_empty_check(void)
{
    if (stackPtr == 0)    
        return 1; // queue is empty
    else 
        return 0; // queue is not empty
}
// LIFO Stack is Full if stackPtr= Address of last element in the stack;
int stack_full_check(void)
{
    if(stackPtr == &StackStore[STACK_SIZE-1])
      return 1; //stack is full
    else
      return 0; //stack is not full
}
// Add element to stack
// If stack is full return error 
// Otherwise return success
int stack_push(int element)
{
    if(stackPtr == &StackStore[STACK_SIZE-1])
      return 1; //stack is full
    
    if (stackPtr == 0)
    {
      stackPtr = &StackStore[0];        //ready to push the 1st element
    }    
    else
    {
        stackPtr++;
    }
    *stackPtr = element;
    return 0;
}

// Get element from stack
// If stack is empty return error
// Otherwise return success
int stack_pop(int* element)
{   
    if (stackPtr == 0)
    {
        // stack is empty
        return 1;
    }

    *element = *stackPtr;
    
    if (stackPtr == &StackStore[0])
    {
        stackPtr = 0;   //last elemennt has been popped
    }
    else
    {
        stackPtr--;
    }
    return 0;
}