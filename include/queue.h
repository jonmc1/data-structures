#ifndef QUEUE_H
#define QUEUE_H

// Node structure
typedef struct QueueNode {
	int data;
	struct QueueNode* next;
} QueueNode;

// Queue structure
typedef struct queue {
	int length;
	QueueNode* front;
	QueueNode* rear;
} queue_t;

/**
 * Creat a new queue and return a pointer to it
 */
queue_t* queue_create();

/**
 * Check if the queue is empty. Returns 1 if empty, 0 otherwise
 */
int queue_is_empty(queue_t* queue);

/**
 * Add an element to the end of the queue
 */
void queue_add(queue_t* queue, int data);

/**
 * Remove and return the element at the front of the queue. Returns -1 if the queue is empty
 */
int queue_pop(queue_t* queue);

/**
 * Return the element at the front of the queue without removing it. Returns -1 if the queue is empty
 */
int queue_peek(queue_t* queue);

/**
 * Print the contents of the queue from front to back
 */
void queue_print(queue_t* queue);

/**
 * Delete the queue and free all associated memory
 */
void queue_delete(queue_t* queue);

#endif // QUEUE_H
