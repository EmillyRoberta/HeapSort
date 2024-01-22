#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "structs.h"
void MIN_HEAPIFY(int *A,int i, int tamanho_do_heap);
void BUILD_MIN_HEAP(int *A, int tamanho_do_heap);
void MIN_HEAPSORT(int *A, TypeOfProperty *option);
int HEAP_MINIMUN(int *A);
int HEAP_EXTRAX_MIN(int *A, TypeOfProperty *option);
int pai(int i);
void HEAP_INCREASE_KEY(int *A, int i, int newNum);
void MIN_HEAP_INSERT(int *A, int chave, TypeOfProperty *option);
#endif
