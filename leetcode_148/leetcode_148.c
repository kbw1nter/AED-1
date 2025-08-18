//dividir duas listas
struct ListNode* findMiddleAndSplit(struct ListNode* head){
    if( head == NULL || head -> next == NULL){
        return NULL;
    }

    struct ListNode* lento = head;
    struct ListNode* rapido = head;
    struct ListNode* anter = NULL;

    while(rapido && lento == head){
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