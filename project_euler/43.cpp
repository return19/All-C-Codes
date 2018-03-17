#include<bits/stdc++.h>
using namespace std;

int n;
int arr[10]={2,3,5,7,11,13,17};

void maskIt(int &mask,int pos){
    mask = mask| (1<<pos);
}

int isMasked(int mask,int pos){
    if(mask & (1<<pos))
        return 1;
    return 0;
}

int solve(int idx,int mask,string num){
    cout<<idx<<" "<<num<<endl;
    if(idx == n+1){
        vector<int> v;
        while(num){
            v.push_back(num%10);
            num/=10;
        }

        for(int i=0,j=n-1;i<j;i++,j--)
            swap(v[i],v[j]);

        for(int i=1;i<n-1;i++){
            int temp = v[i]*100 + v[i+1]*10 + v[i+2];
            if(temp%arr[i-1]!=0)
                return 0;
        }
        return 1;
    }

    int i,j;
    int ans=0;
    for(i=0;i<=n;i++){
        if(!isMasked(mask,i)){
            int temp = mask;
            maskIt(temp,i);
            string s
            ans += solve(idx+1,temp,num + );
        }
    }
    return ans;
}

int main()
{
    int i,j,k;
    scanf("%d",&n);

    int ans = solve(0,0,0);
    printf("%d\n",ans);

    return 0;
}
