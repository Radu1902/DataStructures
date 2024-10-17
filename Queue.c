#include "Queue.h"

void queue_init(struct Queue* queue)
{
	queue->front = NULL;
	queue->rear = NULL;
}

void queue_enqueue(struct Queue* queue, int value)
{
	struct QueueNode* new_rear = (struct QueueNode*)malloc(sizeof(struct QueueNode));
	new_rear->data = value;
	new_rear->next = NULL;

	if (queue_empty(*queue))
	{
		queue->front = new_rear;
		queue->rear = new_rear;
	}
	else
	{
		queue->rear->next = new_rear;
		queue->rear = new_rear;
	}
	printf("Enqueuing value %d to the queue\n", value);
}

void queue_dequeue(struct Queue* queue)
{
	if (queue_empty(*queue))
	{
		printf("Cannot dequeue empty queue\n");
		return;
	}

	printf("Dequeuing queue, front had the value: %d\n", queue->front->data);
	if (queue->rear == queue->front) // if the queue has only one element
	{
		free(queue->front);
		queue_init(queue);
		return;
	}

	struct ListNode* new_front = queue->front->next;
	free(queue->front);
	queue->front = new_front;
}

int queue_peek(const struct Queue queue)
{
	if (queue_empty(queue))
	{
		printf("Cannot peek on empty queue. Returning -1 as a sentinel value.");
		return -1;
	}
	return queue.front->data;
}

bool queue_empty(const struct Queue queue)
{
	if (queue.front == NULL)
		return true;
	return false;
}

void queue_clear(struct Queue* queue)
{
	while (!queue_empty(*queue))
	{
		queue_dequeue(queue);
	}
}

void queue_print(const struct Queue queue)
{
	struct QueueNode* current_node = queue.front;

	printf("FRONT -> ");
	while (current_node != NULL)
	{
		printf("%d -> ", current_node->data);
		current_node = current_node->next;
	}
	printf("REAR\n");
	printf("size: %d\n", queue_size(queue));
}

unsigned int queue_size(const struct Queue queue)
{
	struct QueueNode* current_node = queue.front;
	unsigned int counter = 0;

	while (current_node != NULL)
	{
		counter++;
		current_node = current_node->next;
	}

	return counter;
}


