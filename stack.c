#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif
#ifndef NULL
#define NULL (void*) 0
#endif
#ifndef STACK_H
#include "stack.h"
#endif

typedef struct StackNode stacknode_t;
typedef struct StackNode StackNode;

typedef struct Stack Stack;

// A container for each part in the Stack.
// Contains a reference to some arbitrary data, and a reference to the next
// container.
// A.K.A. LinkedList
struct StackNode {

  void* data;
  StackNode* next;

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

  StackNode* first;

};

// Creates a brand spankin' new Stack and returns a reference to it.
Stack* s_create( void )
{
  Stack* stack = malloc( sizeof( Stack ) );
  stack->first = malloc( sizeof( StackNode ) );
  return( stack );
}

// uses a recursive algorithm to return the length of a stack
// Usage: pass the head/first of the list to this function.
int s_length_recursive( StackNode* node )
{
  if ( node->next == NULL ) return 0;
  return 1 + s_length_recursive( node->next );
}

// Returns the number of elements currently on the stack.
int s_length( Stack* stack )
{
  return s_length_recursive( stack->first );
}

// Pushes an element onto the top of the stack and returns the current
// length of the stack
int s_push( Stack* stack, void* thing )
{
  // save a reference to the old head/first element of the stack
  StackNode* old_first = stack->first;
  StackNode* first = malloc( sizeof( StackNode ) );
  first->data = thing;
  first->next = old_first;
  stack->first = first;
  return s_length( stack );
}

// Returns a reference to the last element on the stack WITHOUT removing it.
void* s_peek( Stack* stack )
{
  return stack->first->data;
}

// Destroys memory for a StackNode allocated via malloc ( dynamic ).
void stack_node_destroy( StackNode* node )
{
  node->next = NULL;
  node->data = NULL;
  free( node );
}

// Returns the last element on the stack AND removes it from the stack.
void* s_pop( Stack* stack )
{
  if ( s_length( stack ) == 0 ) return NULL;
  StackNode* old_first = stack->first;
  void* data = old_first->data;
  stack->first = old_first->next;
  // Clean up the reference as it is no longer accessible through the
  // stack's interface
  stack_node_destroy( old_first );
  return data;
}

// Iterates through a StackNode's next until the next value is null.
// As it unwinds, it destroys each of those next values.
void stack_node_destroy_recursive( StackNode* node )
{
  if ( node == NULL ) return;
  stack_node_destroy_recursive( node->next );
  stack_node_destroy( node );
}

// Destroys memory created for a Stack via malloc.
void s_destroy( Stack *stack )
{
  stack_node_destroy_recursive( stack->first );
  free( stack );
}

