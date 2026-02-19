/**
 * Linked List Item
 */
typedef struct ll_item {
	int value;
	struct ll_item *next;
} ll_item_t;

/**
 * Returns the last item in the list, or NULL if the list is empty.
 */
ll_item_t* get_last_item(ll_item_t* list_head);

/**
 * Appends a new item with the given value to the end of the list
 */
ll_item_t* append_item(ll_item_t* list_head, int value);

/**
 * Print the list
 */
void print_list(ll_item_t* list_head);
