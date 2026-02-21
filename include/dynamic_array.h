/**
 * Dynamic Array
 */
typedef struct dynamic_array {
	int length;
	int capacity;
	int *data;
} dynamic_array_t;

/**
 * Create a new dynamic array
 *
 * Initial capacity is 4, and it doubles when the length reaches the capacity
 */
dynamic_array_t* da_create();

/**
 * Append a value to the end of the dynamic array
 */
void da_append(dynamic_array_t* array, int value);

/**
 * Get the value at the given index in the dynamic array
 */
int da_get(dynamic_array_t* array, int index);

/**
 * Set the value to the given index in the dynamic array
 */
void da_set(dynamic_array_t* array, int index, int value);

/**
 * Traverse the dynamic array and apply the given function to each value
 */
void da_traverse(dynamic_array_t* array, void (*func)(int));

/**
 * Print the dynamic array
 */
void da_print(dynamic_array_t* array);
