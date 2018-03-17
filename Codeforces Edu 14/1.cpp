#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k;
    int n;
    int x;
    scanf("%d",&n);
    int c=0;

    for(i=0;i<n;i++){
        scanf("%d",&x);
        if(x)
            c++;
    }

   // cout<<c<<endl;
  if(n==1 && c==1){
        printf("YES\n");
        return 0;
    }
    if(n==1 && c==0){
        printf("NO\n");
        return 0;
    }

    if(c==n-1){
        printf("YES\n");
        return 0;
    }

    printf("NO\n");

    return 0;
}
