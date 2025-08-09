#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* insertionSortList(struct ListNode* head) {
    if (!head || !head->next) return head;
    
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = NULL;
    
    struct ListNode* current = head;
    
    while (current) {
        struct ListNode* next = current->next;
        struct ListNode* prev = dummy;
        
        while (prev->next && prev->next->val < current->val) {
            prev = prev->next;
        }
        
        current->next = prev->next;
        prev->next = current;
        
        current = next;
    }
    
    head = dummy->next;
    free(dummy);
    return head;
}

struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode* createList(int* arr, int size) {
    if (size == 0) return NULL;
    
    struct ListNode* head = createNode(arr[0]);
    struct ListNode* current = head;
    
    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    
    return head;
}

void printList(struct ListNode* head) {
    printf("[");
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(",");
        head = head->next;
    }
    printf("]\n");
}

void freeList(struct ListNode* head) {
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {

    //testes
    int arr1[] = {4, 2, 1, 3};
    struct ListNode* head1 = createList(arr1, 4);
    printf("Example 1:\n");
    printf("Before: ");
    printList(head1);
    head1 = insertionSortList(head1);
    printf("After:  ");
    printList(head1);
    freeList(head1);
    
    int arr2[] = {-1, 5, 3, 4, 0};
    struct ListNode* head2 = createList(arr2, 5);
    printf("\nExample 2:\n");
    printf("Before: ");
    printList(head2);
    head2 = insertionSortList(head2);
    printf("After:  ");
    printList(head2);
    freeList(head2);
    
    int arr3[] = {1};
    struct ListNode* head3 = createList(arr3, 1);
    printf("\nExample 3:\n");
    printf("Before: ");
    printList(head3);
    head3 = insertionSortList(head3);
    printf("After:  ");
    printList(head3);
    freeList(head3);
    
    return 0;
}