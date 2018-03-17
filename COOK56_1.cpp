#include<bits/stdc++.h>
using namespace std;

char str[110];
int arr[110];

char str1[110];
char str2[110];

int main()
{
    int test,i,j,k,l;
    int n;
    int swap1,swap2;
    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        memset(arr,9999,sizeof(arr));
        scanf("%d",&n);

        scanf("%s",str);

        j=0;
        while(str[j]!='\0')
        {
            arr[j]=str[j];

            j++;
        }

        sort(arr,arr+n);

        for(j=0;j<n;j++)
        {
            if(arr[j]!=(str[j]))
            {
                swap1=j;

                break;
            }
        }
        if(j>=n)
        {
            printf("%s\n",str);
            continue;
        }

        for(j=n-1;j>=0;j--)
        {
            if(str[j]==arr[swap1])
            {
                swap2=j;
                break;
            }
        }

       // cout<<"swap1 : "<<swap1<<" swap2 : "<<swap2<<endl;
       int swap3=n;
       for(j=swap1+1;j<n;j++)
       {
           if(str[j]>str[swap1])
            {
                swap3=j;
                break;
            }
       }
      // cout<<"swap3 : "<<swap3<<endl;


        k=-1;
        l=-1;

        for(j=0;j<n;j++)
        {
            if(j==swap1)
            {
                //printf("%c",arr[j]);
               // printf("%c",str[swap1]);
                //cout<<(char)arr[j];
                //cout<<str[swap1];
                str1[++k]=arr[j];
                str1[++k]=str[swap1];

            }
            else if(j==swap2)
            {
                //printf("%c",str[swap1]);
                //str2[++l]=str[j];
                str2[++l]=str[j];
            }
            else if(j==swap3)
            {
                str1[++k]=str[j];


                str2[++l]=str[swap1];
                str2[++l]=str[j];
            }
            else
            {
                //printf("%c",str[j]);
                //cout<<str[j];
                str1[++k]=str[j];
                str2[++l]=str[j];
            }
        }

        if(swap3==n)
        {
            str2[++l]=str[swap1];
        }

        //cout<<endl;
        int flag=1;

        for(j=0;j<n;j++)
        {
            if(str1[j]>str2[j])
            {
                flag=2;
                break;
            }
            else if(str1[j]<str2[j])
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
        {
            for(j=0;j<n;j++)
            {
                printf("%c",str1[j]);
            }
            cout<<endl;
        }
        else
        {
            for(j=0;j<n;j++)
            {
                printf("%c",str2[j]);
            }
            cout<<endl;
        }
    }

    return 0;
}
