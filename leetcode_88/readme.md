# 88. Merge Sorted Array 🔀

## Descrição 📝

Dado dois arrays de inteiros `nums1` e `nums2` ordenados em ordem não-decrescente, e dois inteiros `m` e `n` representando o número de elementos em `nums1` e `nums2` respectivamente, mescle `nums1` e `nums2` em um único array ordenado.

O array final deve ser armazenado dentro do array `nums1`.

## Abordagem 

A solução utiliza a técnica de **dois ponteiros** começando do final dos arrays:

1. **Ponteiro i**: Posição do último elemento válido em `nums1`
2. **Ponteiro j**: Posição do último elemento em `nums2`  
3. **Ponteiro k**: Posição onde inserir o próximo elemento (final de `nums1`)

### Por que começar do final?

- Evita sobrescrever elementos válidos de `nums1`
- Utiliza o espaço extra no final de `nums1`
- Complexidade O(m+n) com espaço O(1)

## Complexidade ⚡

- **Tempo**: O(m + n) - percorre cada elemento uma vez
- **Espaço**: O(1) - apenas variáveis auxiliares

## Exemplos 📊

**Exemplo 1:**
```
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
```

**Exemplo 2:**
```
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
```

**Exemplo 3:**
```
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
```