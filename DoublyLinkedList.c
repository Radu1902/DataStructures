#include "DoublyLinkedList.h"

void list_node_init(struct ListNode* ln)
{
	ln->data = 0;
	ln->next = NULL;
	ln->prev = NULL;
}

void dll_init(struct DoublyLinkedList* dll)
{
	dll->head = NULL;
	dll->tail = NULL;
}

void dll_push_front(struct DoublyLinkedList* dll, int value)
{
	struct ListNode* new_front_node = (struct ListNode*)malloc(sizeof(struct ListNode));
	new_front_node->data = value;
	new_front_node->prev = NULL;

	if (dll_empty(*dll))
	{
		dll->head = new_front_node;
		dll->tail = new_front_node;
	}
	else
	{
		dll->head->prev = new_front_node;
		new_front_node->next = dll->head;
		dll->head = new_front_node;
	}
	printf("Pushed value %d to the front of the list\n", value);
}

void dll_push_back(struct DoublyLinkedList* dll, int value)
{
	struct ListNode* new_back_node = (struct ListNode*)malloc(sizeof(struct ListNode));
	new_back_node->data = value;
	new_back_node->next = NULL;

	if (dll_empty(*dll))
	{
		dll->tail = new_back_node;
		dll->head = new_back_node;
	}
	else
	{
		dll->tail->next = new_back_node;
		new_back_node->prev = dll->tail;
		dll->tail = new_back_node;
	}
	printf("Pushed value %d to the back of the list\n", value);
}

void dll_pop_front(struct DoublyLinkedList* dll)
{
	if (dll_empty(*dll))
	{
		printf("Cannot pop from empty list\n");
		return;
	}

	printf("Popping front node, with the value: %d\n", dll->head->data);
	if (dll->head->next == NULL)
	{
		free(dll->head);
		dll_init(dll);
		return;
	}

	struct ListNode* new_head = dll->head->next;
	new_head->prev = NULL;
	free(dll->head); // bug ciudat, se intampla doar dupa ce apelez push_front macar o data pe lista
	dll->head = new_head;
}
void dll_pop_back(struct DoublyLinkedList* dll)
{
	if (dll_empty(*dll))
	{
		printf("Cannot pop from empty list\n");
		return;
	}

	printf("Popping back node, with the value: %d\n", dll->tail->data);
	if (dll->tail->prev == NULL)
	{
		free(dll->tail);
		dll_init(dll);
		return;
	}

	struct ListNode* new_tail = dll->tail->prev;
	new_tail->next = NULL;
	free(dll->tail);
	dll->tail = new_tail;
}

struct ListNode* dll_find(const struct DoublyLinkedList dll, const int value)
{
	struct ListNode* current_node = dll.head;

	while (current_node != NULL)
	{
		if (current_node->data == value)
			return current_node;
		current_node = current_node->next;
	}
	return NULL;
}

void dll_erase(struct DoublyLinkedList* dll, struct ListNode* node)
{
	if (node == dll->head)
	{
		dll_pop_front(dll);
		return;
	}
	if (node == dll->tail)
	{
		dll_pop_back(dll);
		return;
	}

	struct ListNode* prev_node = node->prev;
	struct ListNode* next_node = node->next;
	prev_node->next = next_node;
	next_node->prev = prev_node;
	printf("Erasing node at location: %p\n", node);

	free(node);
}

void dll_remove(struct DoublyLinkedList* dll, const int value)
{
	struct ListNode* node_to_remove = dll_find(*dll, value);

	while (node_to_remove != NULL)
	{
		dll_erase(dll, node_to_remove);
		node_to_remove = dll_find(*dll, value);
	}
	printf("Removed all elements with the value: %d\n", value);
}

void dll_insert(struct DoublyLinkedList* dll, struct  ListNode* node, const int value)
{
	if (node == dll->tail->prev)
	{
		dll_push_back(dll, value);
		return;
	}

	struct ListNode* next_node = node->next;

	struct ListNode* inserted_node = (struct Listnode*)malloc(sizeof(struct ListNode));
	inserted_node->data = value;

	inserted_node->prev = node;
	node->next = inserted_node;
	inserted_node->next = next_node;
	next_node->prev = inserted_node;

	printf("Inserting value %d after node at location %p\n", value, node);
}

bool dll_empty(const struct DoublyLinkedList dll)
{
	if (dll.head == NULL)
		return true;
	return false;
}

void dll_clear(struct DoublyLinkedList* dll)
{
	struct ListNode* current_node = dll->head;
	printf("Clearing list...\n");

	while (!dll_empty(*dll))
	{
		dll_pop_front(dll);
	}
}

void dll_print(const struct DoublyLinkedList dll)
{
	struct ListNode* current_node = dll.head;

	printf("HEAD <-> ");
	while (current_node != NULL)
	{
		printf("%d <-> ", current_node->data);
		current_node = current_node->next;
	}
	printf("TAIL\n");
	
	unsigned int size = dll_size(dll);
	printf("size: %d\n", size);
}

unsigned int dll_size(const struct DoublyLinkedList dll)
{
	struct ListNode* current_node = dll.head;
	unsigned int counter = 0;

	while (current_node != NULL)
	{
		counter++;
		current_node = current_node->next;
	}
	return counter;
}
