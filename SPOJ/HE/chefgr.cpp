#include<iostream>
using namespace std;
int a[105];
int largest(int index)
{
    int g=0,i;
    for(i=0;i<index;i++)
    {
        if(a[i]>a[g])
           {
               g=i;
           }
    }

    return g;

}

int minCount(int index)
{
    int i,c=0,g;
    g=a[largest(index)];

    for(i=0;i<index;i++)
    {
        c+=g-a[i];
    }

    return c;
}

int main()
{
     int test,col,ground,i,j,grdused,grdleft;
     cin>>test;

     for(i=0;i<test;i++)
     {
         cin>>col;
         cin>>ground;
         for(j=0;j<col;j++)
         {
             cin>>a[j];
         }
         grdused=minCount(col);
         grdleft=ground-grdused;
         if(grdleft<0)
         {
             cout<<"No"<<endl;
             continue;
         }

         if(grdleft%col==0)
         {
             cout<<"Yes"<<endl;
         }
         else
         {
             cout<<"No"<<endl;
         }
     }
     return 0;
}
