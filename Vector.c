#include "Vector.h"

void vector_init(struct Vector* vec)
{
    vec->size = 0;
    vec->capacity = 1;
    vec->elements = (float*)malloc(sizeof(float));
}

bool vector_empty(const struct Vector vec) // returns true if vector is NULL, false otherwise
{
    if (vec.elements == NULL || vec.size == 0)
        return true;
    return false;
}

void vector_push_back(struct Vector* vec, float val)
{
    if (vector_empty(*vec))
    {
        vector_init(vec);
    }
    vector_resize(vec);

    vec->elements[vec->size] = val;
    printf("Pushed value %f at index %d\n", val, vec->size);
    vec->size++;
}

float vector_pop(struct Vector* vec)
{
    if (vector_empty(*vec))
    {
        printf("Cannot pop from empty vector\n");
        return -1.0f;
    }

    float tail = vec->elements[vec->size - 1];
    float* temp_elems = (float*)malloc(sizeof(float) * (vec->size));
    for (unsigned int i = 0; i < vec->size - 1; i++)
    {
        temp_elems[i] = vec->elements[i];
    }
    free(vec->elements);
    vec->size--;

    vec->elements = (float*)malloc(sizeof(float) * vec->capacity);
    for (unsigned int i = 0; i < vec->size; i++)
    {
        vec->elements[i] = temp_elems[i];
    }
    free(temp_elems);
    return tail;
}

void vector_resize(struct Vector* vec)
{
    if (vec->size < vec->capacity)
        return;

    float* temp_elems = (float*)malloc(sizeof(float) * vec->size);
    for (unsigned int i = 0; i < vec->size; i++)
    {
        temp_elems[i] = vec->elements[i];
    }
    free(vec->elements);

    vec->capacity = vec->capacity * 2;
    vec->elements = (float*)malloc(sizeof(float) * vec->capacity);
    for (unsigned int i = 0; i < vec->size; i++)
    {
        vec->elements[i] = temp_elems[i];
    }
    free(temp_elems);
}

float vector_get_value(const struct Vector vec, const int index)
{
    if (index >= vec.size || index < 0)
    {
        printf("Invalid index\n");
        return -1.0f;
    }
    return vec.elements[index];
}

void vector_insert(struct Vector* vec, const float value, const int index)
{
    if (index > vec->size)
    {
        printf("Invalid index\n");
        return;
    }
    vector_resize(vec);

    float* temp_elems = (float*)malloc(sizeof(float) * (vec->size + 1));

    for (unsigned int i = 0; i < index; i++)
    {
        temp_elems[i] = vec->elements[i];
    }
    temp_elems[index] = value;
    for (unsigned int i = index + 1; i < vec->size + 1; i++)
    {
        temp_elems[i] = vec->elements[i - 1];
    }

    vec->size++;
    for (unsigned int i = 0; i < vec->size; i++)
    {
        vec->elements[i] = temp_elems[i];
    }

    free(temp_elems);

    printf("Inserted value: %f at index %d\n", value, index);
}

void vector_erase(struct Vector* vec, const int index)
{
    if (index >= vec->size)
    {
        printf("Invalid index\n");
        return;
    }
    float* temp_elems = (float*)malloc(sizeof(float) * (vec->size - 1));

    for (unsigned int i = 0; i < index; i++)
    {
        temp_elems[i] = vec->elements[i];
    }
    for (unsigned int i = index; i < vec->size - 1; i++)
    {
        temp_elems[i] = vec->elements[i + 1];
    }
    free(vec->elements);

    vec->size--;
    vec->elements = (float*)malloc(sizeof(float) * (vec->capacity));
    for (unsigned int i = 0; i < vec->size; i++)
    {
        vec->elements[i] = temp_elems[i];
    }

    free(temp_elems);

    printf("Erased value at index %d\n", index);
}

void vector_read(struct Vector* vec)
{
    free(vec->elements);

    int count = 0;
    printf("Choose number of input elements:\n");
    do
    {
        scanf_s("%d", &count);
        if (count <= 0)
            printf("Number of input elements must be bigger than 0.\n");
    } while (count <= 0);

    vec->size = count;
    vec->elements = (float*)malloc(sizeof(float) * count);
    vec->capacity = count;
    printf("Choose elements: ");
    for (unsigned int i = 0; i < count; i++)
    {
        scanf_s("%f", &(vec->elements[i]));
    }
}

void vector_print(const struct Vector vec)
{
    for (unsigned int i = 0; i < vec.size; i++)
    {
        printf("%f ", vec.elements[i]);
    }
    printf("\n");
    printf("size: %d\ncapacity: %d\n", vec.size, vec.capacity);
}

void vector_clear(struct Vector* vec)
{
    vec->size = 0;
    vec->capacity = 1;
    free(vec->elements);
}