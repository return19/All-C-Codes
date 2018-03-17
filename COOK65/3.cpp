#include<bits/stdc++.h>
using namespace std;

unordered_map<long long,long long> memo;
unordered_map<long long,long long> base;

long long m=4294967296;

int main()
{
    long long test,i,j,k,t;

    long long n,s,a,b;

    scanf("%lld%lld%lld%lld",&n,&s,&a,&b);

    long long prev=s;
    long long sum=0;

    long long s1=s;

    if(s%2!=0){
        memo[s1/2]=1;
        sum+=s1/2;
    }
    else
        memo[s1/2]=0;

    //cout<<"s :"<<s<<endl;

    for(i=1;i<n;i++)
    {
        //cout<<"insi"<<endl;

        s=((prev*a)%m + b)%m;

       /* if(base[s]==1)
        {
            j=(n/(i+1)) - 1;
            sum=sum + (sum)*j;

            i=i*(j+1);


            //cout<<"here"<<" : "<<i<<endl;
            continue;
        }*/
       // cout<<i<<endl;

        base[s]=1;

        prev=s;
        //cout<<"here"<<endl;

        s1=s;

        //cout<<"s :"<<s<<endl;

       // cout<<"here"<<endl;

        if(s%2!=0)
        {
            if(memo[s1/2]==0)
            {
                memo[s1/2]=1;
                sum+=s1/2;
            }
        }
        else
        {
            if(memo[s1/2]==1)
            {
                memo[s1/2]=0;
                sum-=s1/2;
            }
        }


        //cout<<"here"<<endl;
    }



    printf("%lld\n",sum);

    return 0;
}

