# 147. Insertion Sort List 🔗

## Descrição 📝

Dado o `head` de uma lista ligada simples, ordene a lista usando **insertion sort** e retorne o head da lista ordenada.

O **insertion sort** funciona da seguinte forma:
1. Itera consumindo um elemento de cada vez da entrada
2. Cresce uma lista de saída ordenada
3. A cada iteração, remove um elemento da entrada e o insere na posição correta da lista ordenada
4. Repete até não sobrar elementos na entrada

## Abordagem

A solução utiliza um **nó dummy** para simplificar as inserções:

1. **Nó Dummy**: Facilita inserções no início da lista ordenada
2. **Ponteiro Current**: Percorre a lista original
3. **Ponteiro Prev**: Encontra a posição correta na lista ordenada

### Algoritmo 🔄

1. Crie um nó dummy como cabeça da lista ordenada
2. Para cada nó da lista original:
   - Salve o próximo nó
   - Encontre a posição correta na lista ordenada
   - Insira o nó atual na posição encontrada
   - Avance para o próximo nó

## Complexidade ⚡

- **Tempo**: O(n²) - no pior caso precisa percorrer a lista ordenada para cada inserção
- **Espaço**: O(1) - apenas ponteiros auxiliares

## Exemplos 📊

**Exemplo 1:**
```
Input: head = [4,2,1,3]
Output: [1,2,3,4]
```

**Exemplo 2:**
```
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
```

## Vantagens do Nó Dummy 💡

- Elimina casos especiais para inserção no início
- Simplifica o código de inserção
- Mantém a lógica consistente para todas as posições