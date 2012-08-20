// the implementation of the stack
struct Stack;

// allocate memory and initialize values
struct Stack* s_create();

// return the current length of the stack
int s_length(struct Stack* s);

// return the new length of the stack
int s_push(struct Stack* s, void* v);

// pop off the top of the stack (
void* s_pop(struct Stack* s);

// look at the most recently inserted element
void* s_peek(struct Stack* s);

// release the memory allocated
void s_destroy(struct Stack* s);
