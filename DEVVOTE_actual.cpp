#include<bits/stdc++.h>
using namespace std;

double a,b,c;

double arr[10];

int main()
{
    int i,j,k,test;
    int n;

    arr[1]=(double)1;
    arr[2]=(double)2;
    arr[3]=(double)24/12;
    arr[4]=(double)192/108;
    arr[5]=(double)2120/1280;
    arr[6]=(double)31140/18750;
    arr[7]=(double)566202/326592;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%d",&n);

        printf("%.6lf\n",arr[n]);
    }
    return 0;
}
