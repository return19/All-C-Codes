#include<bits/stdc++.h>
using namespace std;



string rev1(string str1)
{
    long long i,n;

    n=str1.length();

    for(i=0;i<n;i++)
    {
        if(str1[i]=='0')
            str1[i]='1';
        else
            str1[i]='0';
    }

    return str1;
}

map<string,long long> memo;
map<string,long long>::iterator it;
int main()
{
    long long i,j,k;
    long long n;

    string str;

    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        cin>>str;

        memo[str]++;

        //str=rev1(str);

       // cout<<"rev : "<<str<<endl;

       // memo[str]++;
    }

    long long max1=0;

    for(it=memo.begin();it!=memo.end();it++)
    {
        //cout<<it->first<<" "<<it->second<<endl;

        max1=max(max1,it->second);
    }

    printf("%lld\n",max1);


    return 0;
}

