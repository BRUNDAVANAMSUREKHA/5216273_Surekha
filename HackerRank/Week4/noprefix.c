#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 10  // since only 'a' to 'j'

typedef struct TrieNode {
    bool isEndOfWord;
    struct TrieNode *children[ALPHABET_SIZE];
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

bool insert(TrieNode* root, char* word) {
    TrieNode* current = root;
    for (int i = 0; word[i]; i++) {
        int idx = word[i] - 'a';

        if (!current->children[idx]) {
            current->children[idx] = createNode();
        }

        current = current->children[idx];

        if (current->isEndOfWord) {
            return false;
        }
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (current->children[i]) {
            return false;
        }
    }

    current->isEndOfWord = true;
    return true;
}

void noPrefix(int words_count, char** words) {
    TrieNode* root = createNode();

    for (int i = 0; i < words_count; i++) {
        if (!insert(root, words[i])) {
            printf("BAD SET\n%s\n", words[i]);
            return;
        }
    }

    printf("GOOD SET\n");
}

// ---------------- Main & Helpers ----------------

char* readline();
char* ltrim(char*);
char* rtrim(char*);
int parse_int(char*);

int main() {
    int n = parse_int(ltrim(rtrim(readline())));
    char** words = malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        words[i] = readline();
    }

    noPrefix(n, words);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) break;
        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') break;
        alloc_length <<= 1;
        data = realloc(data, alloc_length);
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }
    return data;
}

char* ltrim(char* str) {
    while (*str != '\0' && isspace(*str)) str++;
    return str;
}

char* rtrim(char* str) {
    if (!*str) return str;
    char* end = str + strlen(str) - 1;
    while (end >= str && isspace(*end)) end--;
    *(end + 1) = '\0';
    return str;
}

int parse_int(char* str) {
    return strtol(str, NULL, 10);
}
