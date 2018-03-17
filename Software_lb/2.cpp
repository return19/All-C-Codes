#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > test;

char *months[13]={"Jan", "Feb", "March", "april" , "may","june", "july", "august", "sept", "oct", "nov","Dec"};

void generate_test()
{
    int i,j,k;

    test.resize(4*3 + 1);

    for(i=0;i<13;i++){
        test[i].resize(3);
        test[i][0]=15;
        test[i][1]=6;
        test[i][2]=1962;
    }

    int t[10][10]={{1,2,30,31},
            {1,2,11,12},
            {1900,1901,2024,2025}};

    j=0;
    k=-1;
    for(i=0;i<4*3;i++)
    {
        if(i%4==0){
            k++;
            j=0;
        }
        test[i][k]=t[k][j];
        j++;
    }

}

int check_leap(int y)
{
    if(y%4==0)
    {
        if(y%100==0)
        {
            if(y%400==0)
                return 1;
            return 0;
        }
        return 1;
    }
    return 0;
}

int main()
{
    int i,j,k;
    int d,m,y;


    generate_test();
    printf("S.No\tDay\tMonths\tYear\tOutput\n\n");

    for(i=0;i<test.size();i++)
    {
        d=test[i][0];   m=test[i][1];   y=test[i][2];    // declare

        printf("%d\t%d\t%d\t%d\t",i+1,d,m,y);

        if(d<0 || d>31 || m<0 || m>12 || y<1900 || y>2025)
        {
            printf("Invalid inputs\n\n");
            continue;
        }

        if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
        {
            if(d==31)
            {
                d=1;
                if(m==12)
                {
                    m=1;
                    y++;
                }
                else
                    m++;
            }
            else
                d++;
        }
        else
        {
            if(d>30)
            {
                printf("Invalid inputs\n\n");
                continue;
            }

            if(m==2)
            {
                if(d==28)
                {
                    int lp=check_leap(y);
                    if(lp==1)
                    {
                        d++;
                    }
                    else
                    {
                        d==1;
                        m++;
                    }
                }
                else
                    d++;
            }
            else
            {
                if(d==30)
                {
                    d=1;
                    m++;
                }
                else
                    d++;
            }
        }

        printf("%d-%s-%d\n\n",d,months[m-1],y);
    }

    return 0;
}














