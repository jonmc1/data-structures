#include <stdio.h>
#include <stdlib.h>
#include "../include/linked_list.h"

int main(int argc, char *argv[]) {
	ll_item_t* list_head = NULL;
	for (int index = 0; index < 10; index++) {
		list_head = append_item(list_head, index);
	}
	print_list(list_head);
}

ll_item_t* get_last_item(ll_item_t* list_head) {
	if (list_head == NULL) {
		return NULL;
	}
	ll_item_t* list_item = list_head;
	while (list_item->next != NULL) {
		list_item = list_item->next;
	}
	return list_item;
}

ll_item_t* append_item(ll_item_t* list_head, int value) {
	ll_item_t* new_item = malloc(sizeof(ll_item_t));
	new_item->value = value;
	new_item->next = NULL;
	printf("Appending Value: %d\n", new_item->value);

	if (list_head == NULL) {
		return new_item;
	}

	ll_item_t* last_item = get_last_item(list_head);
	last_item->next = new_item;
	return list_head;
}

void print_list(ll_item_t* list_head) {
	printf("\n\nprint_list() ...\n");
	if (list_head == NULL) {
		return;
	}
	ll_item_t* list_item = list_head;

	while (1) {
		printf("%d", list_item->value);
		if (list_item->next == NULL) {
			break;
		}
		printf(" -> ");
		list_item = list_item->next;
	}
	printf("\n\n");
}
