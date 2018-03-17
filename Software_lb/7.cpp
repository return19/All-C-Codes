#include<bits/stdc++.h>
using namespace std;

int s[101000];
vector<int> p;

void sieve()
{
    int i,j,k;

    s[0]=s[1]=1;

    for(i=2;i<100100;i++)
    {
        if(s[i]==0)
        {
            k=2;
            for(j=i*k;j<10100;j=i*k)
            {
                s[j]=1;
                k++;
            }
        }
    }
}

int main()
{
    int i,j,k;
    int n;
    int test,t;

    scanf("%d",&test);

    for(t=0;t<test;t++){

        scanf("%d",&n);
        if(n==1 || n==0)
        {
            cout<<"branch : "<<1<<endl;
            printf("Not a prime\n");
            continue;
        }
        else if(n==2)
        {
            cout<<"branch : "<<2<<endl;
            printf("prime\n");
            continue;
        }

        for(i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
                break;
        }

        if(i>sqrt(n))
        {
            cout<<"branch : "<<3<<endl;
            printf("Prime number\n");
        }else{
            cout<<"branch : "<<4<<endl;
            printf("Not a prime\n");
        }
    }

    return 0;
}
