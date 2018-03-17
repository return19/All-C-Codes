#include<bits/stdc++.h>
using namespace std;

char a[10][10];

int move_x[4]={-2,-2,2,2};
int move_y[4]={-2,2,-2,2};

int check(int x,int y){
    if(x>=0 && x<8 && y>=0 && y<8)
        return 1;
    return 0;
}

int solve(int x,int y){
    if(a[x][y]=='T' || a[x][y]=='#')
        return 0;

    if(a[x][y]=='K')
        return 1;
    a[x][y]='T';
    for(int i=0;i<4;i++){
        int tx=x+move_x[i];
        int ty=y+move_y[i];

        if(check(tx,ty) && solve(tx,ty))
            return 1;
    }
    return 0;
}

int main()
{
    int i,j,k;
    int t,test;
    scanf("%d",&test);

    for(t=0;t<test;t++){
        for(i=0;i<8;i++){
            scanf("%s",a[i]);
        }

        int sx,sy;

        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                if(a[i][j]=='K'){
                    sx=i;   sy=j;
                }
            }
        }

        a[sx][sy]='.';
        if(solve(sx,sy))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
















