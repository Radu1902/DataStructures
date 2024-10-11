#pragma once
#include <stdlib.h>
#include <stdbool.h>

struct ListNode
{
	int data;
	struct ListNode* next;
	struct ListNode* prev;
};

void list_node_init(struct ListNode* ln);

struct DoublyLinkedList
{
	struct ListNode* head;
	struct ListNode* tail;
};

void dll_init(struct DoublyLinkedList* dll);

void dll_push_front(struct DoublyLinkedList* dll, int value);
void dll_push_back(struct DoublyLinkedList* dll, int value);
void dll_pop_front(struct DoublyLinkedList* dll);
void dll_pop_back(struct DoublyLinkedList* dll);

struct ListNode* dll_find(const struct DoublyLinkedList dll, const int value);

void dll_erase(struct DoublyLinkedList* dll, struct ListNode* node); // deletes specific node from list
void dll_remove(struct DoublyLinkedList* dll, const int value); // deletes all nodes from list with a specific value
void dll_insert(struct DoublyLinkedList* dll, struct ListNode* node, const int value);

bool dll_empty(const struct DoublyLinkedList dll); // verifies if list is empty
void dll_clear(struct DoublyLinkedList* dll); // deletes entire list
void dll_print(const struct DoublyLinkedList dll);

unsigned int dll_size(const struct DoublyLinkedList dll);