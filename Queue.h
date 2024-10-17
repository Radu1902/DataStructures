#pragma once
#include <stdlib.h>
#include <stdbool.h>

struct QueueNode
{
	int data;
	struct QueueNode* next;
};

struct Queue
{
	struct QueueNode* front;
	struct QueueNode* rear;
};

void queue_init(struct Queue* queue);

void queue_enqueue(struct Queue* queue, int value);
void queue_dequeue(struct Queue* queue);
int queue_peek(const struct Queue queue);

bool queue_empty(const struct Queue queue); // verifies if queue is empty
void queue_clear(struct Queue* queue); // deletes entire queue
void queue_print(const struct Queue queue);

unsigned int queue_size(const struct Queue queue);