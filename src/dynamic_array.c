#include <stdio.h>
#include <stdlib.h>
#include "../include/dynamic_array.h"

int main(int argc, char *argv[]) {
	dynamic_array_t* array = create_dynamic_array();
	for (int index = 0; index < 10; index++) {
		append_to_dynamic_array(array, index);
	}
	print_dynamic_array(array);
}

dynamic_array_t* create_dynamic_array() {
	dynamic_array_t* array = malloc(sizeof(dynamic_array_t));
	array->length = 0;
	array->capacity = 4;
	array->data = malloc(sizeof(int) * array->capacity);
	return array;
}

void append_to_dynamic_array(dynamic_array_t* array, int value) {
	if (array->length == array->capacity) {
		array->capacity *= 2;
		array->data = realloc(array->data, sizeof(int) * array->capacity);
	}
	array->data[array->length] = value;
	array->length++;
}

void print_dynamic_array(dynamic_array_t* array) {
	printf("\n\nprint_dynamic_array() ...\n");
	for (int index = 0; index < array->length; index++) {
		printf("%d ", array->data[index]);
	}
	printf("\n\n");
}
