#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
#include "share.h"
#include "algorithms.h"
#include "structs.h"
#include <time.h>
#include <sys/types.h>
#ifdef _WIN32
#endif
#define PATH_SEPARATOR "\\"

void menuFileSize(TypeOfPropertyMenu *optionMenu)
{
    do
    {
        printf("                                                 \n");
        printf("\t****Escolha a quantidade de algoritmos:********\n");
        printf("\t|                                              |\n");
        printf("\t|           1. 10                              |\n");
        printf("\t|           2. 100                             |\n");
        printf("\t|           3. 1000                            |\n");
        printf("\t|           4. 10000                           |\n");
        printf("\t|           5. 100000                          |\n");
        printf("\t|           6. 1000000                         |\n");
        printf("\t|                                              |\n");
        printf("\t|______________________________________________|\n\n");

        printf("\tDigite a opcao: ");
        scanf("%d", &optionMenu->inputSize);

        if(optionMenu->inputSize<1 || optionMenu->inputSize>6)
        {
            printf("Digite uma opção válida!\n");
            Sleep(1000);
        }
        system("cls");
    }
    while(optionMenu->inputSize<1 || optionMenu->inputSize>6);
}

void menuNumbersChoice(TypeOfPropertyMenu *optionMenu)
{
    do
    {
        printf("                                                 \n");
        printf("\t***Escolha a forma em que serão geradas:*******\n");
        printf("\t|                                              |\n");
        printf("\t|           1. Números Randômicos              |\n");
        printf("\t|           2. Números Crescentes              |\n");
        printf("\t|           3. Números Decrescentes            |\n");
        printf("\t|                                              |\n");
        printf("\t|______________________________________________|\n\n");

        printf("\tDigite a opcao: ");
        scanf(" %d", &optionMenu->inputType);

        if(optionMenu->inputType>0 && optionMenu->inputType<4)
        {
            system("cls");
            menuFileSize(optionMenu);
        }
        else
        {
            printf("entrou aqui3\n");
            printf("Digite uma opção válida!\n");
            Sleep(1000);
            system("cls");
        }
    }
    while(optionMenu->inputType<1 || optionMenu->inputType>3);
}

void menuAlgorithmChoice(TypeOfPropertyMenu *optionMenu)
{
    int opcao;
    do
    {
        printf("                                                 \n");
        printf("\t***Escolha o Algoritmo de Ordenação Desejado***\n");
        printf("\t|                                              |\n");
        printf("\t|           1. Heap Sort Minimo                |\n");
        printf("\t|           2. Heap Minimum                    |\n");
        printf("\t|           3. Heap Extract Min                |\n");
        printf("\t|           4. Heap Increase Key               |\n");
        printf("\t|           5. Insert Heap                     |\n");
        printf("\t|                                              |\n");
        printf("\t|______________________________________________|\n\n");

        printf("\tDigite a opcao: ");
        scanf("%d", &opcao);

        if(opcao>0 && opcao<7)
        {
            optionMenu->algorithm = opcao;
            system("cls");
            menuNumbersChoice(optionMenu);
            return;
        }
        system("cls");
    }
    while(opcao<1 || opcao>6);

}



void dataOutput(TypeOfProperty *option)
{
    printf("                                                 \n");
    printf("\t***************Dados Apurados******************\n");
    printf("\t                                              \n");
    printf("\t Algoritmo Usado: %s                          \n", option->algorithm);
    printf("\t Tipo de Entrada: %s                          \n", option->inputType);
    printf("\t Tamanho: %d                                  \n", option->inputSize);
    printf("\t Tempo: %f segundos                           \n", option->timeTaken);
    printf("\t                                              \n");
    printf("\t______________________________________________\n\n");
}
int main()
{
    setlocale(LC_ALL, "Portuguese");
    TypeOfPropertyMenu optionMenu;
    TypeOfProperty option;
    clock_t start_t, end_t;
    menuAlgorithmChoice(&optionMenu);
    filterNumber(&option, &optionMenu);
    createFiles(&option);
    createFileNumbers(&option);
    int *numbersVector = readFileNumbers(&option);
    int originalVector[option.inputSize+1];
    for (int i = 0; i < option.inputSize; i++) {originalVector[i] = numbersVector[i];}
    start_t = clock();
    MIN_HEAPSORT(numbersVector, &option);
    end_t = clock();
    resultOrdenation(numbersVector, &option);
    int i, numExtract, posix;

    switch(optionMenu.algorithm)
    {
    case 1:
        option.timeTaken = ((end_t - start_t) / (double)CLOCKS_PER_SEC);
        resultTime(&option);
        dataOutput(&option);
        break;
    case 2:
        printf("Vetor Original:");
        for(i=0;i<option.inputSize;i++){
            printf(" %d ", originalVector[i]);
        }
        int minimumNumber = HEAP_MINIMUN(numbersVector);
        printf("\n\n");
        printf("Elemento minimo: %d\n\n", minimumNumber);
        printf("Saída: ");
        for(i=0;i<option.inputSize;i++){
            printf(" %d ", numbersVector[i]);
        }
        printf("\n\n");
        break;
    case 3:
        numExtract = HEAP_EXTRAX_MIN(numbersVector, &option);
        printf("Vetor Original:");
        for(i=0;i<option.inputSize;i++){
            printf(" %d ", originalVector[i]);
        }
        printf("\n\n");
        printf("Elemento removido: %d\n\n", numExtract);
        printf("Saída: ");
        for(i=1;i<option.inputSize;i++){
            printf(" %d ", numbersVector[i]);
        }
        printf("\n\n");
        break;
    case 4:
        printf("Vetor Original:");
        for(i=0;i<option.inputSize;i++){
            printf(" %d ", originalVector[i]);
        }
        printf("\n\n");
        printf("Saída: ");
        for(i=0;i<option.inputSize;i++){
            printf(" %d ", numbersVector[i]);
        }
        printf("\n\n");
        printf("\nInsira a posição que deseja colocar:\n");
        scanf("%d", &posix);
        HEAP_INCREASE_KEY(numbersVector,posix,1000);
        printf("\n\n\nAlteração feita!!\n\n\n");
        printf("Vetor Alterado: ");
        for(i=0;i<option.inputSize;i++){
            printf(" %d ", numbersVector[i]);
        }
        resultOrdenation(numbersVector, &option);
        break;
    case 5:
        printf("Vetor Original:");
        for(i=0;i<option.inputSize;i++){
            printf(" %d ", originalVector[i]);
        }
        printf("\n\n");
        printf("Saída: ");
        for(i=0;i<option.inputSize;i++){
            printf(" %d ", numbersVector[i]);
        }
        printf("\n\n");
        MIN_HEAP_INSERT(numbersVector,1000, &option);
        printf("\n\n\nAlteração feita!!\n\n\n");
        printf("Vetor Alterado: ");
        for(i=0;i<option.inputSize;i++){
            printf(" %d ", numbersVector[i]);
        }
        resultOrdenation(numbersVector, &option);
        break;
    default:
        printf("Digite uma opcao valida\n");
        system("cls");
        break;
    }
    return 0;
}
