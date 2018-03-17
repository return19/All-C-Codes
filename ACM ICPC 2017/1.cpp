#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test,t;
    int x,y,a,b;
    scanf("%d",&test);

    for(t=0;t<test;t++){
        scanf("%d%d%d%d",&x,&y,&a,&b);

        if(x==a){
            if(y<b){
                printf("up\n");
            } else{
                printf("down\n");
            }
        } else if(y==b){
            if(x<a){
                printf("right\n");
            } else {
                printf("left\n");
            }
        } else {
            printf("sad\n");
        }
    }
    return 0;
}
