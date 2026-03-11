#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/queue.h"

int main(int argc, char *argv[]) {
	char op[32];
	int arg1;
	int arg2;
	int arg3;

	queue_t *queue = queue_create();

	const char help_message[] = "Operations:"
		"\n- print"
		"\n- is-empty"
		"\n- length"
		"\n- add <value>"
		"\n- pop"
		"\n- peek"
		"\n- add-random-values <count> <min> <max>"
		"\n- help"
		"\n- exit|quit\n";

	printf(help_message);
	while (1) {
		printf("\n> ");
		scanf("%s", op);
		if (strcmp(op, "print") == 0) {
			queue_print(queue);
		} else if (strcmp(op, "is-empty") == 0) {
			printf(queue_is_empty(queue) ? "Queue is empty\n" : "Queue is not empty\n");
		} else if (strcmp(op, "length") == 0) {
			printf("Queue length: %d\n", queue->length);
		} else if (strcmp(op, "add") == 0) {
			scanf("%d", &arg1);
			queue_add(queue, arg1);
			printf("Added %d to the queue\n", arg1);
		} else if (strcmp(op, "pop") == 0) {
			int value = queue_pop(queue);
			if (value != -1) {
				printf("Removed %d from the queue\n", value);
			} else {
				printf("Queue is empty.\n");
			}
		} else if (strcmp(op, "peek") == 0) {
			int value = queue_peek(queue);
			if (value != -1) {
				printf("Front of the queue: %d\n", value);
			} else {
				printf("Queue is empty\n");
			}
		} else if (strcmp(op, "add-random-values") == 0) {
			scanf("%d %d %d", &arg1, &arg2, &arg3);
			srand(time(NULL));
			for (int i = 0; i < arg1; i++) {
				int random_int = (rand() % (arg3 - arg2 + 1)) + arg2;
				queue_add(queue, random_int);
			}
			printf("Added %d random values between %d and %d\n", arg1, arg2, arg3);
		} else if (strcmp(op, "help") == 0) {
			printf(help_message);
		} else if (strcmp(op, "exit") == 0 || strcmp(op, "quit") == 0) {
			printf("\nDeleting queue ...\n");
			queue_delete(queue);
			printf("\nDone. Exiting ...\n");
			break;
		} else {
			printf("\nUnknown operation: %s\n\n", op);
			printf(help_message);
		}
	}
	return 0;
}

QueueNode* queue_new_node(int data) {
	QueueNode* new_node = malloc(sizeof(QueueNode));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

queue_t* queue_create() {
	queue_t* queue = malloc(sizeof(queue_t));
	queue->front = NULL;
	queue->rear = NULL;
	queue->length = 0;
	return queue;
}

int queue_is_empty(queue_t* queue) {
	return queue->front == NULL;
}

void queue_add(queue_t* queue, int data) {
	QueueNode* new_node = queue_new_node(data);
	if (queue_is_empty(queue)) {
		queue->front = new_node;
		queue->rear = new_node;
	} else {
		queue->rear->next = new_node;
		queue->rear = new_node;
	}
	queue->length++;
}

int queue_pop(queue_t* queue) {
	if (queue_is_empty(queue)) {
		return -1;
	}
	QueueNode* temp = queue->front;
	queue->front = queue->front->next;
	int returnValue = temp->data;
	free(temp);
	queue->length--;
	return returnValue;
}

int queue_peek(queue_t* queue) {
	if (queue_is_empty(queue)) {
		return -1;
	}
	return queue->front->data;
}

void queue_print(queue_t* queue) {
	if (queue_is_empty(queue)) {
		printf("Queue is empty\n");
		return;
	}
	printf("Queue (front to back):\n");
	QueueNode* current = queue->front;
	while (current != NULL) {
		printf("%d, ", current->data);
		current = current->next;
	}
	printf("\n");
}

void queue_delete(queue_t* queue) {
	while (!queue_is_empty(queue)) {
		queue_pop(queue);
	}
	free(queue);
}
