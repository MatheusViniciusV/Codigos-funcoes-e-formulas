#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//================================================================
// Nome Do Arquivo: sort.c
// Descrição: Algoritmo de ordenação de N elementos
//
// Matheus Vinicius, Informática, CEFET-MG
//================================================================

void quick_sort(int *a, int left, int right) {

    // Função de Ordenação por Seleção: Quick Sort

    int i, j, x, y;
     
    i = left;
    j = right;
    x = a[(left + right) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}

int main() {

    //Declaração de variáveis
    int i, num_componentes, *v;

    //Leitura do limite de elementos
    printf("*********** ALGORITMO DE ORDENACAO: QUICK SORT ***********\n\n");
    printf("Informe o numero de elementos a serem ordenados: ");
    scanf("%d", &num_componentes);
    system("cls");

    //Alocando dinamicamente o espaço necessário
    v = (int *) malloc(num_componentes * sizeof(int));
    
    //Armazenando os dados em um vetor
    for (i = 0; i < num_componentes; i++) {
        printf("Digite %d o valor: ", i + 1);
        scanf("%d", &v[i]);
        system("cls");
    }

    //Invocando a função de ordenação
    quick_sort(v, 0, num_componentes - 1);
    
    //Percorrendo o vetor e imprimindo os valores
    printf("*********** Valores ordenados ***********\n\n");
    
    for (i = 0; i < num_componentes; i++) {
        printf("%d ", v[i]);
    }
    
    //Liberando o espaço de memória alocado e finalizando programa
    free(v);
    printf("\n\n");
    system("pause");

    return 0;
}
