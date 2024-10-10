#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"

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

    printf("%d, %d", vec.size, vec.capacity);

    int operation_choice = 0;
    float temp_val;
    int temp_count;

    while (data_structure_choice != 0)
    {
        if (data_structure_choice == 1)
        {
            scanf_s("%d", &operation_choice);
            while (operation_choice != 0)
            {
                printf("Choose vector operation:");
                printf("1.Pushback element");
                printf("2.Pop element");
                printf("3.Read (Specify number of values, followed by the values themselves)");
                printf("4.Print (Show entire vector data)");
                printf("5.Get value at index");

                scanf_s("%d", &operation_choice);

                if (operation_choice == 1)
                {
                    scanf_s("%f", &temp_val);
                    push_back(&vec, temp_val);
                    printf("")
                }

            }
        }
        scanf_s("%d", &data_structure_choice);

    }


    return 0;
}