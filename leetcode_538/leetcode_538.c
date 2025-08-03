#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// variável global para manter a soma acumulada
int sum = 0;

void reverseInOrder(struct TreeNode* root) {
    if (root == NULL) return;
    
    // 1. Visita subárvore direita primeiro
    reverseInOrder(root->right);
    
    // 2. Processa o nó atual
    sum += root->val;        
    root->val = sum;      
    
    // 3. Visita subárvore esquerda
    reverseInOrder(root->left);
}

struct TreeNode* convertBST(struct TreeNode* root) {
    sum = 0;  // Reset da variável global
    reverseInOrder(root);
    return root;
}


// cria um novo nó
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// imprime a árvore em in-order
void printInOrder(struct TreeNode* root) {
    if (root == NULL) return;
    printInOrder(root->left);
    printf("%d ", root->val);
    printInOrder(root->right);
}

// imprime a árvore em formato de array
void printArray(struct TreeNode* root, int* arr, int index) {
    if (root == NULL) return;
    arr[index] = root->val;
    if (root->left) printArray(root->left, arr, 2 * index + 1);
    if (root->right) printArray(root->right, arr, 2 * index + 2);
}

// libera memória da árvore
void freeTree(struct TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}


// Teste 1: [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
struct TreeNode* createTest1() {
    struct TreeNode* root = createNode(4);
    root->left = createNode(1);
    root->right = createNode(6);
    
    root->left->left = createNode(0);
    root->left->right = createNode(2);
    root->right->left = createNode(5);
    root->right->right = createNode(7);
    
    root->left->right->right = createNode(3);
    root->right->right->right = createNode(8);
    
    return root;
}

// Teste 2: [0,null,1]
struct TreeNode* createTest2() {
    struct TreeNode* root = createNode(0);
    root->right = createNode(1);
    return root;
}


int main() {
    printf("CONVERT BST TO GREATER TREE - TESTES\n");
    printf("=====================================\n\n");
    
    // TESTE 1
    printf("TESTE 1:\n");
    printf("Input:  [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]\n");
    printf("Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]\n\n");
    
    struct TreeNode* test1 = createTest1();
    
    printf("Árvore original (in-order): ");
    printInOrder(test1);
    printf("\n");
    
    convertBST(test1);
    
    printf("Árvore convertida (in-order): ");
    printInOrder(test1);
    printf("\n");
    printf("   Esperado: 36 30 33 35 21 26 15 8\n\n");
    
    freeTree(test1);
    
    // TESTE 2
    printf("TESTE 2:\n");
    printf("Input:  [0,null,1]\n");
    printf("Output: [1,null,1]\n\n");
    
    struct TreeNode* test2 = createTest2();
    
    printf("Árvore original (in-order): ");
    printInOrder(test2);
    printf("\n");
    
    convertBST(test2);
    
    printf("Árvore convertida (in-order): ");
    printInOrder(test2);
    printf("\n");
    printf("   Esperado: 1 1\n\n");
    
    freeTree(test2);
    
    // TESTE 3 - Caso simples adicional
    printf("TESTE 3 (Adicional):\n");
    printf("Input:  [2,1,3]\n");
    printf("Output: [5,6,3]\n\n");
    
    struct TreeNode* test3 = createNode(2);
    test3->left = createNode(1);
    test3->right = createNode(3);
    
    printf("Árvore original (in-order): ");
    printInOrder(test3);
    printf("\n");
    
    convertBST(test3);
    
    printf("Árvore convertida (in-order): ");
    printInOrder(test3);
    printf("\n");
    printf("   Esperado: 6 5 3\n");
    printf("   Explicação: 1→(1+2+3)=6, 2→(2+3)=5, 3→(3)=3\n\n");
    
    freeTree(test3);
    
    printf("Todos os testes executados!\n");
    printf("Dica: Compare os resultados 'in-order' com os esperados\n");
    
    return 0;
}