#pragma once
#include <stdlib.h>

struct Vector
{
	float* elements;
	unsigned int size;
	unsigned int capacity;
};

struct Vector vectorInit();
void push_back(struct Vector* vec, float elem);
void resize(struct Vector* vec);