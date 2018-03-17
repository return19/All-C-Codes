#include<bits/stdc++.h>
using namespace std;

 long long s[1000100];
 long long p[1000100],P=-1;
void sieve()
{
     long long i,j,k;
    s[0]=s[1]=1;
    for(i=2;i<=32000;i++)
    {
        if(!s[i]){
            j=2;
            p[++P]=i;

            for(k=j*i;k<=32000;k=j*i)
            {
                s[k]=1;
                j++;
        }
        }
    }
}

 long long count1( long long num)
{
    long long sum=1;
    long long i,j,k;

    for(i=2;i*i<=num;i++)
    {
        if(num%i==0)
        {
            sum=sum+i+num/i;
        }

        if(i*i==num)
            sum=sum-i;
    }

    return sum;

    /*
     long long i=0;
     long long temp=0,primef =1,flag=0;
    temp=num;
     long long sum = 1;
     long long temp2=num;
    for(i=0;;i++)
    {
        if((temp%p[i])==0)
        {
            flag=1;
            primef=1;
            while(temp%p[i]==0)
            {

                temp=temp/p[i];
                temp2=temp2/p[i];

                primef*=p[i];
            }

            primef*=p[i];

            sum*=(primef-1)/(p[i]-1);
        }

        if(temp2==1||temp2==0)
            break;
    }
    if(flag==0)
    {
        sum=1;
        return sum;
    }
    if(temp!=1){

        sum*=((temp*temp)-1)/(temp-1);
    }
    sum-=num;

    return sum;*/
}


int main()
{
     long long test,i,j,k;
     long long n;
    //sieve();
    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld",&n);

        if(n==1){
            printf("1\n");
            continue;
        }

        printf("%lld\n",count1(n)+n);
    }

    //cout<<p[P]<<endl;
    return 0;
}
