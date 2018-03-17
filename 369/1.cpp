#include<bits/stdc++.h>
using namespace std;

char arr[1010][5];

int main()
{
    int i,j,k;
    int n;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%s",arr[i]);

    int f=0;
    for(i=0;i<n;i++){
        if(arr[i][0]=='O' && arr[i][1]=='O'){
            arr[i][0] = arr[i][1] = '+';
            f=1;
            break;
        }

        if(arr[i][3]=='O' && arr[i][4]=='O'){
            arr[i][3] = arr[i][4] = '+';
            f=1;
            break;
        }
    }

    if(f){
        printf("YES\n");
        for(i=0;i<n;i++)
        {
            for(j=0;j<5;j++)
                printf("%c",arr[i][j]);
            printf("\n");
        }
    }else {
        printf("NO\n");
    }
    return 0;
}
