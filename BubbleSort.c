#include<stdio.h>
#include<stdlib.h>

//Programa C de Bubble Sort em ordem crescente e decrescente.

main(){
   int data[100],i,n,step,temp;
   printf("Digite o número de elementos que deseja ordenar: ");
   scanf("%d",&n);
   for(i=0;i<n;++i){
       printf("%d. Insira o elemento aqui:",i+1);
       scanf("%d",&data[i]);
   }
   //ordem crescente
   for(step=0;step<n-1;++step)
   for(i=0;i<n-step-1;++i){
       if(data[i]>data[i+1])
       {
           temp=data[i];
           data[i]=data[i+1];
           data[i+1]=temp;
       }
   }

   printf("Em ordem crescente:");
   for(i=0;i<n;++i)
        printf("%d  ",data[i]);

   //Implementação da ordem decrescente

       for(step=0;step<n-1;++step)
   for(i=0;i<n-step-1;++i){
       if(data[i]<data[i+1])
       {
           temp=data[i];
           data[i]=data[i+1];
           data[i+1]=temp;
       }
   }
   printf("Em ordem decrescente:");
   for(i=0;i<n;++i)
        printf("%d  ",data[i]);


   system("pause");
}

//Sobre o algoritmo: O Bubble sort é um dos algoritmos mais simples de serem implementados, por haver somente uma tarefa a ser executada.
//Porem, não é muito eficiente para classificar matrizes e o tempo de execução pode chegar a O(N^2).