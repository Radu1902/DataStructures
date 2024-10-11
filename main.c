#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"
#include "DoublyLinkedList.h"

int main()
{
    int data_structure_choice = 0;

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

    struct Vector vec;
    vector_init(&vec);

    struct DoublyLinkedList dll;
    dll_init(&dll);

    

    while (data_structure_choice != 0)
    {
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
                    int popped = vector_pop(&vec);
                    printf("Popped value: %d\n", popped);
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
                printf("6.Insert value at occurance of a value\n");
                printf("7.Clear list\n");
                printf("8.Print (Show all list elements)\n");
                printf("0.Return to main menu\n");

                scanf_s("%d", &operation_choice);


            }
        }
        scanf_s("%d", &data_structure_choice);

    }


    return 0;
}