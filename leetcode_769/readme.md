# 🧩 LeetCode 769: Max Chunks To Make Sorted

## Informações do Problema

- **Número**: 769
- **Título**: Max Chunks To Make Sorted
- **Dificuldade**: Medium
- **Link**: [LeetCode 769](https://leetcode.com/problems/max-chunks-to-make-sorted/)
- **Tópicos**: Array, Stack, Greedy, Sorting, Monotonic Stack

## Descrição do Problema

Dado um array de inteiros `arr` de tamanho `n` que representa uma permutação dos inteiros no intervalo `[0, n - 1]`.

Dividimos `arr` em alguns **chunks** (partições) e ordenamos cada chunk individualmente. Após concatená-los, o resultado deve ser igual ao array ordenado.

Retorne o **maior número de chunks** que podemos fazer para ordenar o array.

## 🎯 Exemplos

### Exemplo 1:
```
Input: arr = [4,3,2,1,0]
Output: 1
Explicação: Dividir em dois ou mais chunks não retornará o resultado necessário.
Por exemplo, dividir em [4, 3], [2, 1, 0] resultará em [3, 4, 0, 1, 2], que não está ordenado.
```

### Exemplo 2:
```
Input: arr = [1,0,2,3,4]
Output: 4
Explicação: Podemos dividir em [1, 0], [2], [3], [4] para obter o máximo de chunks.
```

## Estratégia da Solução

### Insight Principal
Como o array é uma permutação de `[0, n-1]`, podemos usar a propriedade de que **podemos criar um chunk terminando na posição `i` se e somente se o valor máximo de `arr[0...i]` for igual a `i`**.

### Por que funciona?
- Se `max(arr[0...i]) = i`, significa que todos os valores `[0, i]` estão presentes nas primeiras `i+1` posições
- Portanto, ordenar este chunk resultará em `[0, 1, ..., i]`
- Este chunk pode ser independente do resto do array

### Algoritmo
1. Percorrer o array mantendo o **valor máximo** visto até agora
2. A cada posição `i`, verificar se `maxSoFar == i`
3. Se sim, podemos criar um chunk → incrementar contador
4. Retornar o total de chunks

## ⚡ Implementação

### Versão para LeetCode
```c
int maxChunksToSorted(int* arr, int arrSize) {
    int chunks = 0;
    int maxSoFar = 0;
    
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > maxSoFar) {
            maxSoFar = arr[i];
        }
        
        if (maxSoFar == i) {
            chunks++;
        }
    }
    
    return chunks;
}
```

## 📊 Análise de Complexidade

- **Tempo**: O(n) - uma única passagem pelo array
- **Espaço**: O(1) - apenas variáveis auxiliares

## 🧪 Casos de Teste

| Input | Output | Explicação |
|-------|--------|------------|
| `[4,3,2,1,0]` | `1` | Apenas um chunk possível |
| `[1,0,2,3,4]` | `4` | Chunks: `[1,0]`, `[2]`, `[3]`, `[4]` |
| `[0,1,2,3,4]` | `5` | Array já ordenado - cada elemento é um chunk |
| `[0]` | `1` | Elemento único |
| `[1,0]` | `1` | Elementos trocados - apenas um chunk |
| `[2,0,1,3]` | `2` | Chunks: `[2,0,1]`, `[3]` |

## 🔍 Análise Passo a Passo

### Para `[1,0,2,3,4]`:

| Índice | Valor | Max até agora | Max == Índice? | Chunks |
|--------|-------|---------------|----------------|---------|
| 0      | 1     | 1             | ❌ (1 ≠ 0)    | 0       |
| 1      | 0     | 1             | ✅ (1 = 1)    | 1       |
| 2      | 2     | 2             | ✅ (2 = 2)    | 2       |
| 3      | 3     | 3             | ✅ (3 = 3)    | 3       |
| 4      | 4     | 4             | ✅ (4 = 4)    | 4       |

**Resultado**: 4 chunks = `[1,0]`, `[2]`, `[3]`, `[4]`