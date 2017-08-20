#ifndef COUNT_SUB_STR_H
#define COUNT_SUB_STR_H

#include <stdio.h>

typedef struct vector vector;
void addVectors(int dim, vector* w , vector v);
vector multiplyVecScal(int dim, int scalar, vector v);
int getNumber(char*token);
void getVector(FILE* input , int dim , vector* v , int x);
int braket(int dim, vector* v, vector* w);
void algo(int dim, vector* wVector ,vector* v);
int getNumber(char *token);

#endif