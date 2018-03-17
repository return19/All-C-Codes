#include<iostream>
using namespace std;
void part(int*,int,int);
void merge(int*,int,int,int);
void display(int*,int);
int main()
{cout<<"Enter the no of elements you want to enter:";
 int n;
 cin>>n;
cout<<"Enter the array:";
 int a[100];

 for(int i=0;i<n;i++)
 cin>>a[i];

 cout<<"\nArray after sorting:";

 part(a,0,n-1);

 display(a,n);
return 0;
}

void part(int *a,int lb,int ub)
{int mid;
if(lb<ub)
{
mid=(lb+ub)/2;
part(a,lb,mid);
part(a,mid+1,ub);
merge(a,lb,mid,ub);
}
}

void merge(int *a,int lb,int mid,int ub)
{int i,j,k=lb;
j=mid+1;
int temp[100];

for(i=lb;i<=mid&&j<=ub;k++)
{if(a[i]<=a[j])
 {temp[k]=a[i++];
 }
 else if(a[i]>a[j])
 {temp[k]=a[j++];
 }
}

while(i<=mid)
{temp[k++]=a[i++];
}
while(j<=ub)
{temp[k++]=a[j++];
}

for(i=lb;i<=ub;i++)
{a[i]=temp[i];
}

}

void display(int *a,int ub)
{
for(int i=0;i<ub;i++)
    cout<<a[i]<<"   ";
}
