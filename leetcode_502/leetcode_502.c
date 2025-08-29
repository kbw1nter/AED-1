#include <stdio.h>
#include <stdlib.h>

// esstrutura para armazenar projeto 
typedef struct {
    int capital;
    int profit;
} Project;

// função de comparação para ordenar projetos por capital necessário
int compareByCapital(const void* a, const void* b) {
    Project* pa = (Project*)a;
    Project* pb = (Project*)b;
    return pa->capital - pb->capital;
}

// funções do heap máximo para lucros
void maxHeapifyUp(int* heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] >= heap[index]) break;
        
        int temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;
        index = parent;
    }
}

void maxHeapifyDown(int* heap, int size, int index) {
    while (1) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        
        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;
        
        if (largest == index) break;
        
        int temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;
        index = largest;
    }
}

void heapPush(int* heap, int* size, int value) {
    heap[*size] = value;
    maxHeapifyUp(heap, *size);
    (*size)++;
}

int heapPop(int* heap, int* size) {
    if (*size == 0) return 0;
    
    int result = heap[0];
    heap[0] = heap[--(*size)];
    if (*size > 0) {
        maxHeapifyDown(heap, *size, 0);
    }
    return result;
}

int findMaximizedCapital(int k, int w, int* profits, int profitsSize, int* capital, int capitalSize) {
    // criar array de projetos e ordenar por capital necessário
    Project* projects = (Project*)malloc(profitsSize * sizeof(Project));
    for (int i = 0; i < profitsSize; i++) {
        projects[i].capital = capital[i];
        projects[i].profit = profits[i];
    }
    
    qsort(projects, profitsSize, sizeof(Project), compareByCapital);
    
    // heap para armazenar lucros dos projetos disponíveis
    int* profitHeap = (int*)malloc(profitsSize * sizeof(int));
    int heapSize = 0;
    
    int currentCapital = w;
    int projectIndex = 0;
    
    // fazer no máximo k projetos
    for (int i = 0; i < k; i++) {
        // adiciona todos os projetos que podemos pagar agora
        while (projectIndex < profitsSize && 
               projects[projectIndex].capital <= currentCapital) {
            heapPush(profitHeap, &heapSize, projects[projectIndex].profit);
            projectIndex++;
        }
        
        // se não tiver projetos disponíveis, paramos
        if (heapSize == 0) {
            break;
        }
        
        // pegar o projeto mais lucrativo disponível
        int bestProfit = heapPop(profitHeap, &heapSize);
        currentCapital += bestProfit;
    }
    
    free(projects);
    free(profitHeap);
    return currentCapital;
}

// testes
int main() {
    int profits1[] = {1, 2, 3};
    int capital1[] = {0, 1, 1};
    int result1 = findMaximizedCapital(2, 0, profits1, 3, capital1, 3);
    printf("Teste 1 - Esperado: 4, Resultado: %d\n", result1);
    
    int profits2[] = {1, 2, 3};
    int capital2[] = {0, 1, 2};
    int result2 = findMaximizedCapital(3, 0, profits2, 3, capital2, 3);
    printf("Teste 2 - Esperado: 6, Resultado: %d\n", result2);
    
    int profits3[] = {1, 2, 3};
    int capital3[] = {2, 1, 3};
    int result3 = findMaximizedCapital(2, 0, profits3, 3, capital3, 3);
    printf("Teste 3 - Capital inicial 0, só conseguimos fazer projeto com capital 1\n");
    printf("Esperado: 2, Resultado: %d\n", result3);
    
    return 0;
}