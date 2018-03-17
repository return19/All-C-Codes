#include<iostream>
using namespace std;
 void part(int*,int,int);
 int quick(int*,int,int);
 void display(int*,int);

 int main()
 {cout<<"Enter the size of array:";
  int n;
  cin>>n;
  cout<<"\nEnter the array:";

  int a[30],i;
  for(int i=0;i<n;i++)
  cin>>a[i];

  cout<<"\nSorted array:";

  part(a,0,n-1);

  display(a,n-1);
  return 0;
 }

 void part(int *a,int lb,int ub)
 {if(lb<ub)
   {int q=quick(a,lb,ub);
    part(a,lb,q-1);
    part(a,q+1,ub);
   }
 }

 int quick(int *a,int lb,int ub)
 {int i=lb-1;
  int x=a[ub];
  for(int j=lb;j<ub;j++)
  {if(a[j]<=x)
   {i=i+1;
    int t=a[j];
    a[j]=a[i];
    a[i]=t;
   }
  }
  i=i+1;
  a[ub]=a[i];
  a[i]=x;
  return i;
 }

 void display(int *a,int n)
 {cout<<endl;
  for(int i=0;i<=n;i++)
   cout<<a[i]<<"  ";
 }

