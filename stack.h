#ifndef STACK_H
#define STACK_H
extern struct Stack;
extern struct StackNode;

void s_create;
int s_length( struct Stack *stack );
int s_push( struct Stack *stack, void *thing );
void* s_peek( struct Stack *stack );
void* s_pop( struct Stack *stack );
#endif
