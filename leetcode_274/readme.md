# 274. H-Index 📊

## Descrição 📝

Dado um array de inteiros `citations` onde `citations[i]` é o número de citações que um pesquisador recebeu para seu `i-ésimo` paper, retorne o **h-index** do pesquisador.

Segundo a definição da Wikipedia: O h-index é definido como o valor máximo de `h` tal que o pesquisador publicou pelo menos `h` papers que foram citados pelo menos `h` vezes cada.

## Abordagem 

A solução utiliza **Counting Sort** otimizado:

### Algoritmo 

1. **Counting Array**: Cria array de contagem de tamanho `n+1`
2. **Agrupamento**: Papers com citações ≥ n são agrupados no índice `n`
3. **Busca Reversa**: Percorre do maior para o menor h-index possível
4. **Verificação**: Encontra o maior `h` onde temos pelo menos `h` papers com `≥h` citações

### Por que Counting Sort?

- H-index máximo possível é `n` (número de papers)
- Evita ordenação O(n log n)
- Aproveita o limite das constraints
- Permite busca eficiente da resposta

## Complexidade ⚡

- **Tempo**: O(n) - uma passada para contar + uma para buscar
- **Espaço**: O(n) - array de contagem

## Exemplos 📊

**Exemplo 1:**
```
Input: citations = [3,0,6,1,5]
Output: 3
Explicação: 3 papers com pelo menos 3 citações cada
```

**Exemplo 2:**
```
Input: citations = [1,3,1]
Output: 1
Explicação: 1 paper com pelo menos 1 citação
```