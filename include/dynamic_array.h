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
dynamic_array_t* create_dynamic_array();

/**
 * Append a value to the end of the dynamic array
 */
void append_to_dynamic_array(dynamic_array_t* array, int value);

/**
 * Print the dynamic array
 */
void print_dynamic_array(dynamic_array_t* array);
