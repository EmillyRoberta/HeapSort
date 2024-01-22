#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structs.h"

void MIN_HEAPIFY(int *A,int i, TypeOfProperty *option){
    int left,right,menor, aux;
    left = 2*i;
    right = (2*i)+1;
    if ((left <= option->inputSize) && (left <= option->comprimento) && (A[left] > A[i])){
        menor = left;
    }
    else{
        menor = i;
    }
    if ((right <= option->inputSize) && (right <= option->comprimento) && (A[right] > A[menor])){
        menor = right;
    }
    if (menor != i)
    {
        aux=A[i];
        A[i]=A[menor];
        A[menor]=aux;
        MIN_HEAPIFY(A,menor,option);
    }
    return;
}

void BUILD_MIN_HEAP(int *A, TypeOfProperty *option){
    int i;
    for (i = floor((option->inputSize-1)/2); i >= 0; i--){
        MIN_HEAPIFY(A,i, option);
    }
}

void MIN_HEAPSORT(int *A, TypeOfProperty *option){
    int i, aux; option->comprimento=option->inputSize-1;
    BUILD_MIN_HEAP(A, option);
    for (i = option->inputSize-1; i > 0; i--)
    {
        aux=A[i];
        A[i]=A[0];
        A[0]=aux;
        option->comprimento--;
        MIN_HEAPIFY(A,0, option);
    }
}

int HEAP_EXTRAX_MIN(int *A, TypeOfProperty *option){
    int min;
    min = A[0];
    A[0] = A[option->comprimento-1];
    option->comprimento--;
    MIN_HEAPIFY(A,1,option);
    return min;
}

int HEAP_MINIMUN(int *A){
   return A[0];
}

int pai(int i){
    int parent = floor(i/2);
    return parent;
}

void HEAP_INCREASE_KEY(int *A, int i, int newNum){
    int aux;
    if(newNum < A[i]){
        printf("\nNova chave e menor que a chave atual\n");
        exit(0);
    }
    A[i] = newNum;
    while(i>0 && A[pai(i)] > A[i]){
        aux=A[i];
        A[i]=A[pai(i)];
        A[pai(i)]=aux;
        i = pai(i);
        printf("passou aqui");
    }
}

void MIN_HEAP_INSERT(int *A, int newNumber, TypeOfProperty *option){
    A[option->inputSize] = newNumber;
    option->inputSize++;
    BUILD_MIN_HEAP(A, option);
    int i = option->inputSize - 1;
    while(i > 0 && A[(i - 1) / 2] > A[i]) {
        int temp = A[i];
        A[i] = A[(i - 1) / 2];
        A[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}
