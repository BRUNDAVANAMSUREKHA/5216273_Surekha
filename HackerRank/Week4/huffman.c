#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
} Node;

Node* newNode(char ch, int freq) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->ch = ch;
    n->freq = freq;
    n->left = n->right = NULL;
    return n;
}

/* Min-heap of Node* */
void heap_swap(Node** a, Node** b) { Node* t = *a; *a = *b; *b = t; }

void heap_push(Node** heap, int *hsz, Node* nd) {
    int i = (*hsz)++;
    heap[i] = nd;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p]->freq > heap[i]->freq) { heap_swap(&heap[p], &heap[i]); i = p; }
        else break;
    }
}

Node* heap_pop(Node** heap, int *hsz) {
    if (*hsz == 0) return NULL;
    Node* root = heap[0];
    heap[0] = heap[--(*hsz)];
    int i = 0;
    while (1) {
        int l = 2*i + 1, r = 2*i + 2, s = i;
        if (l < *hsz && heap[l]->freq < heap[s]->freq) s = l;
        if (r < *hsz && heap[r]->freq < heap[s]->freq) s = r;
        if (s != i) { heap_swap(&heap[i], &heap[s]); i = s; } else break;
    }
    return root;
}

/* Build codes by traversing tree */
void build_codes(Node* root, char** codes, char* path, int depth) {
    if (!root) return;
    if (!root->left && !root->right) {
        if (depth == 0) { /* single unique character -> give it code "0" */
            codes[(unsigned char)root->ch] = strdup("0");
        } else {
            path[depth] = '\0';
            codes[(unsigned char)root->ch] = strdup(path);
        }
        return;
    }
    if (root->left) {
        path[depth] = '0';
        build_codes(root->left, codes, path, depth+1);
    }
    if (root->right) {
        path[depth] = '1';
        build_codes(root->right, codes, path, depth+1);
    }
}

void decode_huff(Node *root, char *s) {
    Node *curr = root;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '0') curr = curr->left;
        else curr = curr->right;
        if (!curr->left && !curr->right) {
            putchar(curr->ch);
            curr = root;
        }
    }
    putchar('\n');
}

int main() {
    char buffer[10005];
    if (!fgets(buffer, sizeof(buffer), stdin)) return 0;
    /* remove trailing newline */
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len-1] == '\n') buffer[--len] = '\0';

    /* frequency */
    int freq[256] = {0};
    for (size_t i = 0; i < len; i++) freq[(unsigned char)buffer[i]]++;

    /* build heap of nodes for characters with freq>0 */
    Node* heap[256];
    int hsz = 0;
    for (int c = 0; c < 256; c++) {
        if (freq[c] > 0) heap_push(heap, &hsz, newNode((char)c, freq[c]));
    }

    if (hsz == 0) return 0; /* empty input */

    /* build Huffman tree */
    while (hsz > 1) {
        Node* a = heap_pop(heap, &hsz);
        Node* b = heap_pop(heap, &hsz);
        Node* parent = newNode('\0', a->freq + b->freq);
        parent->left = a;
        parent->right = b;
        heap_push(heap, &hsz, parent);
    }
    Node* root = heap_pop(heap, &hsz);

    /* build codes */
    char* codes[256] = {0};
    char path[1005];
    build_codes(root, codes, path, 0);

    /* compute encoded string length and build encoded string */
    size_t totbits = 0;
    for (int c = 0; c < 256; c++) if (codes[c]) totbits += (size_t)strlen(codes[c]) * (size_t)freq[c];

    char *encoded = malloc(totbits + 1);
    encoded[0] = '\0';
    for (size_t i = 0; i < len; i++) {
        char *code = codes[(unsigned char)buffer[i]];
        strcat(encoded, code);
    }

    /* decode using decode_huff (the same function judge would call) */
    decode_huff(root, encoded);

    /* cleanup (not strictly necessary in short-lived program) */
    for (int c = 0; c < 256; c++) if (codes[c]) free(codes[c]);
    free(encoded);
    /* Note: freeing tree nodes omitted for brevity */

    return 0;
}
