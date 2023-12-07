#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 64

struct PatriciaNode {
    int isLeaf;
    int index;
    char key[MAX_KEY_LENGTH];
    struct PatriciaNode* left;
    struct PatriciaNode* right;
};

typedef struct PatriciaNode PatriciaNode;

PatriciaNode* createPatriciaNode(int index, char* key) {
    PatriciaNode* node = (PatriciaNode*)malloc(sizeof(PatriciaNode));
    node->isLeaf = 1;
    node->index = index;
    strcpy(node->key, key);
    node->left = NULL;
    node->right = NULL;
    return node;
}

PatriciaNode* insert(PatriciaNode* root, char* key) {
    if (root == NULL) {
        return createPatriciaNode(strlen(key), key);
    }

    if (root->isLeaf) {
        int i = 0;
        while (key[i] == root->key[i]) {
            i++;
        }

        if (i == root->index) {
            root->left = insert(NULL, key);
            root->isLeaf = 0;
            root->index = i;
            return root;
        } else {
            PatriciaNode* node = createPatriciaNode(i, key);
            if (key[i] == '0') {
                node->left = createPatriciaNode(strlen(key), key);
                node->right = root;
            } else {
                node->left = root;
                node->right = createPatriciaNode(strlen(key), key);
            }
            return node;
        }
    } else {
        if (key[root->index] == '0') {
            root->left = insert(root->left, key);
        } else {
            root->right = insert(root->right, key);
        }
        return root;
    }
}

int search(PatriciaNode* root, char* key) {
    if (root == NULL) {
        return 0;
    }
    if (root->isLeaf) {
        return (strcmp(root->key, key) == 0);
    }
    if (key[root->index] == '0') {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

void printPatriciaTree(PatriciaNode* root, int level) {
    if (root == NULL) return;

    for (int i = 0; i < level; i++) {
        printf("  ");
    }

    if (root->isLeaf) {
        printf("Leaf: %s\n", root->key);
    } else {
        printf("Internal Node (%d)\n", root->index);
    }

    printPatriciaTree(root->left, level + 1);
    printPatriciaTree(root->right, level + 1);
}

int main() {
    PatriciaNode* root = NULL;

    int option;
    char key[MAX_KEY_LENGTH];
    int found;

    while (1) {
        printf("Escolha uma opção:\n");
        printf("1. Inserir chave\n");
        printf("2. Buscar chave\n");
        printf("3. Imprimir Árvore Patricia\n");
        printf("4. Sair\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Digite a chave a ser inserida: ");
                scanf("%s", key);
                root = insert(root, key);
                break;
            case 2:
                printf("Digite a chave a ser buscada: ");
                scanf("%s", key);
                found = search(root, key);
                if (found) {
                    printf("A chave '%s' foi encontrada na árvore Patricia.\n", key);
                } else {
                    printf("A chave '%s' não foi encontrada na árvore Patricia.\n", key);
                }
                break;
            case 3:
                printf("Árvore Patricia:\n");
                printPatriciaTree(root, 0);
                break;
            case 4:
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    }

    return 0;
}

// Observações sobre o código:
// O código está implementado como uma árvore binária onde cada nó tem no máximo dois filhos.
// A árvore Patricia é otimizada para armazenar chaves binárias eficientemente, economizando espaço ao 
// armazenar apenas os bits diferentes entre as chaves. Este algoritmo segue a estrutura básica de uma árvore
//  binária, mas com a otimização adicional para armazenar chaves binárias compartilhadas. Usa a compactação 
// de prefixo para evitar redundância na representação de chaves binárias comuns.