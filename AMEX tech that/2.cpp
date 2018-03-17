#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

vector< vector< pair< pair<double,double>,double > > > img;
vector< vector< pair< pair<double,double>,double > > > arr;
vector< vector< pair< pair<double,double>,double > > > scaled;

double n1,m1,n2,m2;
double sf;

double check(double x,double y,double a,double b)
{
    if(arr[x][y].ft.ft==scaled[a][b].ft.ft && arr[x][y].ft.sd==scaled[a][b].ft.sd && arr[x][y].sd==scaled[a][b].sd)
        return 1;
    return 0;
}

int main()
{
    double i,j,k;
    double x,y,r,g,b;
    double test,t;
    scanf("%lf",&test);
    scanf("%lf%lf%lf%lf",&n1,&m1,&n2,&m2);
    scanf("%lf",&sf);

    img.resize(n1);

    for(i=0;i<n1;i++)
        img[i].resize(m1);



    arr.resize(n2);
    for(i=0;i<n2;i++){
        arr[i].resize(m2);
    }

    for(i=0;i<n1*m1;i++)
    {
        scanf("%lf%lf%lf%lf%lf",&x,&y,&r,&g,&b);
        img[x][y]=mp(mp(r,g),b);

    }

    for(i=0;i<n2*m2;i++)
    {
        scanf("%lf%lf%lf%lf%lf",&x,&y,&r,&g,&b);
        arr[x][y]=mp(mp(r,g),b);

    }

    scaled.resize(n1*sf);
    for(i=0;i<scaled.size();i++)
    {
        scaled[i].resize(m1*sf);
    }

    for(i=0;i<n1;i++)
    {
        for(j=0;j<m1;j++)
        {
            for(x=i*sf;x<i*sf + sf;x++)
            {

                for(y=j*sf;y<j*sf + sf;y++)
                {
                    scaled[x][y]=img[i][j];
                }
            }
        }
    }

    n1=sf*n1;
    m1=sf*m1;

    for(i=0;i<n2;i++)
    {
        for(j=0;j<m2;j++)
        {
            if(check(i,j,0,0))
            {
                double f=1;
                for(x=0;x<n1;x++)
                {
                    for(y=0;y<m1;y++)
                    {
                        if(x+i>=n2 || y+j >=m2)
                        {
                            f=0;
                            break;
                        }

                        if(!check(x+i,y+j,x,y))
                        {
                            f=0;
                            break;
                        }
                    }
                    if(f==0)
                        break;
                }
                if(f==1)
                {
                    printf("Y\n");
                    printf("%.0lf %.0lf\n",i,j);
                    return 0;
                }
            }
        }

    }

    printf("N\n");

    return 0;
}












