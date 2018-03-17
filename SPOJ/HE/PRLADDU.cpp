#include<iostream>
using namespace std;

int *a=NULL;
unsigned long long total,grass;
void fronttra(long long index)
{
    long long i=0,j=0;
    for(i=0;i<index;i++)
    {

        if(a[i]>0)
        { total-=a[i];

            for(j=i+1;j<index;j++)
            {
                if(a[j]<0)
                {
                    if(a[i]+a[j]>0)
                    {
                        grass+=(a[j])*(j-i);
                        a[i]=a[i]+a[j];
                        a[j]=0;

                        continue;
                    }
                    else
                    {
                        grass+=(a[i])*(j-i);
                        a[j]=a[i]+a[j];
                        a[i]=0;
                        break;
                    }
                }
            }
        }


        if(total==0)
        {
            return;
        }
    }
}

void reartra(long long index)
{
    long long i=0,j=0;
    for(i=index-1;i>=0;i--)
    {

        if(a[i]>0)
        {
            total-=a[i];
            for(j=i-1;j>=0;j++)
            {
                if(a[j]<0)
                {
                    if(a[j]+a[i]>0)
                    {
                        grass+=(a[j])*(i-j);
                        a[i]=a[i]+a[j];
                        a[j]=0;
                        continue;
                    }
                    else
                    {
                        grass+=(a[i])*(i-j);
                        a[j]=a[i]+a[j];
                        a[i]=0;
                        break;
                    }
                }
            }
        }
        if(total==0)
        {
            return;
        }

    }
}

void count(long long index)
{
    long long i=0;
    total=0;
    for(i=0;i<index;i++)
    {
        if(a[i]>0)
        {
            total++;
        }
    }
}

int main()
{
    long long i=0,j=0,test=0,vill=0;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>vill;
        a=new int[vill];
        for(j=0;j<vill;j++)
        {
            cin>>a[j];
        }
        grass=0;
        count(vill);
        fronttra(vill);
        if(total!=0)
        {
            reartra(vill);
        }
        cout<<grass<<endl;
        delete[] a;
    }
    return 0;
}




