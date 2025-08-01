#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// funçãopara calcular valor absoluto
int abs(int x) {
    return x < 0 ? -x : x;
}

// função que retorna a altura da árvore
int getHeight(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    // recursivamente calcula a altura das subárvores esquerda e direita
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    
    // se alguma subárvore não estiver balanceada
    if (leftHeight == -1 || rightHeight == -1) {
        return -1;
    }
    
    // verifica se a diferença de altura excede 1
    if (abs(leftHeight - rightHeight) > 1) {
        return -1;  // Não balanceada
    }
    
    // retorna a altura do nó atual (máximo das subárvores + 1)
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

bool isBalanced(struct TreeNode* root) {
    // Se getHeight retornar -1, a árvore não está balanceada
    return getHeight(root) != -1;
}

// função auxiliar para criar um novo nó
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Função de teste
int main() {
    // Exemplo 1: [3,9,20,null,null,15,7]
    struct TreeNode* root1 = createNode(3);
    root1->left = createNode(9);
    root1->right = createNode(20);
    root1->right->left = createNode(15);
    root1->right->right = createNode(7);
    
    printf("Exemplo 1: %s\n", isBalanced(root1) ? "true" : "false");
    
    // Exemplo 2: [1,2,2,3,3,null,null,4,4]
    struct TreeNode* root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(2);
    root2->left->left = createNode(3);
    root2->left->right = createNode(3);
    root2->left->left->left = createNode(4);
    root2->left->left->right = createNode(4);
    
    printf("Exemplo 2: %s\n", isBalanced(root2) ? "true" : "false");
    
    // Exemplo 3: [] - balanceada (árvore vazia)
    printf("Exemplo 3: %s\n", isBalanced(NULL) ? "true" : "false");
    
    return 0;
}