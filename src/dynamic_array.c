#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/dynamic_array.h"

int main(int argc, char *argv[]) {
	dynamic_array_t* array = da_create();
	char op[32];
	int arg1;
	int arg2;
	int arg3;

	const char help_message[] = "Operations:\n- print\n- length\n- get <index>\n- set <index> <value>"
		"\n- append <value>\n- append-random-values <count> <min> <max>\n- help\n- exit|quit\n";

	printf(help_message);
	while (1) {
		printf("\n> ");
		scanf("%s", op);
		if (strcmp(op, "print") == 0) {
			da_print(array);
		} else if (strcmp(op, "length") == 0) {
			printf("Length: %d\n", array->length);
		} else if (strcmp(op, "get") == 0) {
			scanf("%d", &arg1);
			printf("Value at index %d is %d\n", arg1, da_get(array, arg1));
		} else if (strcmp(op, "set") == 0) {
			scanf("%d %d", &arg1, &arg2);
			da_set(array, arg1, arg2);
			printf("Index %d set to %d\n", arg1, arg2);
		} else if (strcmp(op, "append") == 0) {
			scanf("%d", &arg1);
			da_append(array, arg1);
			printf("Appended %d to the end of the array\n", arg1);
		} else if (strcmp(op, "append-random-values") == 0) {
			scanf("%d %d %d", &arg1, &arg2, &arg3);
			srand(time(NULL));
			for (int i = 0; i < arg1; i++) {
				int random_int = (rand() % (arg3 - arg2 + 1)) + arg2;
				da_append(array, random_int);
			}
			printf("Appended %d random values between %d and %d\n", arg1, arg2, arg3);
		} else if (strcmp(op, "help") == 0) {
			printf(help_message);
		} else if (strcmp(op, "exit") == 0 || strcmp(op, "quit") == 0) {
			printf("\nExiting...\n");
			break;
		} else {
			printf("\nUnknown operation: %s\n\n", op);
			printf(help_message);
		}
	}
	return 0;
}

dynamic_array_t* da_create() {
	dynamic_array_t* array = malloc(sizeof(dynamic_array_t));
	array->length = 0;
	array->capacity = 4;
	array->data = malloc(sizeof(int) * array->capacity);
	return array;
}

int da_get(dynamic_array_t* array, int index) {
	if (index < 0 || index >= array->length) {
		printf("Index %d is out of bounds. Valid range is 0 to %d.\n", index, array->length - 1);
		return 0;
	}
	return array->data[index];
}

void da_set(dynamic_array_t* array, int index, int value) {
	if (index < 0 || index >= array->length) {
		printf("Index %d is out of bounds. Valid range is 0 to %d.\n", index, array->length - 1);
		return;
	}
	array->data[index] = value;
}

void da_append(dynamic_array_t* array, int value) {
	if (array->length == array->capacity) {
		array->capacity *= 2;
		array->data = realloc(array->data, sizeof(int) * array->capacity);
	}
	array->data[array->length] = value;
	array->length++;
}

void da_traverse(dynamic_array_t* array, void (*func)(int)) {
	for (int index = 0; index < array->length; index++) {
		func(array->data[index]);
	}
}

void print_value(int value) {
	printf("%d, ", value);
}

void da_print(dynamic_array_t* array) {
	if (array->length == 0) {
		printf("\nThe array is empty.\n");
		return;
	}
	printf("\nValues: \n");
	da_traverse(array, print_value);
	printf("\n");
}
