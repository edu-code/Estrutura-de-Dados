#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

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

Node* findMin(Node* node) {
    Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

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

void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;
    int choice, value, randomCount;

    while (1) {
        printf("\nOpções:\n");
        printf("1. Inserir um valor\n");
        printf("2. Inserir dados aleatórios\n");
        printf("3. Pesquisar um valor\n");
        printf("4. Excluir um valor\n");
        printf("5. Imprimir a árvore em ordem\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Digite a quantidade de dados aleatórios a serem inseridos: ");
                scanf("%d", &randomCount);
                for (int i = 0; i < randomCount; i++) {
                    value = rand() % 100;  // Gera valores aleatórios entre 0 e 99
                    root = insert(root, value);
                }
                break;
            case 3:
                printf("Digite o valor a ser pesquisado: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) {
                    printf("%d encontrado na árvore.\n", value);
                } else {
                    printf("%d não encontrado na árvore.\n", value);
                }
                break;
            case 4:
                printf("Digite o valor a ser excluído: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 5:
                printf("Árvore em ordem: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 6:
                // Liberar a memória alocada e sair do programa
                free(root);
                exit(0);
            default:
                printf("Opção inválida.\n");
        }
    }

    return 0;
}
// O algoritmo agora tem a função de utilizar dados aleatórios para criar a árvore.