#include<iostream>
using namespace std;


int greatest(int r,int g,int b)
{
    if(r>=g&&r>=b)
    {
        return r;
    }
    else if(g>=b&&g>=r)
    {
        return g;
    }
    return b;
}

    int test;
    int sumR=0,sumG=0,sumB=0,r=0,g=0,b=0,m;
    int rGreat=0,gGreat=0,bGreat=0;

    int i,j;
    int s;
int main()
{

    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>r;
        cin>>g;
        cin>>b;
        cin>>m;
        for(j=0;j<r;j++)
        {
            cin>>s;
            sumR=sumR+s;
            if(rGreat<s)
                rGreat=s;

        }
        for(j=0;j<g;j++)
        {
            cin>>s;
            sumG=sumG+s;
            if(gGreat<s)
                gGreat=s;

        }
        for(j=0;j<b;j++)
        {
            cin>>s;
            sumB=sumB+s;
            if(bGreat<s)
                bGreat=s;

        }

        for(j=0;j<m;j++)
        {
            if(rGreat>=gGreat&&rGreat>=bGreat)
            {
                sumR=sumR/2;
                rGreat=rGreat/2;
            }
            else if(gGreat>=rGreat&&gGreat>=bGreat)
            {
                sumG=sumG/2;
                gGreat=gGreat/2;
            }
            else
            {
                sumB=sumB/2;
                bGreat=bGreat/2;
            }
        }
        cout<<greatest(rGreat,gGreat,bGreat)<<endl;

    }
    return 0;
}
