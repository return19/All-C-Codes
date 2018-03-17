#include<bits/stdc++.h>
using namespace std;

int arr[101000];
void mergeIt(int arr[],int l,int mid,int r);
void customMergeSort(int arr[],int l,int r)
{
	if(l<r)
	{

	    cout<<"here"<<endl;
		int mid=l + (r-l)/2;
	customMergeSort(arr,l,mid);
	customMergeSort(arr,mid+1,r);
	mergeIt(arr,l,mid,r);
}
}

void mergeIt(int arr[],int l,int mid,int r)
{
    cout<<"in merge"<<endl;
	int i,j,k;

	int temp[r-l+5];
	i=l;
j=mid+1;
k=-1;

	while(i<=mid&&j<r)
{
	if(arr[i]<0)
{
	temp[++k]=arr[i++];
}
else if(arr[j]<0)
{
	temp[++k]=arr[j++];
}
else
	break;
}

while(i<=mid)
	temp[++k]=arr[i++];
while(j<r)
	temp[++k]=arr[j++];
for(i=0;i<=k;i++)
	arr[i+l]=temp[i];

}

int main()
{
	int i,j,k;

	int n;

	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
	scanf("%d",&arr[i]);
}

customMergeSort(arr,0,n-1);

for(i=0;i<n;i++)
	printf("%d ",arr[i]);

return 0;
}

