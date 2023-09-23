// Código a ser implementado

#include <stdio.h>
#include <stdlib.h>
 
// Define uma constante
// Define a constant
#define MAX 10
 
// Protótipo da função de ordenação
// Ordination function prototype
void insertion_sort(int *a);
 
// Função main
// Main Function
int main(int argc, char** argv)
{
 int i, vet[MAX];
 
 // Lê MAX ou 10 valores
 // Read MAX or 10 values
 for(i = 0; i < MAX; i++)
 {
  printf("Digite um valor: ");
  scanf("%d", &vet[i]);
 }
 
 // Ordena os valores
 // Order values
 insertion_sort(vet);
 
 // Imprime os valores ordenados
 // Print values in order ascendant
 printf("nnValores ordenadosn");
 for(i = 0; i < MAX; i++)
 {
  printf("%dn", vet[i]);
 }
 system("pause");
 return 0;
}
 
// Função de Ordenação por Inserção
// Insertion sort function
void insertion_sort(int *a)
{
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