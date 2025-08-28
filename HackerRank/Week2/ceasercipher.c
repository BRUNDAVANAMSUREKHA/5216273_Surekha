#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    int n,k;
    scanf("%d",&n);
    getchar();
    char b[n+1];
    fgets(b, sizeof(b), stdin);
    b[strcspn(b, "\n")] = '\0';
    scanf("%d",&k);
    k = k % 26;
    for(int i=0; b[i]!='\0'; i++){
        if(isupper(b[i])){
            b[i] = 'A' + (b[i]-'A' + k) % 26;
        } else if(islower(b[i])){
            b[i] = 'a' + (b[i]-'a' + k) % 26;
        }
    }
    printf("%s\n",b);
    return 0;
}