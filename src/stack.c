#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/stack.h"

int main(int argc, char *argv[]) {
	char op[32];
	int arg1;
	int arg2;
	int arg3;

	printf("Capacity: ");
	scanf("%d", &arg1);
	the_stack *stack = stack_create(arg1);

	const char help_message[] = "Operations:"
		"\n- print"
		"\n- is-empty"
		"\n- is-full"
		"\n- push <value>"
		"\n- pop"
		"\n- peek"
		"\n- append-random-values <count> <min> <max>"
		"\n- help"
		"\n- exit|quit\n";

	printf(help_message);
	while (1) {
		printf("\n> ");
		scanf("%s", op);
		if (strcmp(op, "print") == 0) {
			stack_print(stack);
		} else if (strcmp(op, "is-empty") == 0) {
			printf(stack_is_empty(stack) ? "Stack is empty\n" : "Stack is not empty\n");
		} else if (strcmp(op, "is-full") == 0) {
			printf(stack_is_full(stack) ? "Stack is full\n" : "Stack is not full\n");
		} else if (strcmp(op, "push") == 0) {
			scanf("%d", &arg1);
			if (stack_push(stack, arg1)) {
				printf("Pushed %d onto the stack\n", arg1);
			} else {
				printf("Stack is full\n");
			}
		} else if (strcmp(op, "pop") == 0) {
			int value = stack_pop(stack);
			if (value != -1) {
				printf("Popped %d from the stack\n", value);
			} else {
				printf("Stack is empty.\n");
			}
		} else if (strcmp(op, "peek") == 0) {
			int value = stack_peek(stack);
			if (value != -1) {
				printf("Top of the stack: %d\n", value);
			} else {
				printf("Stack is empty\n");
			}
		} else if (strcmp(op, "append-random-values") == 0) {
			scanf("%d %d %d", &arg1, &arg2, &arg3);
			srand(time(NULL));
			for (int i = 0; i < arg1; i++) {
				int random_int = (rand() % (arg3 - arg2 + 1)) + arg2;
				if (!stack_push(stack, random_int)) {
					printf("Stack is full, can not push anymore. ");
					arg1 = i + 1; // Update arg1 to reflect how many values were actually pushed
					break;
				}
			}
			printf("Appended %d random values between %d and %d\n", arg1, arg2, arg3);
		} else if (strcmp(op, "help") == 0) {
			printf(help_message);
		} else if (strcmp(op, "exit") == 0 || strcmp(op, "quit") == 0) {
			printf("\nDeleting stack ...\n");
			stack_delete(stack);
			printf("\nDone. Exiting ...\n");
			break;
		} else {
			printf("\nUnknown operation: %s\n\n", op);
			printf(help_message);
		}
	}
	return 0;
}

the_stack *stack_create(int capacity) {
	the_stack *stack = (the_stack *)malloc(sizeof(the_stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->elements = (int *)malloc(stack->capacity * sizeof(int));
	return stack;
}

bool stack_push(the_stack *stack, int value) {
	if (stack->top == stack->capacity - 1) {
		return false;
	}
	stack->top++;
	stack->elements[stack->top] = value;
	return true;
}

int stack_pop(the_stack *stack) {
	if (stack->top == -1) {
		return -1; // Stack underflow
	}
	stack->top--;
	return stack->elements[stack->top];
}

int stack_peek(the_stack *stack) {
	if (stack->top == -1) {
		return -1; // Stack is empty
	}
	return stack->elements[stack->top];
}

bool stack_is_empty(the_stack *stack) {
	return stack->top == -1;
}

bool stack_is_full(the_stack *stack) {
	return stack->top == stack->capacity - 1;
}

void stack_delete(the_stack *stack) {
	free(stack->elements);
	free(stack);
}

void stack_print(the_stack *stack) {
	printf("Stack (top to bottom):\n");
	for (int i = stack->top; i >= 0; i--) {
		printf("%d, ", stack->elements[i]);
	}
	printf("\n");
}
