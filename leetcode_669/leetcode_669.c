#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* trimBST(struct TreeNode* root, int low, int high) {
    // caso base: nó vazio
    if (root == NULL) return NULL;
    
    if (root->val < low) {
        return trimBST(root->right, low, high);
    }
    
    if (root->val > high) {
        return trimBST(root->left, low, high);
    }
    
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    
    return root;
}

// Cria um novo nó
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Imprime a árvore em in-order (esquerda → raiz → direita)
void printInOrder(struct TreeNode* root) {
    if (root == NULL) return;
    printInOrder(root->left);
    printf("%d ", root->val);
    printInOrder(root->right);
}

// Imprime a estrutura da árvore
void printTree(struct TreeNode* root, int space) {
    const int COUNT = 10;
    if (root == NULL) return;
    
    space += COUNT;
    printTree(root->right, space);
    
    printf("\n");
    for (int i = COUNT; i < space; i++) printf(" ");
    printf("%d\n", root->val);
    
    printTree(root->left, space);
}

// libera memória da árvore
void freeTree(struct TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Teste 1: [1,0,2], low=1, high=2
struct TreeNode* createTest1() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(0);
    root->right = createNode(2);
    return root;
}

// Teste 2: [3,0,4,null,2,null,null,1], low=1, high=3
struct TreeNode* createTest2() {
    struct TreeNode* root = createNode(3);
    root->left = createNode(0);
    root->right = createNode(4);
    
    root->left->right = createNode(2);
    root->left->right->left = createNode(1);
    
    return root;
}

int main() {
    printf(" TRIM BINARY SEARCH TREE - TESTES\n");
    printf("===================================\n\n");
    
    // TESTE 1
    printf(" TESTE 1:\n");
    printf("Input:  root = [1,0,2], low = 1, high = 2\n");
    printf("Output: [1,null,2]\n\n");
    
    struct TreeNode* test1 = createTest1();
    
    printf(" Árvore original:\n");
    printTree(test1, 0);
    printf("\n In-order original: ");
    printInOrder(test1);
    printf("\n\n");
    
    // Trim da árvore
    struct TreeNode* result1 = trimBST(test1, 1, 2);
    
    printf(" Árvore após trim [1,2]:\n");
    printTree(result1, 0);
    printf("\n In-order resultado: ");
    printInOrder(result1);
    printf("\n   Esperado: 1 2\n\n");
    
    freeTree(result1);
    printf("----------------------------------------\n\n");
    
    // TESTE 2
    printf("📋 TESTE 2:\n");
    printf("Input:  root = [3,0,4,null,2,null,null,1], low = 1, high = 3\n");
    printf("Output: [3,2,null,1]\n\n");
    
    struct TreeNode* test2 = createTest2();
    
    printf(" Árvore original:\n");
    printTree(test2, 0);
    printf("\n In-order original: ");
    printInOrder(test2);
    printf("\n\n");
    
    // Trim da árvore
    struct TreeNode* result2 = trimBST(test2, 1, 3);
    
    printf(" Árvore após trim [1,3]:\n");
    printTree(result2, 0);
    printf("\n In-order resultado: ");
    printInOrder(result2);
    printf("\n   Esperado: 1 2 3\n\n");
    
    freeTree(result2);
    printf("----------------------------------------\n\n");
    
    // TESTE 3 - Caso adicional
    printf("TESTE 3 (Adicional):\n");
    printf("Input:  root = [5,2,8,1,4,6,9], low = 3, high = 7\n");
    printf("Output: [5,4,6]\n\n");
    
    struct TreeNode* test3 = createNode(5);
    test3->left = createNode(2);
    test3->right = createNode(8);
    test3->left->left = createNode(1);
    test3->left->right = createNode(4);
    test3->right->left = createNode(6);
    test3->right->right = createNode(9);
    
    printf("Árvore original:\n");
    printTree(test3, 0);
    printf("\n In-order original: ");
    printInOrder(test3);
    printf("\n\n");
    
    // Trim da árvore
    struct TreeNode* result3 = trimBST(test3, 3, 7);
    
    printf("Árvore após trim [3,7]:\n");
    printTree(result3, 0);
    printf("\n In-order resultado: ");
    printInOrder(result3);
    printf("\n   Esperado: 4 5 6\n");
    printf("   Explicação: Remove 1,2 (<3) e 8,9 (>7)\n\n");
    
    freeTree(result3);
    
    printf("Todos os testes executados!\n");
    printf("Compare os resultados in-order com os esperados\n");
    
    return 0;
}
/*
COMPLEXIDADE:
- Tempo: O(n) - visita cada nó no pior caso
- Espaço: O(h) - altura da árvore (stack da recursão)
*/ 