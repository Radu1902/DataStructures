#include "Vector.h"

struct Vector vectorInit()
{
    struct Vector v;
    v.size = 0;
    v.capacity = 1;
    v.elements = (float*)malloc(sizeof(float));
    return v;
}

void push_back(struct Vector* vec, float elem)
{
    vec->size++;
    if (vec->size >= vec->capacity)
        resize(vec);

    vec->elements[vec->size - 1] = elem;
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