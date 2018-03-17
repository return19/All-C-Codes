#include<bits/stdc++.h>
using namespace std;

int arr[1000100];

char str[1000100];

char temp[5];

int main()
{
    int k,l,m;
    int i,j,n;

    scanf("%d%d%d",&k,&l,&m);

    arr[1]=1;
    arr[k]=1;
    arr[l]=1;

    for(i=2;i<=1000010;i++)
    {
        //arr[i]=!(arr[i-1]&arr[i-k]&arr[i-l]);
        if(i==k||i==l)
            continue;

        if(arr[i-1]==0)
        {
            arr[i]=1;
            continue;
        }
        if(i-k>0)
        {
            if(arr[i-k]==0)
            {
                arr[i]=1;
                continue;
            }
        }

        if(i-l>0)
        {
            if(arr[i-l]==0)
            {
                arr[i]=1;
                continue;
            }
        }
    }

    /*for(i=1;i<=10;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;*/

    str[0]='\0';

    for(i=0;i<m;i++)
    {
        scanf("%d",&n);

        if(arr[n])
        {
            temp[0]='A';
            temp[1]='\0';
        }
        else
        {
           temp[0]='B';
            temp[1]='\0';
        }

        strcat(str,temp);

    }

    printf("%s\n",str);

    return 0;
}
