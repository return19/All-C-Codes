#include<bits/stdc++.h>
using namespace std;

unsigned long long fact[10000100];
unsigned long long arr[100110];
unsigned long long M;

void calc_fact(unsigned long long n)
{
    unsigned long long i,j,k;
    fact[0]=1;
    for(i=1;i<=n;i++)
    {
        fact[i]=(fact[i-1]*i)%M;
    }
}

int main()
{
    unsigned long long test,i,j,k,n,max1;
    unsigned long long sum=0,temp,t,last,last_val,temp1;

    scanf("%llu%llu",&n,&M);

    max1=0;
///////////////
    for(i=0;i<n;i++)
    {
        scanf("%llu",&arr[i]);
        //if(arr[i]>=M)
          //  continue;
        //if(max1<arr[i]%M)
          //  max1=arr[i]%M;
    }
    calc_fact(M);
    sum=0;
    last_val=0;
    last=0;
    sort(arr,arr+n);

    /*for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;*/

    for(i=0;i<n;i++)
    {
        /*t=arr[i]%M;
        //temp=((((((t/2)*((t+1)/2)))/2))*t)%M;
        if(t%2==0)
        {
            temp=((((t/2)*(t+1))%M)*t)%M;
        }
        else
        {
            temp=((((t)*((t+1)/2))%M)*t)%M;
        }*/

        if(arr[i]%2==0)
        {
            t=(arr[i]/2)%M;
            temp=(((arr[i]+1)%M)*t)%M;
            temp=(temp*(arr[i]%M))%M;
        }
        else
        {
            t=((arr[i]+1)/2)%M;
            temp=(t*(arr[i]%M))%M;
            temp=(temp*(arr[i]%M))%M;

        }
        //cout<<"Tmp "<<temp<<endl;
        temp1=0;
        for(j=last_val+1;j<=arr[i];j++)
        {
            if(j<M){
            temp1=(temp1+((j)*fact[j])%M)%M;

           // cout<<endl<<(j*fact[j])<<endl;
            }
            else
                break;

        }
        //cout<<last<<" temp "<<temp<<" temp1 "<<temp1<<endl;
        //sum=(sum+temp+temp1+last)%M;
        sum=(sum+temp)%M;
        sum=(sum+temp1)%M;
        sum=(sum+last)%M;
        last=(temp1+last)%M;
        last_val=arr[i];
        //cout<<"sm "<<sum<<endl;
    }
////////////////
    printf("%llu\n",sum%M);

    return 0;
}

/*
 for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
        //if(arr[i]>=M)
          //  continue;
        if(max1<arr[i]%M)
            max1=arr[i]%M;
    }
    calc_fact(max1);
    sum=0;
    last_val=0;
    last=0;
    sort(arr,arr+n);


    for(i=0;i<n;i++)
    {
        t=arr[i]%M;
        temp=((((t*(t+1)))/2)*t)%M;
        //cout<<"Tmp "<<temp<<endl;
        for(j=last_val+1;j<=arr[i];j++)
        {
            if(j<M){
            temp1=((j)*fact[j])%M;
            temp1=temp%M;
           // cout<<endl<<(j*fact[j])<<endl;
            }
        }
        cout<<last_val<<" "<<last<<" temp "<<temp<<endl;
        sum=(sum+temp+temp1+last)%M;
        last=temp1;
        last_val=arr[i-1];
        //cout<<"sm "<<sum<<endl;
    }
*/



/*
    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);

        if(max1<arr[i]%M)
            max1=arr[i]%M;
    }
    calc_fact(max1);
    sum=0;
    for(i=0;i<n;i++)
    {
        t=arr[i]%M;
        temp=((((t*(t+1)))/2)*t)%M;
        cout<<"Tmp "<<temp<<endl;
        for(j=1;j<=arr[i];j++)
        {
            temp=temp+((j%M)*fact[j%M])%M;
            temp=temp%M;
        }
        sum=(sum+temp)%M;
        cout<<"sm "<<sum<<endl;
    }

*/






