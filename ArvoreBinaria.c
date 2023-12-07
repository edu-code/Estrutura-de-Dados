#include <stdio.h>
#include <stdlib.h>

// Estrutura para um nó da árvore
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Função para inserir um elemento na árvore
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Função para pesquisar um elemento na árvore
Node* search(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Função para encontrar o nó com valor mínimo na árvore
Node* findMin(Node* node) {
    Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Função para excluir um elemento da árvore
Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Função para imprimir a árvore em ordem
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;

    // Inserir elementos na árvore
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Imprimir a árvore em ordem
    printf("Árvore em ordem: ");
    inOrderTraversal(root);
    printf("\n");

    // Pesquisar um elemento na árvore
    int key = 40;
    Node* result = search(root, key);
    if (result != NULL) {
        printf("%d encontrado na árvore.\n", key);
    } else {
        printf("%d não encontrado na árvore.\n", key);
    }

    // Excluir um elemento da árvore
    int toDelete = 30;
    root = deleteNode(root, toDelete);
    printf("Árvore após excluir %d: ", toDelete);
    inOrderTraversal(root);
    printf("\n");

    return 0;
}

// O programa cria uma árvore binária de busca e realiza operações de inserção, pesquisa e exclusão de elementos.
//  Ele imprime a árvore em ordem antes e depois da exclusão, mostrando como as operações afetam a estrutura da árvore.

// O código conta com a seguinte estrutura:
// 1. Estrutura do nó. 
// 2. Uma função para criar um novo nó.
// 3. Função para Inserir um Elemento na Árvore:
// 4. Função para Pesquisar um Elemento na Árvore:
// 5. Função para Encontrar o Nó com Valor Mínimo na Árvore:
// 6. Função para Excluir um Elemento da Árvore:
// 7. Função para Imprimir a Árvore em Ordem (In-Order Traversal):
// 8. Função principal

// Utilização:
// Administração de grandes quantidades de dados em uma ordem qualquer.
// Administração de Informações Hierárquicas
// Posso representar que conjuntos de dados dependem de que outros de uma forma natural.
// Representação de Processos Decisórios.
