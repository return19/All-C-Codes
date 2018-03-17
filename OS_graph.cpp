#include<bits/stdc++.h>
using namespace std;

double vals[110]={0.25,0.25,0.125,0.125,0.125,0.125,0.125,0.125,0.125,0.5,0.5};

double g1=0.3;
double g2=0.1;

double g11=0.4;
double g22=0.2;

double hopes[110][110]={{0,2,1,2,1,2,0,1,0,2,0},
                     {2,0,0,0,2,2,2,1,1,2,0},
                     {1,0,0,1,2,0,0,0,0,0,2},
                     {2,0,1,0,2,0,0,0,0,0,1},
                     {1,2,2,2,0,1,0,1,2,2,1},
                     {2,2,0,0,1,0,2,1,1,1,2},
                     {0,2,0,0,0,2,0,0,1,1,0},
                     {1,1,2,0,1,1,0,0,2,2,2},
                     {0,1,0,0,2,1,1,2,0,1,0},
                     {0,2,0,0,2,1,1,2,1,0,0},
                     {2,0,2,1,1,2,0,2,0,0,0}
                    };

double graph[110][110];

double result[110];

int main()
{
    int i,j,k;
    double sum=0;

    for(i=0;i<11;i++)
    {
        for(j=0;j<11;j++)
        {
            if(j==9||j==10)
            {
                if(hopes[i][j]==1)
                {
                    graph[i][j]=g11;
                }
                else if(hopes[i][j]==2)
                {
                    graph[i][j]=g22;
                }
                else
                {
                    graph[i][j]=0;
                }
                continue;
            }

            if(i!=j)
            {
                if(hopes[i][j]==1)
                {
                    graph[i][j]=g1;
                }
                else if(hopes[i][j]==2)
                {
                    graph[i][j]=g2;
                }
                else
                {
                    graph[i][j]=0;
                }
            }
            else
            {
                graph[i][j]=0;
            }
        }
    }

    for(i=0;i<11;i++)
    {
        sum=0;

        for(j=0;j<11;j++)
        {
            if(i==j)
            {
                sum=sum+vals[i];
                continue;
            }

            sum=sum+graph[i][j]*vals[j];


        }

        result[i]=sum;
    }

    cout<<"Required graph :"<<endl<<endl;

    for(i=0;i<11;i++)
    {
        for(j=0;j<11;j++)
        {
            cout<<graph[i][j]<<"\t";
        }
        cout<<endl;
    }

    cout<<endl<<endl<<"Required parameters :"<<endl<<endl;

    cout<<"s1 "<<" : "<<result[0]<<endl;
    cout<<"s2 "<<" : "<<result[1]<<endl;

    cout<<"n1 "<<" : "<<result[2]<<endl;
    cout<<"n2 "<<" : "<<result[3]<<endl;
    cout<<"n3 "<<" : "<<result[4]<<endl;
    cout<<"n4 "<<" : "<<result[5]<<endl;
    cout<<"n5 "<<" : "<<result[6]<<endl;
    cout<<"n6 "<<" : "<<result[7]<<endl;
    cout<<"n7 "<<" : "<<result[8]<<endl;

    cout<<"d1 "<<" : "<<result[9]<<endl;
    cout<<"d2 "<<" : "<<result[10]<<endl;
    getchar();
    return 0;
}











