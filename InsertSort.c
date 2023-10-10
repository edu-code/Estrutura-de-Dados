#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void insertion_sort(int *a);

int main(int argc, char** argv){
    int i, vet[MAX];
    for(i = 0; i < MAX; i++)
    {
        printf("Digite um valor: ");
        scanf("%d", &vet[i]);
    }

    insertion_sort(vet);
    printf("nnValores ordenadosn");
    for(i = 0; i < MAX; i++)
    {
        printf("%dn", vet[i]);
    }

    system("pause");
    return 0;
}

void insertion_sort(int *a){
    int i, j, tmp;
    for(i = 1; i < MAX; i++)
    {
        tmp = a[i];
        for(j = i-1; j >= 0 && tmp < a[j]; j--)
        {
            a[j+1] = a[j];
        }
    a[j+1] = tmp;
    }
}
   // Funcionamento: A ordenação por inserção é baseada na ideia de que um elemento dos elementos de entrada é consumido em cada iteração para encontrar sua posição correta, ou seja, a posição à qual pertence em uma matriz ordenada.
   // - Esse algoritmo é bastante simples e possui uma fácil implementação. Ele é eficiente para uma quantidade pequena de dados.
   // - Para N elementos, há N² comparações. O tempo de complexidade é O(N²).
