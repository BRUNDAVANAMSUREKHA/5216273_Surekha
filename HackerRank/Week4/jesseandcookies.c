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

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);
int parse_int(char*);

#define MAXN 1000000

int heap[MAXN];
int heapSize;

void swap(int *a,int *b){int t=*a;*a=*b;*b=t;}

void heapifyUp(int i){
    while(i>0){
        int p=(i-1)/2;
        if(heap[p]>heap[i]){swap(&heap[p],&heap[i]);i=p;} else break;
    }
}

void heapifyDown(int i){
    while(1){
        int l=2*i+1,r=2*i+2,s=i;
        if(l<heapSize && heap[l]<heap[s]) s=l;
        if(r<heapSize && heap[r]<heap[s]) s=r;
        if(s!=i){swap(&heap[i],&heap[s]);i=s;} else break;
    }
}

void push(int x){heap[heapSize]=x;heapifyUp(heapSize);heapSize++;}
int top(){return heap[0];}
void pop(){heap[0]=heap[--heapSize];heapifyDown(0);}

int cookies(int k, int A_count, int* A) {
    heapSize=0;
    for(int i=0;i<A_count;i++) push(A[i]);
    int ops=0;
    while(heapSize>0 && top()<k){
        if(heapSize<2) return -1;
        int a=top();pop();
        int b=top();pop();
        int c=a+2*b;
        push(c);
        ops++;
    }
    return ops;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** first_multiple_input = split_string(rtrim(readline()));

    int n = parse_int(*(first_multiple_input + 0));

    int k = parse_int(*(first_multiple_input + 1));

    char** A_temp = split_string(rtrim(readline()));

    int* A = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int A_item = parse_int(*(A_temp + i));
        *(A + i) = A_item;
    }

    int result = cookies(k, n, A);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

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
        if (!data) {data = '\0';break;}
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
        data = realloc(data, data_length);
        if (!data) data = '\0';
    } else {
        data = realloc(data, data_length + 1);
        if (!data) data = '\0';
        else data[data_length] = '\0';
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) return '\0';
    if (!*str) return str;
    while (*str != '\0' && isspace(*str)) str++;
    return str;
}

char* rtrim(char* str) {
    if (!str) return '\0';
    if (!*str) return str;
    char* end = str + strlen(str) - 1;
    while (end >= str && isspace(*end)) end--;
    *(end + 1) = '\0';
    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");
    int spaces = 0;
    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) return splits;
        splits[spaces - 1] = token;
        token = strtok(NULL, " ");
    }
    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);
    if (endptr == str || *endptr != '\0') exit(EXIT_FAILURE);
    return value;
}
