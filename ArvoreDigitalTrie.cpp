#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TrieNode {
    struct TrieNode* children[26];
    int isEndOfWord;
} TrieNode;

TrieNode* createNode() {
    TrieNode* newNode = (TrieNode*)malloc(sizeof(TrieNode));
    newNode->isEndOfWord = 0;
    for (int i = 0; i < 26; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

void insert(TrieNode* root, const char* word) {
    TrieNode* current = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (!current->children[index]) {
            current->children[index] = createNode();
        }
        current = current->children[index];
    }
    current->isEndOfWord = 1;
}

int search(TrieNode* root, const char* word) {
    TrieNode* current = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (!current->children[index]) {
            return 0;
        }
        current = current->children[index];
    }
    return current->isEndOfWord;
}

// Função para imprimir palavras em ordem lexicográfica na Trie
void printWords(TrieNode* root, char buffer[], int depth) {
    if (root == NULL) {
        return;
    }

    if (root->isEndOfWord) {
        buffer[depth] = '\0';
        printf("%s\n", buffer);
    }

    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            buffer[depth] = 'a' + i;
            printWords(root->children[i], buffer, depth + 1);
        }
    }
}

// Função para liberar a memória alocada pela Trie
void freeTrie(TrieNode* root) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < 26; i++) {
        freeTrie(root->children[i]);
    }

    free(root);
}

int main() {
    TrieNode* root = createNode();
    char word[100];

    int option;
    while (1) {
        printf("Escolha uma opção:\n");
        printf("1. Inserir palavra\n");
        printf("2. Buscar palavra\n");
        printf("3. Imprimir palavras em ordem\n");
        printf("4. Sair\n");
        scanf("%d", &option);

        if (option == 1) {
            printf("Digite a palavra a ser inserida: ");
            scanf("%s", word);
            insert(root, word);
        } else if (option == 2) {
            printf("Digite a palavra a ser buscada: ");
            scanf("%s", word);
            if (search(root, word)) {
                printf("A palavra '%s' foi encontrada na trie.\n", word);
            } else {
                printf("A palavra '%s' não foi encontrada na trie.\n", word);
            }
        } else if (option == 3) {
            printf("Palavras em ordem:\n");
            char buffer[100];
            printWords(root, buffer, 0);
        } else if (option == 4) {
            // Liberar a memória alocada e sair do programa
            freeTrie(root);
            break;
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}

// Funcões adicionadas:
// printWords: Esta função percorre a Trie e imprime todas as palavras armazenadas em ordem.
// freeTrie: Esta função libera a memória alocada para a Trie recursivamente.