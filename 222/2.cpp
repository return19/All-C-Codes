#include<bits/stdc++.h>
using namespace std;

pair<int,int> arr[501000];

int main()
{
    int i,j,k;
    int n;

    scanf("%d",&n);

    for(i=0;i<2*n;i++){
        scanf("%d%d",&arr[i].first,&arr[i+1].first);
        arr[i].second=0;
        arr[i+1].second=1;
        i++;
    }

    sort(arr,arr+2*n);
    int l=0,r=0;

    for(i=0;i<n;i++){
        if(arr[i].second==0){
            l++;
        }else{
            r++;
        }
    }

    for(i=0;i<n;i++){
        if(i<max(l,n/2))
            printf("1");
        else
            printf("0");
    }
    cout<<endl;

    for(i=0;i<n;i++){
        if(i<max(r,n/2))
            printf("1");
        else
            printf("0");
    }
    cout<<endl;

    return 0;
}

