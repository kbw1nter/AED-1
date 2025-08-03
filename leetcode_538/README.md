# Convert BST to Greater Tree

**LeetCode 538 - Medium**

## Problema

Dado o `root` de uma Binary Search Tree (BST), converta-a em uma Greater Tree onde cada chave da BST original é alterada para: `chave_original + soma_de_todas_chaves_maiores`.

## Exemplos

### Exemplo 1:
```
Input:  [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
```

### Exemplo 2:
```
Input:  [0,null,1]
Output: [1,null,1]
```

## 💡 Solução - Reverse In-Order Traversal

### Ideia Principal
- **BST In-Order**: esquerda → raiz → direita = ordem crescente
- **BST Reverse In-Order**: direita → raiz → esquerda = ordem decrescente
- Mantemos uma soma acumulada que cresce conforme visitamos os nós

### Algoritmo
1. Visita subárvore direita (valores maiores)
2. Processa nó atual: soma += valor, nó = soma
3. Visita subárvore esquerda (valores menores)

### Exemplo Passo a Passo
```
BST: [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]

Ordem de visita: 8 → 7 → 6 → 5 → 4 → 3 → 2 → 1 → 0

sum = 0
8: sum = 8,  nó = 8    (8 = 8 + 0)
7: sum = 15, nó = 15   (15 = 7 + 8) 
6: sum = 21, nó = 21   (21 = 6 + 8+7)
5: sum = 26, nó = 26   (26 = 5 + 8+7+6)
4: sum = 30, nó = 30   (30 = 4 + 8+7+6+5)
3: sum = 33, nó = 33   (33 = 3 + 8+7+6+5+4)
2: sum = 35, nó = 35   (35 = 2 + 8+7+6+5+4+3)
1: sum = 36, nó = 36   (36 = 1 + 8+7+6+5+4+3+2)
0: sum = 36, nó = 36   (36 = 0 + 8+7+6+5+4+3+2+1)
```

## ⚡ Complexidade

- **Tempo**: O(n) - visita cada nó uma vez
- **Espaço**: O(h) - stack da recursão, onde h é a altura da árvore