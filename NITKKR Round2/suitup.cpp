#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

int n,m;
char arr[510][510];
int memo[510][510][50];
queue< pair< pair<int,int>,pair<int,int> > > q; // x,y,val,mask

int mx[10] = {-1,1,0,0};
int my[10] = {0,0,-1,1};

int isSet(int mask,int pos){
    if((1<<pos)&mask)
        return 1;
    return 0;
}

void maskit(int &mask,int pos){
    mask = mask|(1<<pos);
}

void maskSuit(int &mask,int x,int y){
    if(arr[x][y]=='.')
        return;
    int pos;
    if(arr[x][y]=='P')
        pos=0;
    else if(arr[x][y]=='S')
        pos=1;
    else if(arr[x][y]=='T')
        pos=2;
    else if(arr[x][y]=='C')
        pos=3;
    mask = mask|(1<<pos);
}

int check(int x,int y){
    if(x>=0 && x<m && y>=0 && y<n)
        return 1;
    return 0;
}

int main()
{
    int i,j,k;
    int sx,sy;
    int x,y,z;

    scanf("%d%d",&m,&n);
    scanf("%d%d",&sx,&sy);
    sx--;
    sy--;

    for(i=0;i<m;i++)
        scanf("%s",arr[i]);

    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            for(k=0;k<50;k++)
                memo[i][j][k] = INT_MAX;

    int temp=0;
    maskSuit(temp,sx,sy);
    memo[sx][sy][temp] = 0;
    q.push(mp(mp(sx,sy),mp(temp,0)));

    while(!q.empty()){
        pair< pair<int,int>,pair<int,int> > p = q.front();
        q.pop();
        x = p.ft.ft;
        y = p.ft.sd;
        int val = p.sd.ft;
        int mask = p.sd.sd;

        for(i=0;i<4;i++){
            int tx = x + mx[i];
            int ty = y + my[i];

            if(!check(tx,ty))
                continue;

            int temp = mask;
            maskSuit(temp,tx,ty);

            if(temp == 15)
            {
                printf("%d\n",val+1);
                return 0;
            }

            if(memo[tx][ty][temp] <= val+1)
                continue;
            memo[tx][ty][temp] = val+1;
            q.push(mp(mp(tx,ty),mp(val+1,temp)));
        }
    }

    return 0;
}
















