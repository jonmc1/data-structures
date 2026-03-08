#ifndef stack_h
#define stack_h

#include <stdbool.h>

typedef struct stack
{
	int *elements;
	int capacity;
	int top;
} the_stack; // stack_t was already taken

/**
 * Create a new stack with the given capacity
 */
the_stack *stack_create(int capacity);

/**
 * Push an element onto the stack
 */
bool stack_push(the_stack *stack, int x);

/**
 * Pop an element from the stack
 */
int stack_pop(the_stack *stack);

/**
 * Peek at the top element of the stack without removing it
 */
int stack_peek(the_stack *stack);

/**
 * Check if stack is empty
 */
bool stack_is_empty(the_stack *stack);

/**
 * Check if stack is full
 */
bool stack_is_full(the_stack *stack);

/**
 * Delete the stack and free stack memory
 */
void stack_delete(the_stack *stack);

/**
 * Print the stack from top to bottom
 */
void stack_print(the_stack *stack);

#endif // stack_h
