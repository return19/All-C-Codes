#include<bits/stdc++.h>
using namespace std;

int arr[101000];
    int n;
void printit(){
    int i;
    for(i=1;i<=n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main()
{
    int i,j,k;


    scanf("%d%d",&n,&k);

    if(k>n-1){
        printf("-1\n");
        return 0;
    }

    for(i=1;i<=n;i++)
        arr[i]=i;

    for(i=k+2;i<=n;i++){
        if(i+1<=n){
            swap(arr[i],arr[i+1]);
            i++;
        }
    }

    if((n-k-1)%2!=0){
        swap(arr[1],arr[n]);
    }

    printit();

    return 0;
}
