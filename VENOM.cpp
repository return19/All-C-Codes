#include<stdio.h>
#include<iostream>
using namespace std;
int h,p,a;

int solve(int y)
{
    int i,j,k;
    long long x=(long long)y;
    long long hf=x/2;


    if(x%2==0)
    {
        if( h + (hf)*a == ((hf)*(hf+1)/2)*p )    return 0;
        else if(h + (hf)*a < ((hf)*(hf+1)/2)*p)    return -1;
        return 1;
    }else{
        hf++;
        if ( h + (hf-1)*a == ((hf)*(hf+1)/2)*p )    return 0;
        else if(h + (hf-1)*a < ((hf)*(hf+1)/2)*p)   return -1;
        return 1;
    }
}

int main()
{
    int i,j,k;
    int test,t;
    scanf("%d",&test);


    for(t=0;t<test;t++)
    {
       scanf("%d%d%d",&h,&p,&a);

        int st=1,ed=100010;
        int mid;
        while(st<=ed)
        {
            mid=st + (ed-st)/2;

            int cur=solve(mid);
            int prev=solve(mid-1);
            int next=solve(mid+1);

           // cout<<mid<<" : "<<prev<<" "<<cur<<" "<<next<<endl;

            if(cur==0 || (prev>0 && cur<0))
            {
                break;
            }

            if(cur>0 && next<=0)
            {
                mid++;
                break;
            }

            if(cur>0)
            {
                st=mid+1;
            }else if(cur<0){
                ed=mid-1;
            }
        }

        printf("%d\n",mid);

    }

    return 0;
}












