#ifndef LINKED_LIST_H
#define LINKED_LIST_H

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
ll_item_t* ll_get_last_item(ll_item_t* list_head);

/**
 * Returns the item at the given index in the list, or NULL if the index is out of bounds
 */
ll_item_t* ll_get_item_at_index(ll_item_t* list_head, int index);

/**
 * Prepends a new item with the given value to the beginning of the list
 */
ll_item_t* ll_insert_at_start(ll_item_t* list_head, int value);

/**
 * Appends a new item with the given value to the end of the list
 */
ll_item_t* ll_insert_at_end(ll_item_t* list_head, int value);

/**
 * Inserts a new item with the given value at the specified index in the list
 */
ll_item_t* ll_insert_at_index(ll_item_t* list_head, int index, int value);

/**
 * Traverse the linked list and apply the given function to each value
 */
void ll_traverse(ll_item_t* list_head, void (*func)(int));

/**
 * Print the list
 */
void ll_print(ll_item_t* list_head);

/**
 * Get the length of the list
 */
int ll_get_length(ll_item_t* list_head);

#endif // LINKED_LIST_H
