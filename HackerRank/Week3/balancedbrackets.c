#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackNode {
    char value;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} Stack;

void push(Stack* s, char c) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->value = c;
    node->next = s->top;
    s->top = node;
}

char pop(Stack* s) {
    if (!s->top) return 0;
    StackNode* temp = s->top;
    char val = temp->value;
    s->top = temp->next;
    free(temp);
    return val;
}

int isEmpty(Stack* s) {
    return s->top == NULL;
}

int isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

char* isBalanced(char* s) {
    Stack st;
    st.top = NULL;
    for (int i = 0; s[i]; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            push(&st, c);
        } else {
            if (isEmpty(&st)) return "NO";
            char top = pop(&st);
            if (!isMatching(top, c)) return "NO";
        }
    }
    return isEmpty(&st) ? "YES" : "NO";
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char s[1001];
        scanf("%s", s);
        printf("%s\n", isBalanced(s));
    }
    return 0;
}