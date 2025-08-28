#include<stdio.h>
#include<stdlib.h>

int towerbreakers(int n,int m){
    if(m==1||n%2==0)
        return 2;
    else
        return 1;
}
int main(){
    int a;
    scanf("%d",&a);
    while(a--){
        int n,m;
        scanf("%d%d",&n,&m);
        printf("%d\n",towerbreakers(n,m));
    }
    return 0;
}