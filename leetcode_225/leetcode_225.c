#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// estrutura pra representar um nó da fila
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

// representar uma fila
typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
    int size;
} Queue;

// estrutura da pilha usando duas filas
typedef struct {
    Queue* q1;  // Fila principal
    Queue* q2;  // Fila auxiliar
} MyStack;

// função para criar uma nova fila
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

// função para adicionar elemento na fila (enqueue)
void enqueue(Queue* q, int x) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = x;
    newNode->next = NULL;
    
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

// função para remover elemento da fila (dequeue)
int dequeue(Queue* q) {
    if (q->front == NULL) return -1;
    
    QueueNode* temp = q->front;
    int data = temp->data;
    
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    q->size--;
    return data;
}

// função para verificar se a fila está vazia
bool isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

// função para obter o elemento da frente da fila sem removê-lo
int queueFront(Queue* q) {
    if (q->front == NULL) return -1;
    return q->front->data;
}

// criar a pilha
MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->q1 = createQueue();
    stack->q2 = createQueue();
    return stack;
}

// Push: Adicionar elemento no topo da pilha
void myStackPush(MyStack* obj, int x) {
    // adiciona o novo elemento na q2
    enqueue(obj->q2, x);
    
    // move todos os elementos de q1 para q2
    while (!isQueueEmpty(obj->q1)) {
        enqueue(obj->q2, dequeue(obj->q1));
    }
    
    // troca q1 e q2 (q1 se torna a fila principal)
    Queue* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
}

// Pop: Remove e retorna o elemento do topo da pilha
int myStackPop(MyStack* obj) {
    if (isQueueEmpty(obj->q1)) return -1;
    return dequeue(obj->q1);
}

// Top: Retorna o elemento do topo da pilha sem removê-lo
int myStackTop(MyStack* obj) {
    if (isQueueEmpty(obj->q1)) return -1;
    return queueFront(obj->q1);
}

// Empty: Verifica se a pilha está vazia
bool myStackEmpty(MyStack* obj) {
    return isQueueEmpty(obj->q1);
}

// Free: Libera a memória alocada para a pilha
void myStackFree(MyStack* obj) {
    // libera todos os nós da q1
    while (!isQueueEmpty(obj->q1)) {
        dequeue(obj->q1);
    }
    
    // libera todos os nós da q2
    while (!isQueueEmpty(obj->q2)) {
        dequeue(obj->q2);
    }
    
    // libera as estruturas das filas
    free(obj->q1);
    free(obj->q2);
    
    // libera a estrutura da pilha
    free(obj);
}

// teste (opcional)
int main() {
    MyStack* myStack = myStackCreate();
    
    myStackPush(myStack, 1);
    myStackPush(myStack, 2);
    
    printf("Top: %d\n", myStackTop(myStack));  // return 2
    printf("Pop: %d\n", myStackPop(myStack));  // return 2
    printf("Empty: %s\n", myStackEmpty(myStack) ? "true" : "false");  // return false
    
    myStackFree(myStack);
    return 0;
}