#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int n,k,i,j,a[1000],c[1000],click1;
    char click[15];
    cin>>n>>k;
    for(i=0;i<n;i++)
        a[i]=0;
    c[0]=0;
    for(i=0;i<k;i++)
    {
        //cin>>click;
        cin>>click;
        if(strcmp(click,"CLOSEALL")==0)
        {
            for(j=0;j<n;j++)
               {
                   a[j]=0;
               }
            c[i]=0;
        }
        else
        { cin>>click1;
            click1--;
            if(a[click1]==0)
                {a[click1]++;
                 c[i]++;
                }
            else
                {a[click1]--;
                 c[i]--;
                }
        }

        c[i+1]=c[i];

    }

    for(i=0;i<k;i++)
        cout<<c[i]<<endl;

    return 0;
}
