# 📹 Binary Tree Cameras

**LeetCode 968 - Hard**

## Problema

Você recebe o `root` de uma árvore binária. Instale câmeras nos nós da árvore onde cada câmera pode monitorar seu **pai**, **ele mesmo** e seus **filhos imediatos**.

Retorne o **número mínimo de câmeras** necessárias para monitorar todos os nós da árvore.

## Exemplos

### Exemplo 1:
```
Input:  root = [0,0,null,0,0]
Output: 1

    0
   /        📹 Uma câmera aqui
  0              cobre todos os nós
 / \
0   0
```

### Exemplo 2:
```
Input:  root = [0,0,null,0,null,0,null,null,0]  
Output: 2

    0
   /         📹 Duas câmeras necessárias
  0              para cobrir toda a árvore
 /
0
 \
  0
   \
    0
```
