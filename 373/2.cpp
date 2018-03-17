#include<bits/stdc++.h>
using namespace std;

char arr[101000];
char brr[101000];

int main()
{
    int i,j,k;
    int n;

    scanf("%d",&n);
    scanf("%s",arr);

    int ans1=0;
    int ans2=0;

    int r=0,b=0;

    for(i=0;i<n;i++){ // starts with black
        if(i%2==1){
            if(arr[i]=='b')
                b++;
        } else {
            if(arr[i]=='r')
                r++;
        }
    }

    ans1 = min(r,b) + abs(r-b);


    r=0;    b=0;
    for(i=0;i<n;i++){
        if(i%2==1){
            if(arr[i]=='r')
                b++;
        } else {
            if(arr[i]=='b')
                r++;
        }
    }

    ans2 = min(r,b) + abs(r-b);
    //cout<<ans1<<" "<<ans2<<endl;
    printf("%d\n",min(ans1,ans2));

    return 0;
}

