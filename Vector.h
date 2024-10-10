#pragma once
#include <stdlib.h>
#include <stdbool.h>

struct Vector
{
	float* elements;
	unsigned int size;
	unsigned int capacity;
};

void vector_init(struct Vector* vec);
void vector_push_back(struct Vector* vec, const float elem);
float vector_pop(struct Vector* vec);
void vector_resize(struct Vector* vec);
float vector_get_value(const struct Vector vec, const unsigned int index);
void vector_insert(struct Vector* vec, const float value, const unsigned int index);
void vector_erase(struct Vector* vec, const unsigned int index);

void vector_read(struct Vector* vec);
void vector_print(const struct Vector vec);