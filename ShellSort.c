#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define MAX 10000

void shell_sort(int *a, int size);
void gerar_numeros(int *a, int size);

int main(int argc, char** argv)
{
    int i, vet[MAX];

    srand(time(NULL));

    gerar_numeros(vet, MAX);

    printf("Valores não ordenados:\n");
    for(i = 0; i < MAX; i++)
    {
        printf("%d\n", vet[i]);
    }

    shell_sort(vet, MAX);

    printf("\nValores ordenados:\n");
    for(i = 0; i < MAX; i++)
    {
        printf("%d\n", vet[i]);
    }

    return 0;
}
void shell_sort(int *a, int size)
{
    int i, j, value;
    int gap = 1;

    do {
        gap = 3 * gap + 1;
    } while(gap < size);

    do {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value = a[i];
            j = i - gap;

            while (j >= 0 && value < a[j]) {
                a[j + gap] = a[j];
                j -= gap;
            }
            a[j + gap] = value;
        }
    } while(gap > 1);
}

void gerar_numeros(int *a, int size) {
    for (int i =0; i< size; i++){
        a[i] = rand() % 10000 + 1;
    }
}

// O algoritmo é derivado do algoritmo de inserção. Ele faz trocas a uma certa distância (que diminui a cada passada) e compara elementos 
// separados por "h" posições e as ordena. Progressivamente, o h vai diminuido até chegar a 1.
// É uma boa opção para arquivos moderados e sua implementação é simples.
// No melhor caso, o algoritmo realiza O(N log^2 N) comparações e no pior caso O(N^2).
