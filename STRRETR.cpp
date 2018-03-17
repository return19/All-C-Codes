#include<bits/stdc++.h>
using namespace std;


int gcd(int a,int b)
{
    if(b!=0)
    {
        return gcd(b,a%b);
    }
    else
        return a;
}

int main()
{
    int n,i,j;
    int dif;
    int temp,pres,prev;
    int start,last;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&temp);

        if(i==0)
        {
            start=temp;
            prev=temp;
            continue;
        }
        else if(i==n-1)
        {
            last=temp;
        }
        else if(i==1)
        {
            dif=temp-prev;
            prev=temp;
        }
        dif=gcd(dif,temp-prev);
        prev=temp;
    }
   // cout<<"diff : "<<dif<<endl;

    int ans;
    ans=((last-start)/dif)+1-n;

    printf("%d\n",ans);

    return 0;
}
