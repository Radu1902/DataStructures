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
	struct ListNode* new_front_node = (struct ListNode*)malloc(sizeof(struct ListNode*));
	new_front_node->data = value;
	new_front_node->prev = dll->head;

	if (dll_empty(*dll))
	{
		dll->tail->prev = new_front_node;
	}

	if (dll->head->next != NULL)
	{
		struct ListNode* former_front_node = dll->head->next;
		former_front_node->prev = new_front_node;
		new_front_node->next = former_front_node;
	}
	dll->head->next = new_front_node;
	printf("Pushed value %d to the front of the list", value);
}

void dll_push_back(struct DoublyLinkedList* dll, int value)
{
	struct ListNode* new_back_node = (struct ListNode*)malloc(sizeof(struct ListNode));
	new_back_node->data = value;
	new_back_node->next = dll->tail;

	if (dll_empty(*dll))
	{
		dll->head->next = new_back_node;
	}

	if (dll->tail->prev != NULL)
	{
		struct ListNode* former_back_node = dll->tail->prev;
		former_back_node->next = new_back_node;
		new_back_node->prev = former_back_node;
	}
	dll->tail->prev = new_back_node;
	printf("Pushed value %d to the back of the list", value);
}

void dll_pop_front(struct DoublyLinkedList* dll)
{
	struct ListNode* front_node = dll->head->next;
	printf("Popping front node, with the value: ", front_node->data);
	dll->head->next = front_node->next;
	if (dll->head->next == NULL)
		dll->tail->prev == NULL;
	free(front_node);
}
void dll_pop_back(struct DoublyLinkedList* dll)
{
	struct ListNode* back_node = dll->tail->prev;
	printf("Popping back node, with the value: ", back_node->data);
	dll->tail->prev = back_node->prev;
	if (dll->tail->prev == NULL)
		dll->head->next == NULL;
	free(back_node);
}

struct ListNode* dll_find(const struct DoublyLinkedList dll, const int value)
{
	struct ListNode* current_node = dll.head;
	// se poate sa-mi dea erori la parcurgeri pentru ca head e null si sa nu-mi intre in while, sau cand incerc sa accesez campu data

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
	struct ListNode* prev_node = node->prev;
	struct ListNode* next_node = node->next;

	if (dll->head->next == node)
	{
		dll->head->next = next_node;
	}
	if (dll->tail->prev == node)
	{
		dll->tail->prev = prev_node;
	}

	if (prev_node != NULL)
	{
		prev_node->next = next_node;
	}
	if (next_node != NULL)
	{
		next_node->prev = prev_node;
	}
	
	free(node);
}

void dll_remove(struct DoublyLinkedList* dll, const int value)
{
	struct ListNode* searching_node = dll_find(*dll, value);

	while (searching_node != NULL)
	{
		dll_erase(dll, searching_node);
		dll_find(*dll, value);
	}
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
	inserted_node->prev = node;
	node->next = inserted_node;
	inserted_node->next = next_node;
	next_node->prev = inserted_node;
}

bool dll_empty(const struct DoublyLinkedList dll)
{
	if (dll.head->next == NULL && dll.tail->prev == NULL)
		return true;
	return false;
}

void dll_clear(struct DoublyLinkedList* dll)
{
	struct ListNode* current_node = dll->head;

	while (!dll_empty(*dll))
	{
		dll_pop_front(dll);
	}
}

void dll_print(const struct DoublyLinkedList dll)
{
	struct ListNode* current_node = dll.head;

	while (current_node != NULL)
	{
		printf("%d <-> ", current_node->data);
		current_node = current_node->next;
	}
	printf("NULL\n");
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
