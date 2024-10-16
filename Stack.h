#pragma once
#include <stdlib.h>
#include <stdbool.h>

struct StackNode
{
	int data;
	struct StackNode* next;
};

struct Stack
{
	struct StackNode* top;
};

void stack_init(struct Stack* stack);

void stack_push(struct Stack* stack, int value);
void stack_pop(struct Stack* stack);
int stack_peek(const struct Stack stack);

bool stack_empty(const struct Stack stack); // verifies if stack is empty
void stack_clear(struct Stack* stack); // deletes entire stack
void stack_print(const struct Stack stack);

unsigned int stack_size(const struct Stack stack);