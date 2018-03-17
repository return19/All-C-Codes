#include<bits/stdc++.h>
using namespace std;

double e[5];
double e_dash[5];

int main()
{
    int i,j,k;
    double max1;

    for(i=0;i<4;i++)
    {
        cin>>e[i];
    }

    for(i=0;i<4;i++)
    {
        cin>>e_dash[i];
    }

    /*for(i=0;i<4;i++)
    {
        printf("%f",e[i]);
    }

    for(i=0;i<4;i++)
    {
        printf("%f",e_dash[i]);
    }*/

    while(e[0]!=-1)
    {
        max1=0;

        for(i=0;i<4;i++)
        {
            if(max1<e[i]/e_dash[i])
            {
                max1=e[i]/e_dash[i];
            }

        }
        //cout<<max1<<endl;
        max1=ceil(max1);
        //cout<<max1<<endl;
        for(i=0;i<4;i++)
        {
            printf("%.0f ",e_dash[i]*max1-e[i]);
        }

        printf("\n");

        for(i=0;i<4;i++)
        {
            cin>>e[i];
        }

        for(i=0;i<4;i++)
        {
            cin>>e_dash[i];
        }
    }

    return 0;
}
