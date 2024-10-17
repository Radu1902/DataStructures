#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"
#include "Stack.h"
#include "Queue.h"
#include "DoublyLinkedList.h"

int main()
{
    int data_structure_choice = 1;


    struct Vector vec;
    vector_init(&vec);

    struct DoublyLinkedList dll;
    dll_init(&dll);

    struct Stack stack;
    stack_init(&stack);

    struct Queue queue;
    queue_init(&queue);

    while (data_structure_choice != 0)
    {
        printf("Choose data structure to work with:\n");
        printf("1.Vector\n");
        printf("2.Stack\n");
        printf("3.Queue\n");
        printf("4.Doubly linked list\n");
        printf("5.Hashmap\n");
        printf("6.Heap\n");
        printf("7.Binary tree\n");
        printf("8.Binary search tree\n");
        printf("9.Self-balancing search tree\n");
        printf("0.exit\n");

        scanf_s("%d", &data_structure_choice);

        int operation_choice = 1;

        if (data_structure_choice == 1)
        {
            while (operation_choice != 0)
            {
                printf("\n");
                printf("Choose vector operation:\n");
                printf("1.Pushback element\n");
                printf("2.Pop element\n");
                printf("3.Get value at index\n");
                printf("4.Insert value at index\n");
                printf("5.Erase value at index\n");
                printf("6.Read (Specify number of values, followed by the values themselves)\n");
                printf("7.Print (Show all vector data)\n");
                printf("0.Return to main menu\n");

                scanf_s("%d", &operation_choice);

                if (operation_choice == 1) // pushback
                {
                    int value;
                    printf("Choose value to push back: ");
                    scanf_s("%d", &value);
                    vector_push_back(&vec, value);
                }
                else if (operation_choice == 2) // pop
                {
                    vector_pop(&vec);
                }
                else if (operation_choice == 3) // get index value
                {
                    int index;
                    printf("Choose index: ");
                    scanf_s("%d", &index);
                    int value = vector_get_value(vec, index);
                    printf("Value at index %d: %d\n", index, value);
                }
                else if (operation_choice == 4) // insert at index
                {
                    int value;
                    printf("Choose value: ");
                    scanf_s("%d", &value);
                    int index;
                    printf("Choose index: ");
                    scanf_s("%d", &index);
                    vector_insert(&vec, value, index);
                }
                else if (operation_choice == 5) // erase at index
                {
                    int index;
                    printf("Choose index: ");
                    scanf_s("%d", &index);
                    vector_erase(&vec, index);
                }
                else if (operation_choice == 6) // read
                {
                    vector_read(&vec);
                }
                else if (operation_choice == 7) // print
                {
                    vector_print(vec);
                }
            }
        }
        else if (data_structure_choice == 2)
        {
            while (operation_choice != 0)
            {
                printf("\n");
                printf("Choose stack operation:\n");
                printf("1.Push element\n");
                printf("2.Pop element\n");
                printf("3.Peek element\n");
                printf("4.Clear stack\n");
                printf("5.Print stack\n");
                printf("0.Return to main menu\n");

                scanf_s("%d", &operation_choice);
                
                if (operation_choice == 1) // push
                {
                    int value = 0;
                    printf("Value to push: ");
                    scanf_s("%d", &value);
                    stack_push(&stack, value);
                }
                if (operation_choice == 2) // pop
                {
                    stack_pop(&stack);
                }
                if (operation_choice == 3) // peek
                {
                    printf("Value at the top of the stack: %d\n", stack_peek(stack));
                }
                if (operation_choice == 4) // clear
                {
                    stack_clear(&stack);
                }
                if (operation_choice == 5) // print
                {
                    stack_print(stack);
                }
            }
        }
        else if (data_structure_choice == 3)
        {
            while (operation_choice != 0)
            {
                printf("\n");
                printf("Choose queue operation:\n");
                printf("1.Enqueue element\n");
                printf("2.Dequeue element\n");
                printf("3.Peek element\n");
                printf("4.Clear queue\n");
                printf("5.Print queue\n");
                printf("0.Return to main menu\n");

                scanf_s("%d", &operation_choice);
                
                if (operation_choice == 1) // enqueue
                {
                    int value = 0;
                    printf("Value to enqueue: ");
                    scanf_s("%d", &value);
                    queue_enqueue(&queue, value);
                }
                if (operation_choice == 2) // dequeue
                {
                    queue_dequeue(&queue);
                }
                if (operation_choice == 3) // peek
                {
                    printf("Value at the front of the queue: %d\n", queue_peek(queue));
                }
                if (operation_choice == 4) // clear
                {
                    queue_clear(&queue);
                }
                if (operation_choice == 5) // print
                {
                    queue_print(queue);
                }
            }
        }

        else if (data_structure_choice == 4)
        {
            while (operation_choice != 0)
            {
                printf("\n");
                printf("Choose linked list operation:\n");
                printf("1.Pushback element\n");
                printf("2.Pushfront element\n");
                printf("3.Pop back element\n");
                printf("4.Pop front element\n");
                printf("5.Remove all occurances of a value\n");
                printf("6.Insert value at first occurance of a value\n");
                printf("7.Clear list\n");
                printf("8.Print (Show all list elements)\n");
                printf("0.Return to main menu\n");

                scanf_s("%d", &operation_choice);

                if (operation_choice == 1) // pushback
                {
                    int value;
                    printf("value to push back: ");
                    scanf_s("%d", &value);
                    dll_push_back(&dll, value);
                }
                else if (operation_choice == 2) // pushfront
                {
                    int value;
                    printf("value to push front: ");
                    scanf_s("%d", &value);
                    dll_push_front(&dll, value);
                }
                else if (operation_choice == 3) // pop back
                {
                    dll_pop_back(&dll);
                }
                else if (operation_choice == 4) // pop front
                {
                    dll_pop_front(&dll);
                }
                else if (operation_choice == 5) // remove
                {
                    int value;
                    printf("value to remove from list: ");
                    scanf_s("%d", &value);
                    dll_remove(&dll, value);
                }
                else if (operation_choice == 6) // insert
                {
                    int insert_location;
                    int insert_value;
                    printf("Choose the location of insertion, by specifying a value from the list: ");
                    scanf_s("%d", &insert_location);
                    struct ListNode* location_node = dll_find(dll, insert_location);
                    if (location_node != NULL)
                    {
                        printf("Choose the value to insert: ");
                        scanf_s("%d", &insert_value);
                        dll_insert(&dll, location_node, insert_value);
                    }
                    else
                    {
                        printf("Could not find any nodes with the specified value in the list.");
                    }
                }
                else if (operation_choice == 7) // clear
                {
                    dll_clear(&dll);
                }
                else if (operation_choice == 8) // print
                {
                    dll_print(dll);
                }
            }
        }
    }


    return 0;
}