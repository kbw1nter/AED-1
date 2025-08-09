#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
    
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(",");
    }
    printf("]\n");
}

int main() {
    // testes
    int nums1_1[] = {1, 2, 3, 0, 0, 0};
    int nums2_1[] = {2, 5, 6};
    printf("Example 1:\n");
    printf("Before: ");
    printArray(nums1_1, 6);
    merge(nums1_1, 6, 3, nums2_1, 3, 3);
    printf("After:  ");
    printArray(nums1_1, 6);
    
    int nums1_2[] = {1};
    int nums2_2[] = {};
    printf("\nExample 2:\n");
    printf("Before: ");
    printArray(nums1_2, 1);
    merge(nums1_2, 1, 1, nums2_2, 0, 0);
    printf("After:  ");
    printArray(nums1_2, 1);
    
    int nums1_3[] = {0};
    int nums2_3[] = {1};
    printf("\nExample 3:\n");
    printf("Before: ");
    printArray(nums1_3, 1);
    merge(nums1_3, 1, 0, nums2_3, 1, 1);
    printf("After:  ");
    printArray(nums1_3, 1);
    
    return 0;
}