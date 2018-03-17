#include<bits/stdc++.h>
using namespace std;

map< pair< pair<long long,long long>,long long >,long long > memo;
map< pair< pair<long long,long long>,long long >,long long >::iterator it;

char str[1010000];

int main()
{
    long long i,j,k;
    long long n;
    long long x=0,y=0,z=0;

    scanf("%s",str);
    n=strlen(str);

    memo[make_pair(make_pair(0,0),0)]++;

    for(i=0;i<n;i++){
        if(str[i]=='A'){
            x++;
        }else if(str[i]=='B'){
            y++;
        }else{
            z++;
        }

        long long temp=min(min(x,y),z);
        x -= temp;
        y -= temp;
        z -= temp;

       // cout<<x<<" "<<y<<" "<<z<<endl;

        memo[ make_pair(make_pair(x,y),z) ] ++;
    }

    long long ans=0;

    for(it=memo.begin();it!=memo.end();it++){
        ans += (it->second)*(it->second - 1)/2;
    }

    printf("%lld\n",ans);

    return 0;
}



















