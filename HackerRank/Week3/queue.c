#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {
    int value;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} Stack;

void push(Stack* s, int val) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->value = val;
    node->next = s->top;
    s->top = node;
}

int pop(Stack* s) {
    if (!s->top) return -1;
    StackNode* temp = s->top;
    int val = temp->value;
    s->top = temp->next;
    free(temp);
    return val;
}

int peek(Stack* s) {
    return s->top ? s->top->value : -1;
}

int isEmpty(Stack* s) {
    return s->top == NULL;
}

typedef struct {
    Stack stackIn;
    Stack stackOut;
} Queue;

void enqueue(Queue* q, int val) {
    push(&q->stackIn, val);
}

void dequeue(Queue* q) {
    if (isEmpty(&q->stackOut)) {
        while (!isEmpty(&q->stackIn)) {
            push(&q->stackOut, pop(&q->stackIn));
        }
    }
    if (!isEmpty(&q->stackOut)) {
        pop(&q->stackOut);
    }
}

int front(Queue* q) {
    if (isEmpty(&q->stackOut)) {
        while (!isEmpty(&q->stackIn)) {
            push(&q->stackOut, pop(&q->stackIn));
        }
    }
    return peek(&q->stackOut);
}

int main() {
    int queries;
    scanf("%d", &queries);

    Queue q;
    q.stackIn.top = NULL;
    q.stackOut.top = NULL;

    for (int i = 0; i < queries; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int val;
            scanf("%d", &val);
            enqueue(&q, val);
        } else if (type == 2) {
            dequeue(&q);
        } else if (type == 3) {
            printf("%d\n", front(&q));
        }
    }

    return 0;
}