#ifndef STACK_H
#include "stack.h"
#endif

typedef struct StackNode stacknode_t;
typedef struct StackNode StackNode;

// A container for each part in the Stack.
// Contains a reference to some arbitrary data, and a reference to the next
// container.
// A.K.A. LinkedList
struct StackNode {

  void *data;
  StackNode *next;

};

// A last-in first-out data structure. This means that the last thing to go
// into the data structure will be the first thing that comes out when pop
// or peek is called.
// Interface:
//    void s_create() : create a new stack
//    int s_length( Stack *stack ): get number of items in the stack
//    void* s_peek( Stack *stack ): returns the last element in stack without 
//      removing it
//    void* s_pop( Stack *stack ): returns last element in stack and removes it
//    int s_push( Stack *stack, void* thing ): pushes thing onto the last
//      position in the stack, and returns the current length of the stack.
//  Properties:
//    StackNode *first: a reference to the first StackNode in the list. The list
//      is navigated by beginning at first, and continually dereferencing a next
//      value until the value returns NULL.
//
struct Stack {

  StackNode *first;

};
