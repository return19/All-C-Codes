#include<bits/stdc++.h>
using namespace std;

vector<int> abd;

int poss(int x){
    int i,j,k;
    i=0;    j=abd.size()-1;
   // cout<<"here"<<endl;
    while(i<=j){
     //   cout<<i<<" * "<<j<<endl;
        int sum = abd[i] + abd[j];
        if(sum==x){
           // cout<<abd[i]<<" "<<abd[j]<<endl;
            return 1;
        }
        if(sum<x)
            i++;
        else
            j--;
    }
    return 0;
}

int main()
{
    int i,j,k;
    int n;
    int test,t;

    for(i=1;i<100010;i++){
        int ans=0;
        for(j=2;j*j<=i;j++){
            if(i%j==0){
                ans += j + (i/j);
                if(j == i/j)
                    ans -= j;
            }
        }
        ans++;
       // cout<<i<<" "<<ans<<endl;
        if(i < ans)
            abd.push_back(i);
    }

    scanf("%d",&test);

    for(t=0;t<test;t++){
        scanf("%d",&n);
        if(poss(n))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

















