#pragma once
#include <stdlib.h>

struct Vector
{
	float* elements;
	unsigned int size;
	unsigned int capacity;
};

void vector_init(struct Vector* vec);
void push_back(struct Vector* vec, const float elem);
float pop(struct Vector* vec);
void resize(struct Vector* vec);
float get_value(const struct Vector vec, const unsigned int index);

void read(struct Vector* vec);
void print(const struct Vector vec);