#include<bits/stdc++.h>
using namespace std;

#define ft first
#define sd second

int n;
pair< pair<int,int>,int > arr[1010000];
pair< pair<int,int>,int > pos[1010000];

int bt[1010000];

void update(int x,int val){
    while(x<=n){
        bt[x] = min(bt[x],val);
        x += (x)&(-x);
    }
}

int getmin(int x){
    if(x==0)    return INT_MAX;
    int ans=INT_MAX;
    while(x>0){
        ans=min(ans,bt[x]);
        x -= (x)&(-x);
    }
    return ans;
}

int main()
{
    int i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&pos[i].ft.ft);
    for(i=0;i<n;i++)
        scanf("%d",&pos[i].ft.sd);
    for(i=0;i<n;i++)
        scanf("%d",&pos[i].sd);

    for(i=0;i<n;i++){
        arr[pos[i].ft.ft -1 ].ft.ft=i+1;
        arr[pos[i].ft.sd -1 ].ft.sd=i+1;
        arr[pos[i].sd -1 ].sd=i+1;
    }

    sort(arr,arr+n);

    for(i=1;i<=n;i++)
        bt[i]=INT_MAX;

    int ans=0;
    for(i=0;i<n;i++)
    {
        //cout<<arr[i].ft.ft<<" "<<arr[i].ft.sd<<" "<<arr[i].sd<<" : ";
        int temp = getmin(arr[i].ft.sd - 1);
        //cout<<temp<<endl;

        if(temp>arr[i].sd)
            ans++;
        update(arr[i].ft.sd,arr[i].sd);
    }

    printf("%d\n",ans);

    return 0;
}


















