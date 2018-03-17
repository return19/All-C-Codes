#include<iostream>
using namespace std;
int arr[100010];
int main()
{
    int test,n,m,i,j,sol,loc_g,loc_s;
    int great=0,small=0;

    cin>>test;

    for(i=0;i<test;i++)
    {
        cin>>n;
        cin>>m;
        small=0;
        great=0;
        for(j=0;j<m;j++)
        {
            cin>>sol;
            if(j==0)
            {
                small=sol;
                great=sol;
            }
            if(great<sol)
            {
                great=sol;
            }
            if(small>sol)
            {
                small=sol;
            }

        }
        for(j=0;j<n;j++)
        {
            sol=j;
            loc_g=great-sol;
            loc_s=small-sol;
            if(loc_g<0)
            {
                loc_g=loc_g*(-1);
            }
             if(loc_s<0)
            {
                loc_s=loc_s*(-1);
            }
            if(loc_g>=loc_s)
            {
                sol=loc_g;
            }
            else
            {
                sol=loc_s;
            }
            arr[j]=sol;
            cout<<sol<<" ";
        }
        cout<<endl;
    }
}
