#include<bits/stdc++.h>
using namespace std;

stack<int> s;

int main(){
    int i,j,k;
    int q;
    int x,y,z;
    int sum=0;
    scanf("%d",&q);

    for(i=0;i<q;i++){
        int t;
        scanf("%d",&t);

        if(t==1){
            scanf("%d",&x);
            s.push(x);
            sum += x;
        } else if(t==2){
            scanf("%d%d",&y,&x);
            sum += (y*x);
            for(j=0;j<y;j++)
                s.push(x);
        } else if(t==3){
            if(s.empty()){
                printf("0\n");
                continue;
            }
            printf("%d\n",s.top());
            sum-= s.top();
            s.pop();
        } else if(t==4){
            int ans=0;
            scanf("%d",&x);
            for(j=0;j<x && !s.empty();j++)
            {
                ans += s.top();
                s.pop();
            }
            sum-= ans;
            printf("%d\n",ans);

        } else { // t==5
            printf("%d\n",sum);
        }
    }
    return 0;
}
