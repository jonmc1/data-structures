#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/linked_list.h"

int main(int argc, char *argv[]) {
	ll_item_t* list_head = NULL;
	char op[32];
	int arg1;
	int arg2;
	int arg3;

	const char help_message[] = "Operations:"
		"\n- print"
		"\n- length"
		"\n- get <index>"
		"\n- prepend <value>"
		"\n- append <value>"
		"\n- insert <index> <value>"
		"\n- append-random-values <count> <min> <max>"
		"\n- help"
		"\n- exit|quit\n";

	printf(help_message);
	while (1) {
		printf("\n> ");
		scanf("%s", op);
		if (strcmp(op, "print") == 0) {
			ll_print(list_head);
		} else if (strcmp(op, "length") == 0) {
			printf("Length: %d\n", ll_get_length(list_head));
		} else if (strcmp(op, "get") == 0) {
			scanf("%d", &arg1);
			ll_item_t* item = ll_get_item_at_index(list_head, arg1);
			if (item != NULL) {
				printf("Value at index %d is %d\n", arg1, item->value);
			} else {
				printf("Index %d is out of bounds\n", arg1);
			}
		} else if (strcmp(op, "prepend") == 0) {
			scanf("%d", &arg1);
			list_head = ll_insert_at_start(list_head, arg1);
			printf("Prepended %d to the start of the list\n", arg1);
		} else if (strcmp(op, "append") == 0) {
			scanf("%d", &arg1);
			list_head = ll_insert_at_end(list_head, arg1);
			printf("Appended %d to the end of the list\n", arg1);
		} else if (strcmp(op, "insert") == 0) {
			scanf("%d %d", &arg1, &arg2);
			list_head = ll_insert_at_index(list_head, arg1, arg2);
			printf("Inserted %d at index %d\n", arg2, arg1);
		} else if (strcmp(op, "append-random-values") == 0) {
			scanf("%d %d %d", &arg1, &arg2, &arg3);
			srand(time(NULL));
			for (int i = 0; i < arg1; i++) {
				int random_int = (rand() % (arg3 - arg2 + 1)) + arg2;
				list_head = ll_insert_at_end(list_head, random_int);
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

ll_item_t* ll_get_last_item(ll_item_t* list_head) {
	if (list_head == NULL) {
		return NULL;
	}
	ll_item_t* list_item = list_head;
	while (list_item->next != NULL) {
		list_item = list_item->next;
	}
	return list_item;
}

ll_item_t* ll_get_item_at_index(ll_item_t* list_head, int index) {
	int current_index = 0;
	ll_item_t* list_item = list_head;
	while (list_item != NULL) {
		if (current_index == index) {
			return list_item;
		}
		current_index++;
		list_item = list_item->next;
	}
	return NULL; // Index out of bounds
}

ll_item_t* ll_insert_at_start(ll_item_t* list_head, int value) {
	ll_item_t* new_item = malloc(sizeof(ll_item_t));
	new_item->value = value;
	new_item->next = list_head;
	return new_item;
}

ll_item_t* ll_insert_at_end(ll_item_t* list_head, int value) {
	ll_item_t* new_item = malloc(sizeof(ll_item_t));
	new_item->value = value;
	new_item->next = NULL;
	if (list_head == NULL) {
		return new_item;
	}
	ll_item_t* last_item = ll_get_last_item(list_head);
	last_item->next = new_item;
	return list_head;
}

ll_item_t* ll_insert_at_index(ll_item_t* list_head, int index, int value) {
	if (index == 0) {
		return ll_insert_at_start(list_head, value);
	}
	int current_index = 0;
	ll_item_t* list_item = list_head;
	while (list_item != NULL) {
		if (current_index == index - 1) {
			ll_item_t* new_item = malloc(sizeof(ll_item_t));
			new_item->value = value;
			new_item->next = list_item->next;
			list_item->next = new_item;
			break;
		}
		current_index++;
		list_item = list_item->next;
	}
	return list_head; // No change to the list
}

void ll_traverse(ll_item_t* list_head, void (*func)(int)) {
	ll_item_t* list_item = list_head;
	while (list_item != NULL) {
		func(list_item->value);
		list_item = list_item->next;
	}
}

/**
 * Helper function to print a value, used in ll_print
 */
void print_value(int value) {
	printf("%d, ", value);
}

void ll_print(ll_item_t* list_head) {
	if (list_head == NULL) {
		printf("\nThe list is empty.\n");
		return;
	}
	printf("\nValues: \n");
	ll_traverse(list_head, print_value);
	printf("\n");
}

int ll_get_length(ll_item_t* list_head) {
	int length = 0;
	ll_item_t* list_item = list_head;
	while (list_item != NULL) {
		length++;
		list_item = list_item->next;
	}
	return length;
}
