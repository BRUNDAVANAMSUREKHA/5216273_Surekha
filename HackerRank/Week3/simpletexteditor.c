#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackNode {
    char* text;
    struct StackNode* next;
} StackNode;

void push(StackNode** top, const char* str) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->text = strdup(str);
    node->next = *top;
    *top = node;
}

char* pop(StackNode** top) {
    if (*top == NULL) return NULL;
    StackNode* temp = *top;
    char* result = strdup(temp->text);
    *top = temp->next;
    free(temp->text);
    free(temp);
    return result;
}

int main() {
    int operations;
    scanf("%d", &operations);

    char* editor = (char*)malloc(1000001);
    editor[0] = '\0';

    StackNode* history = NULL;

    for (int i = 0; i < operations; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            char addition[100001];
            scanf("%s", addition);
            push(&history, editor);
            strcat(editor, addition);
        } else if (type == 2) {
            int k;
            scanf("%d", &k);
            push(&history, editor);
            int len = strlen(editor);
            editor[len - k] = '\0';
        } else if (type == 3) {
            int k;
            scanf("%d", &k);
            printf("%c\n", editor[k - 1]);
        } else if (type == 4) {
            char* previous = pop(&history);
            if (previous) {
                strcpy(editor, previous);
                free(previous);
            }
        }
    }

    free(editor);
    while (history) pop(&history);
    return 0;
}