#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

//dividir duas listas
struct ListNode* findMiddleAndSplit(struct ListNode* head){
    if( head == NULL || head -> next == NULL){
        return NULL;
    }

    struct ListNode* lento = head;
    struct ListNode* rapido = head;
    struct ListNode* anter = NULL;

    while(rapido && rapido->next){
        anter = lento;
        lento = lento->next;
        rapido = rapido->next->next;
    }

    anter->next = NULL;
    return lento;
}

// merge de duas listas
struct ListNode* mergeTwoLists(struct ListNode* lista1, struct ListNode* lista2){
    struct ListNode nodeFic;
    nodeFic.next = NULL;
    struct ListNode* tail = &nodeFic;

    while (lista1 && lista2) {
        if (lista1->val <= lista2->val) {
            tail->next = lista1;
            lista1 = lista1->next;
        } else {
            tail->next = lista2;
            lista2 = lista2->next;
        }
        tail = tail->next;
    }

    if(lista1){
        tail->next = lista1;
    } else {
        tail->next = lista2;
    }
    return nodeFic.next;
}

//ordena as listas
struct ListNode* sortList(struct ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }

    struct ListNode* secondHalf = findMiddleAndSplit(head);
    struct ListNode* sortedFirst = sortList(head);
    struct ListNode* sortedSecond = sortList(secondHalf);

    return mergeTwoLists(sortedFirst, sortedSecond);
}

struct ListNode* createNode(int val) {
    struct ListNode* node = malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
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
    // Teste 1: [4,2,1,3] -> [1,2,3,4]
    struct ListNode* head1 = createNode(4);
    head1->next = createNode(2);
    head1->next->next = createNode(1);
    head1->next->next->next = createNode(3);
    
    printf("Teste 1: ");
    printList(head1);
    head1 = sortList(head1);
    printf("Resultado: ");
    printList(head1);
    freeList(head1);
    printf("\n");
    
    // Teste 2: [-1,5,3,4,0] -> [-1,0,3,4,5]
    struct ListNode* head2 = createNode(-1);
    head2->next = createNode(5);
    head2->next->next = createNode(3);
    head2->next->next->next = createNode(4);
    head2->next->next->next->next = createNode(0);
    
    printf("Teste 2: ");
    printList(head2);
    head2 = sortList(head2);
    printf("Resultado: ");
    printList(head2);
    freeList(head2);
    printf("\n");
    
    // Teste 3: [] -> []
    struct ListNode* head3 = NULL;
    printf("Teste 3: ");
    printList(head3);
    head3 = sortList(head3);
    printf("Resultado: ");
    printList(head3);
    freeList(head3); 
    
    return 0;
}