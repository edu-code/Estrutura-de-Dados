#include <stdio.h>

// Armazena o tamanho do heap
int end;

// Função para trocar dois elementos
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Retorna o filho esquerdo de `A[i]`
int LEFT(int i) {
    return (2 * i + 1);
}

// Retorna o filho direito de `A[i]`
int RIGHT(int i) {
    return (2 * i + 2);
}

// Algoritmo de heapify-down recursivo
// O nó no índice `i` e seus dois filhos diretos
// violam a propriedade do heap
void heapify(int A[], int i) {
    // Obtém o filho esquerdo e direito do nó no índice `i`
    int left = LEFT(i);
    int right = RIGHT(i);

    // Compara `A[i]` com seu filho esquerdo e direito
    // e encontra o maior valor
    int largest = i;

    if (left < end && A[left] > A[largest]) {
        largest = left;
    }

    if (right < end && A[right] > A[largest]) {
        largest = right;
    }

    // Troca com um filho de maior valor e
    // chama heapify no filho
    if (largest != i) {
        swap(&A[i], &A[largest]);
        heapify(A, largest);
    }
}

// Reorganiza os elementos do array para construir o max-heap
void buildHeap(int A[]) {
    // Chama o heapify a partir do último nó interno de todos os
    // caminhos até o nó raiz
    for (int i = (end - 2) / 2; i >= 0; i--) {
        heapify(A, i);
    }
}

void heapsort(int A[], int n) {
    // Inicializa o tamanho do heap como o número total de elementos no array
    end = n;

    // Reorganiza os elementos do array para construir o max-heap
    buildHeap(A);

    /* O loop a seguir mantém que `A[0, end-1]`
       é uma Heap e cada elemento além do final é maior que
       tudo antes dele (então `A[end: n-1]` está em ordem ordenada) */

    // Faz até restar apenas um elemento no heap
    while (end != 1) {
        // Move o próximo maior elemento para o final do
        // array (move-o na frente dos elementos ordenados)
        swap(&A[0], &A[end - 1]);

        // Diminui o tamanho do heap em 1
        end--;

        // Chama heapify no nó raiz enquanto a troca destrói
        // a propriedade do heap
        heapify(A, 0);
    }
}

// Implementação do algoritmo Heapsort em C
int main(void) {
    int A[] = {6, 4, 7, 1, 9, -2};
    int n = sizeof(A) / sizeof(A[0]);

    // Executa heapsort no array
    heapsort(A, n);

    // Imprime o array ordenado
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}


// Sobre o algoritmo: O HeapSort ordena através de sucessivas seleções do elemento correto a ser posicionado
//  em um segmento ordenado. Ele utiliza um heap binário para manter o próximo elemento a ser selecionado.

// Desempenho do HeapSort: O(n log n). Quanto ao consumo de tempo, ele é proporcional ao número
//  de comparações entre elementos do vetor, e portanto proporcional a O(n log n) no pior caso.
