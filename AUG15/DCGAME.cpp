#include<bits/stdc++.h>
using namespace std;

struct elem
{
    long long val,lt,rt,pro,cs;
};

elem arr[1000100];

stack<long long> s;

bool cmp(elem a,elem b)
{
    return a.val<b.val;
}

bool cmp1(elem a,long long b)
{
    return a.val<b;
}

bool cmp2(long long a,elem b)
{
    return a<b.val;
}

int main()
{
    long long n,i,j,k;

    scanf("%lld%lld",&n,&k);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i].val);
    }

    s.push(0);
    arr[0].lt=1;

    for(i=1;i<n;i++)
    {  // cout<<"test "<<s.size()<<" "<<s.top()<<endl;
        while(!s.empty()&&arr[s.top()].val<arr[i].val)
            s.pop();

        if(s.empty())
        {
            arr[i].lt=i+1;
        }
        else
        {
            arr[i].lt=i-s.top();
        }

        s.push(i);

    }

   /* for(i=0;i<n;i++)
    {
        cout<<arr[i].lt<<" ";
    }
    cout<<endl;*/

    arr[n-1].rt=1;

    while(!s.empty())
        s.pop();

    s.push(n-1);

    for(i=n-2;i>=0;i--)
    {  // cout<<"test "<<s.size()<<" "<<s.top()<<endl;
        while(!s.empty()&&arr[s.top()].val<=arr[i].val)
            s.pop();

        if(s.empty())
        {
            arr[i].rt=(n-1)-i+1;

        }
        else
        {
            arr[i].rt=s.top()-i;
        }



        s.push(i);

    }

   /* cout<<endl;
     for(i=0;i<n;i++)
    {
        cout<<arr[i].rt<<" ";
    }*/

    //int sum1=0;



    for(i=0;i<n;i++)
    {
        arr[i].pro=arr[i].lt*arr[i].rt;
    }


    //cout<<endl<<sum1<<" : "<<n*(n+1)/2<<endl;



    sort(arr,arr+n,cmp);

    arr[0].cs=arr[0].pro;

    for(i=1;i<n;i++)
    {
        arr[i].cs=arr[i-1].cs+arr[i].pro;
    }

    /*for(i=0;i<n;i++)
    {
        cout<<arr[i].val<<" ";
    }
    cout<<endl;

    for(i=0;i<n;i++)
    {
        cout<<arr[i].cs<<" ";
    }
    cout<<endl;*/

    char a[2],b[2];
    string str;
    long long temp;
    long long sum=0;

    long long low,high;

    for(i=0;i<k;i++)
    {
        scanf("%s%lld%s",a,&temp,b);
        sum=0;

        low=lower_bound(arr,arr+n,temp,cmp1)-arr;
        high=upper_bound(arr,arr+n,temp,cmp2)-arr;

        //cout<<"low : "<<low<<"  high : "<<high<<endl;

        if(a[0]=='=')
        {
            if(arr[low].val==temp)
            {
                if(low!=0)
                    sum=arr[high-1].cs-arr[low-1].cs;
                else
                    sum=arr[high-1].cs;
            }
            else
            {
                sum=0;
            }
        }
        else if(a[0]=='>')
        {
            if(arr[low].val==temp)
            {
                sum=arr[n-1].cs-arr[high-1].cs;
            }
            else
            {
                if(high!=0)
                    sum=arr[n-1].cs-arr[high-1].cs;
                else
                    sum=arr[n-1].cs;
            }
        }
        else
        {
            if(arr[low].val==temp)
            {
                if(low==0)
                    sum=0;
                else
                    sum=arr[low-1].cs;
            }
            else
            {
                if(high==0)
                    sum=0;
                else
                    sum=arr[high-1].cs;
            }
        }
       // cout<<"sum : "<<sum<<endl;
        if(sum%2==0)
            {
                if(b[0]=='C')
                    printf("D");
                else
                    printf("C");

            }
        else
            {
                if(b[0]=='C')
                    printf("C");
                else
                    printf("D");
            }
    }

    //cout<<str<<endl;


    return 0;
}











