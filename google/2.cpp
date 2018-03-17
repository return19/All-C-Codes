#include<bits/stdc++.h>
using namespace std;
int arr1[100005];
int arr2[100005];
int arr3[100005];
int arr4[100005];
int main()
{
    int i,j,k;
    int test;
    int ans=0;
    int x,y,z;
    scanf("%d",&test);



    for(int i=0;i<test;i++)
    {
    	scanf("%d%d%d",&x,&y,&z);

    	for(j=0;j<x;j++)
            scanf("%d",&arr1[j]);

    	for(j=0;j<y;j++)
            scanf("%d",&arr2[j]);

    	for(j=0;j<z;j++)
            scanf("%d",&arr3[j]);


    	for(j=0;j<y;j++)
    	{
    		for(k=j+1;k<z;k++)
    		{
    			if(arr3[k]>arr2[j])
                    arr4[j]++;
    		}
    	}

        ans=0;

    	for(j=0;j<x;j++)
    	{
    		for(k=j+1;k<y;k++)
    		{
    			if(arr2[k]>arr1[j])
                    ans=ans + arr4[k];
    		}
    	}


    	for(j=0;j<y;j++)
            arr4[j]=0;

    	printf("%d\n",ans);
    }

    return 0;
}
