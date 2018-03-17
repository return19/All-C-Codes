#include<bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked

int arr[1000010];
int qans[2000100];

int memo[10001000];

int answer;

int bsize=555;

struct node
{
    int i,j,inx;
}qarr[2000100];
/*
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}*/

void add(int x)
{
    if(memo[x]==0)
        answer++;

    memo[x]++;
}

void sub(int x)
{
    if(memo[x]==1)
        answer--;
    memo[x]--;
}

bool cmp(node a,node b)
{
    if(a.i!=b.i)
    {
        return (a.i/bsize<b.i/bsize);
    }

    return (a.j<b.j);
}

int main()
{
    int test,i,j,k,n,q;

    int a,b;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    //bsize=sqrt(n);

    scanf("%d",&q);

    for(i=0;i<q;i++)
    {
        scanf("%d%d",&a,&b);


        qarr[i].i=a-1;
        qarr[i].j=b-1;
        qarr[i].inx=i;
    }

    sort(qarr,qarr+q,cmp);

    answer=0;
    int l=0,r=0;
    for(i=0;i<q;i++)
    {
        a=qarr[i].i;
        b=qarr[i].j;

        while(r<=b)
        {
            add(arr[r]);
            r++;
        }
        while(r>b+1)
        {
            sub(arr[r-1]);
            r--;
        }
        while(l<a)
        {
            sub(arr[l]);
            l++;
        }
        while(l>a)
        {
            add(arr[l-1]);
            l--;
        }

       qans[qarr[i].inx]=answer;
    }

    for(i=0;i<q;i++)
    {
        printf("%d\n",qans[i]);
    }

    return 0;
}
















