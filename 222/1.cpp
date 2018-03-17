#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k;
    int a,b;
    int l=0,d=0,r=0;

    scanf("%d%d",&a,&b);

    for(i=1;i<=6;i++){
        if(abs(i-a)<abs(i-b)){
            l++;
        }else if(abs(i-a)==abs(i-b)){
            d++;
        }else{
            r++;
        }
    }

    printf("%d %d %d\n",l,d,r);
    return 0;
}
