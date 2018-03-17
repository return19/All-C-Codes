#include<bits/stdc++.h>
using namespace std;



unsigned long long m;

void mul(unsigned long long matrix1[2][2],unsigned long long matrix2[2][2]);
void calc_pow(unsigned long long matrix1[2][2],unsigned long long n);



unsigned long long find_fb(unsigned long long n)
{
  unsigned long long matrix1[2][2] = {{1,1},{1,0}};
  if (n == 0){
    return 0;
  }
  calc_pow(matrix1, n-1);


  return matrix1[0][0];
}


void calc_pow(unsigned long long matrix1[2][2],unsigned long long n)
{
  unsigned long long matrix2[2][2]={{1,1},{1,0}};
  if( n==0||n==1)
    {
      return;
    }


  calc_pow(matrix1, n/2);
  mul(matrix1, matrix1);

  if (n%2 != 0)
  {
     mul(matrix1, matrix2);
  }
}

void mul(unsigned long long matrix1[2][2], unsigned long long matrix2[2][2])
{
  unsigned long long one,two,three,four;

  one=((matrix1[0][0]*matrix2[0][0])%m+(matrix1[0][1]*matrix2[1][0])%m)%m;
  two=((matrix1[0][0]*matrix2[0][1])%m+(matrix1[0][1]*matrix2[1][1])%m)%m;
  three=((matrix1[1][0]*matrix2[0][0])%m+(matrix1[1][1]*matrix2[1][0])%m)%m;
  four=((matrix1[1][0]*matrix2[0][1])%m+(matrix1[1][1]*matrix2[1][1])%m)%m;

  matrix1[0][0] = one;
  matrix1[0][1] = two;
  matrix1[1][0] = three;
  matrix1[1][1] = four;
}

int main()
{
    unsigned long long test,i,j,k,n;
    test=100;
    printf("%llu\n",test);

    for(i=0;i<test;i++)
    {
        scanf("%llu%llu",&n,&m);
        printf("%llu\n",find_fb(n));
    }

    return 0;
}
