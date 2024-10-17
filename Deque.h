#pragma once
#include <stdlib.h>
#include <stdbool.h>

struct DequeNode
{
	int data;
	struct DequeNode* next;
	struct DequeNode* prev;
};

struct Deque
{
	struct DequeNode* front;
	struct DequeNode* rear;
};

void deque_init(struct Deque* deque);

void deque_push_front(struct Deque* deque, int value);
void deque_push_back(struct Deque* deque, int value);
void deque_pop_front(struct Deque* deque);
void deque_pop_back(struct Deque* deque);
int deque_front(const struct Deque deque);
int deque_rear(const struct Deque deque);

bool deque_empty(const struct Deque deque); // verifies if list is empty
void deque_clear(struct Deque* deque); // deletes entire list
void deque_print(const struct Deque deque);

unsigned int deque_size(const struct Deque deque);