#include "Stack.h"

void stack_init(struct Stack* stack)
{
	stack->top = NULL;
}

void stack_push(struct Stack* stack, int value)
{
	struct StackNode* new_top = (struct StackNode*)malloc(sizeof(struct StackNode));
	new_top->data = value;
	new_top->next = NULL;

	if (stack_empty(*stack))
	{
		stack->top = new_top;
	}
	else
	{
		new_top->next = stack->top;
		stack->top = new_top;
	}
	printf("Pushed value %d to the stack\n", value);
}

void stack_pop(struct Stack* stack)
{
	if (stack_empty(*stack))
	{
		printf("Cannot pop from empty stack\n");
		return;
	}

	printf("Popping top, with the value: %d\n", stack->top->data);
	if (stack->top->next == NULL)
	{
		free(stack->top);
		stack_init(stack);
		return;
	}

	struct StackNode* new_top = stack->top->next;
	free(stack->top);
	stack->top = new_top;

}

int stack_peek(const struct Stack stack)
{
	if (stack_empty(stack))
	{
		printf("Cannot peek on empty stack. Returning -1 as a sentinel value.\n");
		return -1;
	}
	return stack.top->data;
}

bool stack_empty(const struct Stack stack)
{
	if (stack.top == NULL)
		return true;
	return false;
}

void stack_clear(struct Stack* stack)
{
	while (!stack_empty(*stack))
	{
		stack_pop(stack);
	}
}

void stack_print(const struct Stack stack)
{
	struct StackNode* current_node = stack.top;

	printf("\nTOP\n");
	while (current_node != NULL)
	{
		printf("%d\n---\n", current_node->data);
		current_node = current_node->next;
	}
	printf("---\n\nsize: %d\n", stack_size(stack));
}

unsigned int stack_size(const struct Stack stack)
{
	struct StackNode* current_node = stack.top;
	unsigned int counter = 0;

	while (current_node != NULL)
	{
		counter++;
		current_node = current_node->next;
	}

	return counter;
}