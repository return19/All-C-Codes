#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
    int i,j,k;
    int m=0,c=0;
    int x,y;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        if(x>y){
            m++;
        } else if( y>x){
            c++;
        }
    }

    if(m>c){
        printf("Mishka\n");
        return 0;
    } else if(c>m){
        printf("Chris\n");
        return 0;
    }

    printf("Friendship is magic!^^\n");

    return 0;
}
