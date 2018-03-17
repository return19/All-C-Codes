#include<map>
using namespace std;
#include<stdio.h>

map<int,int> memo;
map<int,map<int,int> > memo1;
int a[1000010];
int fn[1000010][2];
int main()
{
    int n,l,i,j,k,r,sum=0,sum1=0;
    int test,t,x,y;
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    for(i=0;i<n;i++)
    {
        sum=0;
        sum1=0;
        scanf("%d%d",&l,&r);
        l--;
        r--;
        if(memo1[l][r]!=0)
        {
            fn[i][0]=l;
            fn[i][1]=r;
            continue;
        }
        else
        {
            for(j=l;j<=r;j++)
            {
                if(memo[j]!=0)
                {
                    for(k=r;;k--)
                    {
                        if(k==j)
                        {
                            j=r+1;
                            break;
                        }
                        if(k==memo[j])
                        {
                            sum1=sum1+memo1[j][k];
                            j=r+1;
                            break;
                        }
                        sum1+=a[k];
                    }
                    sum=sum+sum1;
                }
                else
                {
                    sum=sum+a[j];
                }
            }
            if(memo[l]<r)
            {
                memo[l]=r;
            }
        }
        memo1[l][r]=sum;
    }

    scanf("%d",&test);
for(j=0;j<test;j++)
{
     scanf("%d%d%d",&t,&x,&y);
    if(t==1)
    {
        x=x-1;
        for(i=0;i<n;i++)
        {
            if(fn[i][0]<=x&&fn[i][1]>=x)
            {
                memo1[fn[i][0]][fn[i][1]]=memo1[fn[i][0]][fn[i][1]]+(y-a[x]);
            }
        }
        a[x]=y;
    }
    else
    {
        x--;
        y--;
        sum=0;
        for(i=x;i<=y;i++)
        {
            sum=sum+memo1[fn[i][0]][fn[i][1]];
        }
        printf("%d\n",sum);
    }
}

    return 0;
}

