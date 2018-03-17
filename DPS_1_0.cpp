#include<bits/stdc++.h>
using namespace std;

int arr[1000010];

long gcd(long a, long b) {
  long r, i;
  while(b!=0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int find_fib(int a)
{
    int i,j,k;
    arr[0]=0;
    arr[1]=1;
    for(i=2;i<=a;i++)
    {
        arr[i]=(arr[i-1]+arr[i-2])%1000000007;
    }
    return arr[a];
}

int main()
{
    int test,i,j,num1,num2;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d%d",&num1,&num2);
        printf("%d\n",find_fib(gcd(num1,num2)));
        //
    /*for(j=0;j<=gcd(num1,num2);j++)
        cout<<arr[j]<<" ";
        cout<<endl;*/
    }


    return 0;
}
