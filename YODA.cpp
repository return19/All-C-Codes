#include<bits/stdc++.h>
using namespace std;

char str[101000];

int c[260];

int M=10000000000

int power(int a,int b)
{
    if(b==0)
        return 1;

    int hf=power(a,b/2);

    if(b&1)
    {
        return (hf*((hf*a)%M))%M;
    }
    else
    {
        return (hf*hf)%M;
    }
}

int inverseM(int a)
{
    return power(a,M-2);
}

int fact[110];
int inv_fact[110];

void pre()
{
    int i,j,k;

    fact[0]=1;
    inv_fact[0]=1;

    for(i=1;i<=21;i++)
    {
        fact[i]=(fact[i-1]*i)%M;

        inverseM(fact[i]);
    }
}

int main()
{
    int i,j,k;

    int n;

    scanf("%s",str);

    n=strlen(str);

    j=0;

    pre();

    for(i=0;i<n;i++)
    {
        if((str[i]>=65&&str[i]<=90)||(str[i]>=97&&str[i]<=122))
        {
            str[j]=str[i];

            if(str[j]>=65&&str[j]<=90)
                str[j]=str[j]+32;
            j++;
        }
    }

    //cout<<"here"<<endl;

    n=j;

    str[n]='\0';

    for(i=0;i<n;i++)
    {
        c[A[i]]++;
    }

    int l=0;
    int total=0;

    for(i=0;i<257;i++)
    {
        l += c[i]%2;

        total += c[i]/2;
    }

    if(l>1)
    {
        printf("0\n");
    }

    int up=fact[total];

    ans=up;

    for(i=0;i<257;i++)
    {
        if(c[i]>=2)
        ans= ans*inv_fact[fact[c[i]/2]];
    }

    int ans=0;



    return 0;
}












