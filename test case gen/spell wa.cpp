
#include<bits/stdc++.h>
using namespace std;

int arr[101000];

int main(){
    freopen("input05.txt","r",stdin);
    //freopen("out00.txt","w",stdout);
    int i,j,k;
    int n;
    int test,t;
    scanf("%d",&test);

    for(t=0;t<test;t++){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        //cout<<"Yes\n"<<endl;
        for(i=0;i<n;i++)
        {
            //cout<<arr[i]<<" ";
            while(arr[i]%2==0)  arr[i]/=2;
            while(arr[i]%3==0)  arr[i]/=3;
            while(arr[i]%5==0)  arr[i]/=5;
        }

        int f=0;
        for(i=1;i<n;i++)
            if(arr[i]!=arr[i-1]){
                f=1;
                break;
            }
        if(!f){
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
