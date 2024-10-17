#include "Deque.h"

void deque_init(struct Deque* deque)
{
	deque->front = NULL;
	deque->rear = NULL;
}

void deque_push_front(struct Deque* deque, int value)
{
	struct DequeNode* new_front = (struct DequeNode*)malloc(sizeof(struct DequeNode));
	new_front->data = value;
	new_front->prev = NULL;

	if (deque_empty(*deque))
	{
		deque->front = new_front;
		deque->rear = new_front;
	}
	else
	{
		deque->front->prev = new_front;
		new_front->next = deque->front;
		deque->front = new_front;
	}
	printf("Pushed value %d to the front of the deque\n", value);

}

void deque_push_back(struct Deque* deque, int value)
{
	struct DequeNode* new_rear = (struct DequeNode*)malloc(sizeof(struct DequeNode));
	new_rear->data = value;
	new_rear->next = NULL;

	if (deque_empty(*deque))
	{
		deque->rear = new_rear;
		deque->front = new_rear;
	}
	else
	{
		deque->rear->next = new_rear;
		new_rear->prev = deque->rear;
		deque->rear = new_rear;
	}
	printf("Pushed value %d to the rear of the deque\n", value);

}

void deque_pop_front(struct Deque* deque)
{
	if (deque_empty(*deque))
	{
		printf("Cannot pop from empty list\n");
		return;
	}

	printf("Popping front node, with the value: %d\n", deque->front->data);
	if (deque->front->next == NULL)
	{
		free(deque->front);
		dll_init(deque);
		return;
	}

	struct DequeNode* new_front = deque->front->next;
	new_front->prev = NULL;
	free(deque->front);
	deque->front = new_front;
}

void deque_pop_back(struct Deque* deque)
{
	if (deque_empty(*deque))
	{
		printf("Cannot pop from empty list\n");
		return;
	}

	printf("Popping back node, with the value: %d\n", deque->rear->data);
	if (deque->rear->prev == NULL)
	{
		free(deque->rear);
		dll_init(deque);
		return;
	}

	struct DequeNode* new_rear = deque->rear->prev;
	new_rear->next = NULL;
	free(deque->rear);
	deque->rear = new_rear;
}

int deque_front(const struct Deque deque)
{
	if (deque_empty(deque))
	{
		printf("Empty deque. Returning -1 as a sentinel value\n");
		return -1;
	}
	return deque.front->data;
}

int deque_rear(const struct Deque deque)
{
	if (deque_empty(deque))
	{
		printf("Empty deque. Returning -1 as a sentinel value\n");
		return -1;
	}
	return deque.rear->data;
}

bool deque_empty(const struct Deque deque)
{
	if (deque.front == NULL)
	{
		return true;
	}
	return false;
}

void deque_clear(struct Deque* deque)
{
	while (!deque_empty(*deque))
	{
		deque_pop_front(deque);
	}
}

void deque_print(const struct Deque deque)
{
	struct DequeNode* current_node = deque.front;

	printf("FRONT <-> ");
	while (current_node != NULL)
	{
		printf("%d <-> ", current_node->data);
		current_node = current_node->next;
	}
	printf("REAR\n");

	printf("size: %d\n", deque_size(deque)); 
}

unsigned int deque_size(const struct Deque deque)
{
	struct DequeNode* current_node = deque.front;

	unsigned int counter = 0;
	while (current_node != NULL)
	{
		counter++;
		current_node = current_node->next;
	}
}
