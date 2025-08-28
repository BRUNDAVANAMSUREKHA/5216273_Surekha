#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deto(int r,int c,char g[r][c+1],char res[r][c+1]){
    int dr[]={-1,1,0,0,0};
    int dc[]={0,0,-1,1,0};
    char temp[r][c+1];

        for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            temp[i][j]='O';

        for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(g[i][j]=='O'){
                for(int k=0;k<5;k++){
                    int ni=i+dr[k], nj=j+dc[k];
                    if(ni>=0 && ni<r && nj>=0 && nj<c)
                        temp[ni][nj]='.';
                }
            }
        }
    }

        for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            res[i][j]=temp[i][j];
        res[i][c]='\0';
    }
}

int main() {
    int r, c, n;
    scanf("%d %d %d", &r, &c, &n);
    char grid[r][c+1], t3[r][c+1], t5[r][c+1];

    for(int i=0;i<r;i++)
        scanf("%s", grid[i]);

        if(n==1){
        for(int i=0;i<r;i++)
            printf("%s\n", grid[i]);
        return 0;
    }

        deto(r, c, grid, t3);

       deto(r, c, t3, t5);

    
    if(n%2==0){  
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)
                printf("O");
            printf("\n");
        }
    }
    else if(n%4==3){  
        for(int i=0;i<r;i++)
            printf("%s\n", t3[i]);
    }
    else if(n%4==1){  
        for(int i=0;i<r;i++)
            printf("%s\n", t5[i]);
    }

    return 0;
}
