#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

// Stack structure
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Initialize stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if stack is empty
bool isEmpty(Stack *s) {
    return s->top == -1;
}

// Push to stack
void push(Stack *s, int x) {
    if (s->top < MAX_SIZE - 1) {
        s->data[++(s->top)] = x;
    }
}

// Pop from stack
int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return -1; 
}

// Peek top of stack
int peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return -1;
}

// Queue structure using two stacks
typedef struct {
    Stack s1, s2;
} MyQueue;

// Initialize queue
void myQueueInit(MyQueue *q) {
    initStack(&q->s1);
    initStack(&q->s2);
}

// Push element to queue
void myQueuePush(MyQueue *q, int x) {
    push(&q->s1, x);
}

// Pop element from queue
int myQueuePop(MyQueue *q) {
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            push(&q->s2, pop(&q->s1));
        }
    }
    return pop(&q->s2);
}

// Peek front of queue
int myQueuePeek(MyQueue *q) {
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            push(&q->s2, pop(&q->s1));
        }
    }
    return peek(&q->s2);
}

// Function to Check if queue is empty
bool myQueueEmpty(MyQueue *q) {
    return isEmpty(&q->s1) && isEmpty(&q->s2);
}

// Main function
int main() {
    MyQueue queue;
    myQueueInit(&queue);
    
    printf("null\n");
    myQueuePush(&queue, 1);
    printf("null\n");
    myQueuePush(&queue, 2);
    printf("null\n");
    printf("Peek: %d\n", myQueuePeek(&queue)); 
    printf("Pop: %d\n", myQueuePop(&queue)); 
    printf("Empty: %d\n", myQueueEmpty(&queue)); 
    
    return 0;
}
