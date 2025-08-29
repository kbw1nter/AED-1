#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* maxHeap;  // metade menor dos números
    int* minHeap;  // metade maior dos números
    int maxSize;   // quantos números estão na metade menor
    int minSize;   // quantos números estão na metade maior
    int maxCapacity;
    int minCapacity;
} MedianFinder;

// subir elemento no maxheap
void maxHeapifyUp(int* heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] >= heap[index]) break;
        
        // troca pai com filho
        int temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;
        index = parent;
    }
}

// subir elemento no minheap
void minHeapifyUp(int* heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] <= heap[index]) break;
        
        // troca pai com filho
        int temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;
        index = parent;
    }
}

// descer no maxheap
void maxHeapifyDown(int* heap, int size, int index) {
    while (1) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        
        // encontra o maior entre pai, filho esquerdo e direito
        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;
        
        if (largest == index) break;
        
        // troca o pai com o maior filho
        int temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;
        index = largest;
    }
}

// descer no minhea´p
void minHeapifyDown(int* heap, int size, int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        
        // encontra o menor entre pai, filho esquerdo e direito
        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;
        
        if (smallest == index) break;
        
        // Troca o pai com o menor filho
        int temp = heap[index];
        heap[index] = heap[smallest];
        heap[smallest] = temp;
        index = smallest;
    }
}

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    
    // Começa com capacidade para 25000 elementos cada heap
    obj->maxCapacity = 25000;
    obj->minCapacity = 25000;
    obj->maxHeap = (int*)malloc(obj->maxCapacity * sizeof(int));
    obj->minHeap = (int*)malloc(obj->minCapacity * sizeof(int));
    obj->maxSize = 0;
    obj->minSize = 0;
    
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    // Decide onde colocar o número
    if (obj->maxSize == 0 || num <= obj->maxHeap[0]) {
        // Vai para a metade menor
        if (obj->maxSize == obj->maxCapacity) {
            obj->maxCapacity *= 2;
            obj->maxHeap = (int*)realloc(obj->maxHeap, obj->maxCapacity * sizeof(int));
        }
        obj->maxHeap[obj->maxSize] = num;
        maxHeapifyUp(obj->maxHeap, obj->maxSize);
        obj->maxSize++;
    } else {
        // Vai para a metade maior
        if (obj->minSize == obj->minCapacity) {
            obj->minCapacity *= 2;
            obj->minHeap = (int*)realloc(obj->minHeap, obj->minCapacity * sizeof(int));
        }
        obj->minHeap[obj->minSize] = num;
        minHeapifyUp(obj->minHeap, obj->minSize);
        obj->minSize++;
    }
    
    // Balanceia os heaps: a diferença não pode ser maior que 1
    if (obj->maxSize > obj->minSize + 1) {
        // move o maior da metade menor para a metade maior
        int root = obj->maxHeap[0];
        obj->maxHeap[0] = obj->maxHeap[--obj->maxSize];
        maxHeapifyDown(obj->maxHeap, obj->maxSize, 0);
        
        if (obj->minSize == obj->minCapacity) {
            obj->minCapacity *= 2;
            obj->minHeap = (int*)realloc(obj->minHeap, obj->minCapacity * sizeof(int));
        }
        obj->minHeap[obj->minSize] = root;
        minHeapifyUp(obj->minHeap, obj->minSize);
        obj->minSize++;
    } 
    else if (obj->minSize > obj->maxSize + 1) {
        // move o menor da metade maior para a metade menor
        int root = obj->minHeap[0];
        obj->minHeap[0] = obj->minHeap[--obj->minSize];
        minHeapifyDown(obj->minHeap, obj->minSize, 0);
        
        if (obj->maxSize == obj->maxCapacity) {
            obj->maxCapacity *= 2;
            obj->maxHeap = (int*)realloc(obj->maxHeap, obj->maxCapacity * sizeof(int));
        }
        obj->maxHeap[obj->maxSize] = root;
        maxHeapifyUp(obj->maxHeap, obj->maxSize);
        obj->maxSize++;
    }
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->maxSize > obj->minSize) {
        // a menor metade  tem mais elementos, a mediana é seu topo
        return (double)obj->maxHeap[0];
    } 
    else if (obj->minSize > obj->maxSize) {
        // a metade maior tem mais elementos, a mediana é seu topo
        return (double)obj->minHeap[0];
    } 
    else {
        // tamanhos iguais, mediana é a média dos dois topos
        return (obj->maxHeap[0] + obj->minHeap[0]) / 2.0;
    }
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->maxHeap);
    free(obj->minHeap);
    free(obj);
}

//testes
int main() {
    MedianFinder* mf = medianFinderCreate();
    
    printf("Adicionando 1...\n");
    medianFinderAddNum(mf, 1);
    
    printf("Adicionando 2...\n");
    medianFinderAddNum(mf, 2);
    printf("Mediana: %.1f\n", medianFinderFindMedian(mf)); // 1.5
    
    printf("Adicionando 3...\n");
    medianFinderAddNum(mf, 3);
    printf("Mediana: %.1f\n", medianFinderFindMedian(mf)); // 2.0
    
    medianFinderFree(mf);
    return 0;
}