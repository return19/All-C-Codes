#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

map< int,pair<int,int> > pos;
int arr[100];

int check(int x,int y){
    if(x>=0 && x<3 && y>=0 && y<3)
        return 1;
    if(x==3 && y==1)
        return 1;
    return 0;
}

int main()
{
    int i,j,k;

    k=1;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            pos[k++]=mp(i,j);
    pos[0]=mp(3,1);

    int n;
    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%1d",&arr[i]);
    for(i=0;i<=9;i++)
    {
        if(i==arr[0])
            continue;
        int x=pos[i].ft;
        int y=pos[i].sd;

        int f=0;
        int tx=x;
        int ty=y;
        for(j=1;j<n;j++){
            tx = tx + (pos[arr[j]].ft - pos[arr[j-1]].ft);
            ty = ty + (pos[arr[j]].sd - pos[arr[j-1]].sd);
            if(!check(tx,ty)){
                f=1;
                break;
            }
        }

        if(f==0)
        {
           // cout<<i<<endl;
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");


    return 0;
}












