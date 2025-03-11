#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

// Queue structure
typedef struct {
    int data[MAX_SIZE];
    int front, rear, size;
} Queue;

// Initialize queue
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

// Check if queue is empty
bool isQueueEmpty(Queue *q) {
    return q->size == 0;
}

// Push to queue
void enqueue(Queue *q, int x) {
    if (q->size < MAX_SIZE) {
        q->data[q->rear] = x;
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->size++;
    }
}

// Pop from queue
int dequeue(Queue *q) {
    if (!isQueueEmpty(q)) {
        int val = q->data[q->front];
        q->front = (q->front + 1) % MAX_SIZE;
        q->size--;
        return val;
    }
    return -1; 
}

// Peek front of queue
int front(Queue *q) {
    if (!isQueueEmpty(q)) {
        return q->data[q->front];
    }
    return -1;
}

// Stack structure using two queues
typedef struct {
    Queue q1, q2;
} MyStack;

// Initialize stack
void myStackInit(MyStack *s) {
    initQueue(&s->q1);
    initQueue(&s->q2);
}

// Push element onto stack
void myStackPush(MyStack *s, int x) {
    enqueue(&s->q2, x);
    while (!isQueueEmpty(&s->q1)) {
        enqueue(&s->q2, dequeue(&s->q1));
    }
    // Swap queues
    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}

// Removes and returns top element of stack
int myStackPop(MyStack *s) {
    return dequeue(&s->q1);
}

// Function to Get the top element of stack
int myStackTop(MyStack *s) {
    return front(&s->q1);
}

// Returns whether the stack is empty
bool myStackEmpty(MyStack *s) {
    return isQueueEmpty(&s->q1);
}

// Main function
int main() {
    MyStack stack;
    myStackInit(&stack);
    
    printf("null\n");
    myStackPush(&stack, 1);
    printf("null\n");
    myStackPush(&stack, 2);
    printf("null\n");
    printf("Top: %d\n", myStackTop(&stack)); 
    printf("Pop: %d\n", myStackPop(&stack)); 
    printf("Empty: %d\n", myStackEmpty(&stack)); 
    
    return 0;
}
