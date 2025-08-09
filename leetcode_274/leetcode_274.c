#include <stdio.h>

int hIndex(int* citations, int citationsSize) {
    int count[citationsSize + 1];
    
    for (int i = 0; i <= citationsSize; i++) {
        count[i] = 0;
    }
    
    for (int i = 0; i < citationsSize; i++) {
        if (citations[i] >= citationsSize) {
            count[citationsSize]++;
        } else {
            count[citations[i]]++;
        }
    }
    
    int total = 0;
    for (int i = citationsSize; i >= 0; i--) {
        total += count[i];
        if (total >= i) {
            return i;
        }
    }
    
    return 0;
}

void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(",");
    }
    printf("]");
}

int main() {

    //testes
    int citations1[] = {3, 0, 6, 1, 5};
    printf("Example 1:\n");
    printf("Input: citations = ");
    printArray(citations1, 5);
    printf("\nOutput: %d\n", hIndex(citations1, 5));
    printf("Explanation: 3 papers with at least 3 citations each\n");
    
    int citations2[] = {1, 3, 1};
    printf("\nExample 2:\n");
    printf("Input: citations = ");
    printArray(citations2, 3);
    printf("\nOutput: %d\n", hIndex(citations2, 3));
    
    int citations3[] = {100};
    printf("\nExample 3:\n");
    printf("Input: citations = ");
    printArray(citations3, 1);
    printf("\nOutput: %d\n", hIndex(citations3, 1));
    
    int citations4[] = {0, 0};
    printf("\nExample 4:\n");
    printf("Input: citations = ");
    printArray(citations4, 2);
    printf("\nOutput: %d\n", hIndex(citations4, 2));
    
    int citations5[] = {10, 8, 5, 4, 3};
    printf("\nExample 5:\n");
    printf("Input: citations = ");
    printArray(citations5, 5);
    printf("\nOutput: %d\n", hIndex(citations5, 5));
    
    return 0;
}