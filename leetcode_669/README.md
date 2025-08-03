# Trim a Binary Search Tree

**LeetCode 669 - Medium**

## Problema

Dado o `root` de uma BST e os limites `low` e `high`, "pode" a árvore para que todos os elementos fiquem no intervalo `[low, high]`. A estrutura relativa dos elementos restantes deve ser preservada.

## Exemplos

### Exemplo 1:
```
Input:  root = [1,0,2], low = 1, high = 2
Output: [1,null,2]

    1           1
   / \    →      \
  0   2           2
```

### Exemplo 2:
```
Input:  root = [3,0,4,null,2,null,null,1], low = 1, high = 3
Output: [3,2,null,1]

      3             3
     / \           /
    0   4    →    2
     \           /
      2         1
     /
    1
```

## Complexidade

- **Tempo**: O(n) - visita cada nó no pior caso
- **Espaço**: O(h) - altura da árvore (stack da recursão)

