#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"

int main()
{
    int dataStructureChoice = 0;

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

    scanf("%d", &dataStructureChoice);

    struct Vector v;

    int operationChoice = 0;
    while (dataStructureChoice != 0)
    {
        if (dataStructureChoice == 1)
        {
            printf("Choose vector operation:");
            printf("1.Pushback element");
            printf("1.Pop element");
            printf("1.Read (Specify number of values, followed by the values themselves)");
            printf("1.Print (Show entire vector data)");
            printf("1.Print");
        }
    }


    return 0;
}