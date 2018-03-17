#include<bits/stdc++.h>
using namespace std;

vector<unsigned long long> v;

int main()
{
    unsigned long long i,j,k;
    unsigned long long n;

    scanf("%llu",&n);

    while(n!=0)
    {
        v.push_back(n%10);
        n/=10;
    }
    for(i=0,j=v.size()-1;i<j;i++,j--)
        swap(v[i],v[j]);

    unsigned long long ans=0;
    for(i=0;i<v.size();i++)
    {
        if(v[i]>=5)
            v[i]=9-v[i];
    }
    i=0;
    while(i<v.size() && v[i]==0)
        i++;

    if(i>=v.size())
    {
        printf("9\n");
        return 0;
    }

    for(;i<v.size();i++)
        printf("%llu",v[i]);
    printf("\n");
    return 0;
}
