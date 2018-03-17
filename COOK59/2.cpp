#include<bits/stdc++.h>
using namespace std;

char str[1100000];
long long n;
stack<long long> s;

long long check_bal()
{
    long long i,j,k;



    for(i=0;i<n;i++)
    {
        if(str[i]=='(')
        {
            s.push(1);
        }
        else
        {
            if(s.empty())
            {
                return 0;
            }
            else
            {
                s.pop();
            }
        }
    }

    if(s.empty())
    {
        return 1;
    }

    while(!s.empty())
        s.pop();

    return 0;

}

long long check_type()
{
    long long i,j,k;

    for(i=0;i<n-1;i++)
    {
        if(str[i]=='('&&str[i+1]==')')
        {
            return 1;
        }
        else if(str[i]==')'&&str[i+1]=='(')
        {
            return 2;
        }
    }

    return 0;
}

int main()
{
    long long test,i,j,k;

    long long tp;
    int dif;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%s",str);

        n=strlen(str);

        scanf("%lld",&k);


        if(check_bal()==0)
        {
            if(k==1)
            {
                for(j=0;j<n;j++)
                {
                    printf("%c",str[j]);
                }
                printf("\n");
            }
            else
            {
                printf("-1\n");
            }
        }
        else
        {
            dif=n;
            for(j=1;j<n;j++)
            {
                if(str[j]==str[j-1])
                    dif--;
            }

            if(k>dif)
            {
                printf("-1\n");
            }
            else
            {
                int flag=0;

                for(j=0;j<n;j++)
                {
                    if(str[j]==')')
                    {
                        flag=1;
                        break;
                    }
                }

                if(flag==0)
                {
                    for(j=0;j<n-1;j++)
                    {
                        printf("%c",str[j]);
                    }
                    printf("\n");
                }
                else{

                    int c=k-1;
                    int idx=-1;

                    for(j=0;j<n;j++)
                    {
                        if(str[j]==')'&&!c)
                        {
                            c=100000000;
                            idx=j;
                            break;
                        }
                        else
                        {


                            if(str[j]==')'){
                                c--;
                                while(str[j]==')')
                                    j++;
                            }
                        }


                    }

                    if(idx==-1)
                    {
                        for(j=n-1;j>=0;j--)
                        {
                            if(str[j]=='('&&!c)
                            {
                                idx=j;
                                break;
                            }
                            else
                            {
                                if(str[j]=='('){
                                    c--;
                                    while(str[j]=='(')
                                    j--;
                                }
                            }
                        }
                    }

                    for(j=0;j<n;j++)
                    {
                        if(j!=idx)
                        {
                            printf("%c",str[j]);
                        }
                    }


                    printf("\n");
                }

            }
        }

    }

    return 0;
}











