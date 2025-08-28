#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000
#define MODHASH 200003

int heap[MAXN+5];
int heapSize = 0;

void swap(int *a, int *b){int t=*a;*a=*b;*b=t;}

void heapifyUp(int i){
    while(i>0){
        int p=(i-1)/2;
        if(heap[p]>heap[i]){swap(&heap[p],&heap[i]);i=p;}else break;
    }
}

void heapifyDown(int i){
    while(1){
        int l=2*i+1,r=2*i+2,s=i;
        if(l<heapSize&&heap[l]<heap[s])s=l;
        if(r<heapSize&&heap[r]<heap[s])s=r;
        if(s!=i){swap(&heap[i],&heap[s]);i=s;}else break;
    }
}

void push(int x){heap[heapSize]=x;heapifyUp(heapSize);heapSize++;}
int top(){return heap[0];}
void pop(){heap[0]=heap[--heapSize];heapifyDown(0);}

typedef struct Node{int val;struct Node*next;}Node;
Node*deleted[MODHASH];
int hash(int x){return(x%MODHASH+MODHASH)%MODHASH;}
void markDeleted(int x){int h=hash(x);Node*n=malloc(sizeof(Node));n->val=x;n->next=deleted[h];deleted[h]=n;}
int isDeleted(int x){int h=hash(x);Node*c=deleted[h];while(c){if(c->val==x)return 1;c=c->next;}return 0;}

int main(){
    int Q;scanf("%d",&Q);
    while(Q--){
        int t,x;scanf("%d",&t);
        if(t==1){scanf("%d",&x);push(x);}
        else if(t==2){scanf("%d",&x);markDeleted(x);}
        else{while(heapSize>0&&isDeleted(top()))pop();printf("%d\n",top());}
    }
    return 0;
}
