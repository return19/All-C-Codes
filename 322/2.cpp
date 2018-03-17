#include<bits/stdc++.h>
using namespace std;
//C

#define mp make_pair
#define ft first
#define sd second

set< pair<long long,long long> > s;
set< pair<long long,long long> >::iterator it;
long long arr[101000];

int main()
{
    long long i,j;
    long long n,k;

    scanf("%lld%lld",&n,&k);

    for(i=0;i<n;i++){
        scanf("%lld",&arr[i]);
        if(arr[i]!=100)
            s.insert(mp( 10-(arr[i]%10),i ));
    }

    while(k!=0 && !s.empty())
    {
        it=s.begin();

        long long val=(*it).ft;
        long long idx=(*it).sd;

        if(k<val)
            break;
        k-=val;
        arr[idx]+=val;
        s.erase(mp(val,idx));
        if(arr[idx]!=100)
        {
            s.insert(mp(10 - (arr[idx]%10),idx));
        }
    }

    long long ans=0;

    for(i=0;i<n;i++)
        ans += (arr[i]/10);

    /*for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;*/

    printf("%lld\n",ans);

    return 0;
}










