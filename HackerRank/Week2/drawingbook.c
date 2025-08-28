#include<stdio.h>
int pagecount(int n,int p){
    int ff=p/2;
    int fb=(n/2)-(p/2);
    return ff<fb?ff:fb;
}
int main(){
    int n,p;
    scanf("%d%d",&n,&p);
    printf("%d\n",pagecount(n,p));
    return 0;
}