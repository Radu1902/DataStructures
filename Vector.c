#include "Vector.h"

void vector_init(struct Vector* vec)
{
    vec->size = 0;
    vec->capacity = 1;
    vec->elements = (float*)malloc(sizeof(float));
}

void push_back(struct Vector* vec, float elem)
{
    if (vec->size != 0)
    {
        vector_init(vec);
    }
    vec->size++;
    if (vec->size >= vec->capacity)
        resize(vec);

    vec->elements[vec->size - 1] = elem;
}

float pop(struct Vector* vec)
{
    return 42.0f;
}

void resize(struct Vector* vec)
{
    float* tempElements = (float*)malloc(sizeof(float) * vec->size);
    for (unsigned int i = 0; i < vec->size; i++)
    {
        tempElements[i] = vec->elements[i];
    }
    free(vec->elements);

    vec->capacity = vec->capacity * 2;
    vec->elements = (float*)malloc(sizeof(float) * vec->capacity);
    for (unsigned int i = 0; i < vec->size; i++)
    {
        vec->elements[i] = tempElements[i];
    }
    free(tempElements);
}

float get_value(const struct Vector vec, const unsigned int index)
{
    if (index >= vec.size)
    {
        printf("Invalid index\n");
        return -1.0f;
    }
    return vec.elements[index];
}

void read(struct Vector* vec)
{
    int count = 0;
    printf("Choose number of input elements:\n");
    do
    {
        scanf("%d", &count);
        if (count <= 0)
            printf("Number of input elements must be bigger than 0.\n");
    } while (count <= 0);

    for (unsigned int i = 0; i < count; i++)
    {
        scanf("%f", &(vec->elements[i]));
    }
}

void print(const struct Vector vec)
{
    for (unsigned int i = 0; i < vec.size; i++)
    {
        printf("%d ", vec.elements[i]);
    }
    printf("\n");
}