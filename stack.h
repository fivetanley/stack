#ifndef STACK_H
#define STACK_H
struct Stack;
struct StackNode;

typedef struct Stack Stack;

void s_create;
int s_length( Stack *stack );
int s_push( Stack *stack, void *thing );
void* s_peek( Stack *stack );
void* s_pop( Stack *stack );
void s_destroy( Stack *stack );
#endif
