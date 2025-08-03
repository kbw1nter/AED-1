#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// estados possíveis para cada nó:
#define NOT_COVERED 0   
#define HAS_CAMERA 1     
#define COVERED 2       
int cameras = 0; 

int dfs(struct TreeNode* node) {
    // caso base: nó NULL
    if (node == NULL) return COVERED;
    
    // processa os filhos
    int left = dfs(node->left);
    int right = dfs(node->right);
    
    // se algum filho não está coberto, este nó DEVE ter câmera
    if (left == NOT_COVERED || right == NOT_COVERED) {
        cameras++;
        return HAS_CAMERA;
    }
    
    // se algum filho tem câmera, este nó está coberto
    if (left == HAS_CAMERA || right == HAS_CAMERA) {
        return COVERED;
    }

    // se ambos filhos estão cobertos (mas sem câmera), este nó não está coberto (precisa que o pai tenha câmera)
    return NOT_COVERED;
}

int minCameraCover(struct TreeNode* root) {
    cameras = 0;
    
    // se a raiz não está coberta após DFS, precisa de câmera
    if (dfs(root) == NOT_COVERED) {
        cameras++;
    }
    
    return cameras;
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

// imprime estrutura visual da árvore
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

const char* getStateName(int state) {
    switch(state) {
        case NOT_COVERED: return "NOT_COVERED";
        case HAS_CAMERA: return "HAS_CAMERA";
        case COVERED: return "COVERED";
        default: return "UNKNOWN";
    }
}

// Teste 1: [0,0,null,0,0]
struct TreeNode* createTest1() {
    struct TreeNode* root = createNode(0);
    root->left = createNode(0);
    root->left->left = createNode(0);
    root->left->right = createNode(0);
    return root;
}

// Teste 2: [0,0,null,0,null,0,null,null,0]
struct TreeNode* createTest2() {
    struct TreeNode* root = createNode(0);
    root->left = createNode(0);
    root->left->left = createNode(0);
    root->left->left->right = createNode(0);
    root->left->left->right->right = createNode(0);
    return root;
}

int main() {
    printf("📹 BINARY TREE CAMERAS - TESTES\n");
    printf("===============================\n\n");
    
    // TESTE 1
    printf(" TESTE 1:\n");
    printf("Input:  root = [0,0,null,0,0]\n");
    printf("Output: 1\n\n");
    
    struct TreeNode* test1 = createTest1();
    
    printf(" Árvore:\n");
    printTree(test1, 0);
    printf("\n In-order: ");
    printInOrder(test1);
    printf("\n\n");
    
    int result1 = minCameraCover(test1);
    printf(" Número mínimo de câmeras: %d\n", result1);
    printf("   Esperado: 1\n");
    printf("    Uma câmera no nó intermediário cobre todos\n\n");
    
    freeTree(test1);
    printf("----------------------------------------\n\n");
    
    // TESTE 2
    printf("📋 TESTE 2:\n");
    printf("Input:  root = [0,0,null,0,null,0,null,null,0]\n");
    printf("Output: 2\n\n");
    
    struct TreeNode* test2 = createTest2();
    
    printf(" Árvore:\n");
    printTree(test2, 0);
    printf("\n In-order: ");
    printInOrder(test2);
    printf("\n\n");
    
    int result2 = minCameraCover(test2);
    printf("📹 Número mínimo de câmeras: %d\n", result2);
    printf("   Esperado: 2\n");
    printf("   💡 Árvore mais esparsa precisa de mais câmeras\n\n");
    
    freeTree(test2);
    printf("----------------------------------------\n\n");
    
    // TESTE 3 - Casos simples
    printf("📋 TESTES ADICIONAIS:\n\n");
    
    // Árvore com 1 nó
    struct TreeNode* test3 = createNode(0);
    printf(" Árvore: [0] → Câmeras: %d (esperado: 1)\n", minCameraCover(test3));
    freeTree(test3);
    
    // Árvore: [0,0,0]
    struct TreeNode* test4 = createNode(0);
    test4->left = createNode(0);
    test4->right = createNode(0);
    printf(" Árvore: [0,0,0] → Câmeras: %d (esperado: 1)\n", minCameraCover(test4));
    freeTree(test4);
    
    // Árvore linear: [0,0,null,0]
    struct TreeNode* test5 = createNode(0);
    test5->left = createNode(0);
    test5->left->left = createNode(0);
    printf(" Árvore: [0,0,null,0] → Câmeras: %d (esperado: 2)\n", minCameraCover(test5));
    freeTree(test5);
    
    printf("\n Todos os testes executados!\n");

    return 0;
}
