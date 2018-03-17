#include<bits/stdc++.h>
using namespace std;

char str[510];

int arr[5];

int pos[5];

void quicksort(int first,int last){
    int pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(arr[i]<=arr[pivot]&&i<last)
                 i++;
             while(arr[j]>arr[pivot])
                 j--;
             if(i<j){
                 temp=arr[i];
                  arr[i]=arr[j];
                  arr[j]=temp;

                  temp=pos[i];
                  pos[i]=pos[j];
                  pos[j]=temp;


             }
         }

         temp=arr[pivot];
         arr[pivot]=arr[j];
         arr[j]=temp;

         temp=pos[pivot];
         pos[pivot]=pos[j];
         pos[j]=temp;

         quicksort(first,j-1);
         quicksort(j+1,last);

    }
}

int main()
{
    int i,j,k;

    int ans;

    scanf("%s",str);
    arr[0]=strlen(str)-2;

    scanf("%s",str);
    arr[1]=strlen(str)-2;

    scanf("%s",str);
    arr[2]=strlen(str)-2;

    scanf("%s",str);
    arr[3]=strlen(str)-2;

    pos[0]=1;
    pos[1]=2;
    pos[2]=3;
    pos[3]=4;

    quicksort(0,3);

   /* for(i=0;i<4;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    for(i=0;i<4;i++)
        cout<<pos[i]<<" ";
    cout<<endl;*/

    int count1=0;

    if(arr[3]>=2*arr[2])
    {
        count1++;

        ans=pos[3];

    }

    if(2*arr[0]<=arr[1])
    {
        count1++;

        ans=pos[0];


    }


    if(count1!=1)
    {
        ans=3;
    }


    if(ans==1)
    {
        printf("A");
    }
    else if(ans==2)
    {
         printf("B");
    }
    else if(ans==3)
    {
         printf("C");
    }
    else
    {
         printf("D");
    }


    return 0;
}



















