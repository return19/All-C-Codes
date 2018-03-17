#include<bits/stdc++.h>
using namespace std;

int arr[110][110];
int arr1[110][110];
int arr2[110][110];
int c,c1;
int R,C;
int n,m;
int ans[11000][4],ANS=-1;
int ans1[11000][4],ANS1=-1;
int sum;

int min1(int a, int b, int c)
{
  int m = a;
  if (m > b)
    m = b;
  if (m > c)
    m = c;
  return m;
}

void printMaxSubSquare()
{
    R=n;
    C=m;

  int i,j;
  int S[110][110];
  int max_of_s, max_i, max_j;


  for(i = 0; i < R; i++)
     S[i][0] = arr1[i][0];


  for(j = 0; j < C; j++)
     S[0][j] = arr1[0][j];


  for(i = 1; i < R; i++)
  {
    for(j = 1; j < C; j++)
    {
      if(arr1[i][j] == 1)
        S[i][j] = min1(S[i][j-1], S[i-1][j], S[i-1][j-1]) + 1;
      else
        S[i][j] = 0;
    }
  }

  max_of_s = S[0][0]; max_i = 0; max_j = 0;
  for(i = 0; i < R; i++)
  {
    for(j = 0; j < C; j++)
    {
      if(max_of_s < S[i][j])
      {
         max_of_s = S[i][j];
         max_i = i;
         max_j = j;
      }
    }
  }

  ans[++ANS][0]=max_i-max_of_s+1;
  ans[ANS][1]=max_j-max_of_s+1;
  ans[ANS][2]=max_i;
  ans[ANS][3]=max_j;
  c++;



  for(i = max_i; i > max_i - max_of_s; i--)
  {
    for(j = max_j; j > max_j - max_of_s; j--)
    {
        arr1[i][j]=0;
        sum=sum-1;
    }

  }
}

void printMaxSubSquare1()
{
    R=n;
    C=m;

  int i,j;
  int S[110][110];
  int max_of_s, max_i, max_j;


  for(i = 0; i < R; i++)
     S[i][0] = arr2[i][0];


  for(j = 0; j < C; j++)
     S[0][j] = arr2[0][j];


  for(i = 1; i < R; i++)
  {
    for(j = 1; j < C; j++)
    {
      if(arr2[i][j] == 1)
        S[i][j] = min1(S[i][j-1], S[i-1][j], S[i-1][j-1]) + 1;
      else
        S[i][j] = 0;
    }
  }

  max_of_s = S[0][0]; max_i = 0; max_j = 0;
  for(i = 0; i < R; i++)
  {
    for(j = 0; j < C; j++)
    {
      if(max_of_s < S[i][j])
      {
         max_of_s = S[i][j];
         max_i = i;
         max_j = j;
      }
    }
  }

  ans1[++ANS1][0]=max_i-max_of_s+1;
  ans1[ANS1][1]=max_j-max_of_s+1;
  ans1[ANS1][2]=max_i;
  ans1[ANS1][3]=max_j;
  c1++;



  for(i = max_i; i > max_i - max_of_s; i--)
  {
    for(j = max_j; j > max_j - max_of_s; j--)
    {
        arr2[i][j]=0;
        sum=sum-1;
    }

  }
}




map<int,int> memo;
map<int,int> taken;
int main()
{
    int test,i,j,k;

    int sum1;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        c=0;
        c1=0;
        sum=0;
        ANS=-1;
        ANS1=-1;
        memo.clear();
        taken.clear();

        scanf("%d%d",&n,&m);

        for(j=0;j<n;j++)
        {
            for(k=0;k<m;k++)
            {
                scanf("%d",&arr[j][k]);

                memo[arr[j][k]]++;

                arr1[j][k]=0;
                arr2[j][k]=1;
            }
        }



        for(j=0;j<n;j++)
        {
            for(k=0;k<m;k++)
            {
                if(taken[arr[j][k]]==memo[arr[j][k]]/2)
                {
                    continue;
                }
                else
                {
                    //printf("%d %d %d %d\n",j+1,k+1,j+1,k+1);
                    arr1[j][k]=1;
                    arr2[j][k]=0;
                    sum=sum+1;
                    taken[arr[j][k]]++;
                }
            }
        }


        sum1=n*m-sum;

        while(sum!=0)
        {
            printMaxSubSquare();
        }

        sum=sum1;
       // cout<<"here"<<endl;
        while(sum!=0)
        {
           // cout<<"inside"<<endl;
            printMaxSubSquare1();
        }

        if(c<=c1){
        printf("%d\n",c);

        for(j=0;j<=ANS;j++)
        {
            printf("%d %d %d %d\n",ans[j][0]+1,ans[j][1]+1,ans[j][2]+1,ans[j][3]+1);
        }
        }
        else
        {
            //cout<<"alt"<<endl;

            printf("%d\n",c1);

            for(j=0;j<=ANS1;j++)
            {
                printf("%d %d %d %d\n",ans1[j][0]+1,ans1[j][1]+1,ans1[j][2]+1,ans1[j][3]+1);
            }
        }


    }

    return 0;
}
