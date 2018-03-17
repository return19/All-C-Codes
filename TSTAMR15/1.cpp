#include<bits/stdc++.h>
using namespace std;

char t[10100];
char p[1010];

int n1,n2;

// afghan jerseys

int solve(int x,int y)
{
    if(x==n1&&y==n2)
        return 1;

    if(y==n2)
        return 1;

    if(x==n1)
    {
        if(p[y]=='*')
            return solve(x,y+1);
        return 0;
    }



    if(p[y]=='*')
    {
        return solve(x+1,y) + solve(x+1,y+1) + solve(x,y+1);
    }

    if(t[x]==p[y])
        return solve(x+1,y+1) + solve(x+1,y);

    return solve(x+1,y);

}

int main()
{
    int test,i,j,k,t1;

    scanf("%d",&test);

    for(t1=0;t1<test;t1++)
    {
        scanf("%s",t);
        scanf("%s",p);

        n1=strlen(t);
        n2=strlen(p);

        int ans=solve(0,0);

        printf("%d\n",ans);
    }

    return 0;
}
