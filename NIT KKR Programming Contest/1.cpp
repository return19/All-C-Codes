#include<bits/stdc++.h>
using namespace std;

string s;

int main()
{
    int i,j,k;
    int test,t;
    int n;

    scanf("%d",&test);

    for(t=0;t<test;t++){
        scanf("%d",&n);
        cin>>s;

        int ans=INT_MAX;

        int temp=0;

        int st=0,ed=n-1;

        while(st<ed){
            while(st<n && s[st]=='1')
                st++;
            while(ed>=0 && s[ed]=='0')
                ed--;
            if(st<ed)
                temp++;
            st++;
            ed--;
        }

        ans=min(ans,temp);
        temp=0;

        st=0;
        ed=n-1;

        while(st<ed){
            while(st<n && s[st]=='0')
                st++;
            while(ed>=0 && s[ed]=='1')
                ed--;
            if(st<ed)
                temp++;
            st++;
            ed--;
        }

        ans=min(ans,temp);

        printf("%d\n",ans);
    }

    return 0;
}















