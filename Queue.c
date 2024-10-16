#include "Queue.h"

void queue_init(struct Queue* queue)
{
	queue->front == NULL;
	queue->rear == NULL;
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
		new_rear->next = queue->rear;
		queue->rear = new_rear;
	}
	printf("Enqueuing value %d to the queue\n", value);
}

void queue_dequeue(struct Queue* queue)
{
	if (queue_empty(*queue))
	{
		printf("Cannot pop from empty queue\n");
		return;
	}

	printf("Dequeuing queue, front had the value: %d\n", queue->front->data);
	if (queue->rear == queue->front) // if the queue only has one element
	{
		free(queue->front);
		queue_init(queue);
		return;
	}

	struct ListNode* new_front = queue->rear->next;
	free(stack->top);
	stack->top = new_top;

}
