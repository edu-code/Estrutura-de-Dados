#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 50
void fSelect_Sort(int *pVetor);

int main()
{
   int vVetor[TAM];
   int vAux;
   srand ( time(NULL) );
   for (vAux=0; vAux < TAM; vAux++)
   {
       vVetor[vAux] = (rand() % 89) + 10;
       printf(" %d,",vVetor[vAux]);
   }

   fSelect_Sort(vVetor);
   printf("\n\n");

   for (vAux=0; vAux < TAM; vAux++)
   {
       printf(" %d,",vVetor[vAux]);
   }

   printf("\n\n ");
   system("pause");
   return 0;
}

void fSelect_Sort(int *pVetor)
{
   int vMenor;
   int vAux;
   int vTemp;
   int vTroca;


   for(vAux=0; vAux < TAM-1; vAux++)
   {
       vMenor = vAux;


       for (vTemp=vAux+1; vTemp < TAM; vTemp++)
       {
           if (pVetor[vTemp] < pVetor[vMenor])
           {
               vMenor = vTemp;
           }
       }

       if (vMenor != vAux)
       {
           vTroca         = pVetor[vAux];
           pVetor[vAux]   = pVetor[vMenor];
           pVetor[vMenor] = vTroca;
       }
   }
}

// Funcionamento: O selection sort baseia se em ordenar a partir do menor elemento, que é colocado para a primeira posição do array.
// Esse movimento é executado várias vezes até que o array esteja completamente ordenado.
// Selection Sort versus Insertion Sort: O Selection efetua menos trocas do que o Insertion, pois há uma troca apenas por iteração.
// Já o insertion sort efetua ao menos uma troca por iteração, pois deve efetuar trocas para afastar cada elemento avaliado. Por outro lado, 
// o Insertion Sort efetua menos comparações do que o Selection Sort, pois nem sempre o elemento a ser inserido de forma ordenada deve ir até o 
// final. Ambos estão na mesma classe de complexidade.
// O Selection Sort não é considerado um algoritmo eficiente para grandes entradas.


