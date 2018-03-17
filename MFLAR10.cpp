#include<bits/stdc++.h>
using namespace std;

char str[1010];

int main()
{
    int i,j,k,flag,n;
    char start;
    int started;

    str[0]='-';
    str[1]='\0';

    scanf("%[^\n]s",str);
    start=getchar();
    //printf("%s",str);

    while(str[0]!='*')
    {
        if(str[0]=='-'&&str[1]=='\0')
        {

            //cout<<"in "<<str<<endl;
            scanf("%[^\n]s",str);
            start=getchar();
            //cout<<"in "<<str<<endl;
            continue;

        }
        n=strlen(str);
        //cout<<str<<endl;
       // cout<<n<<endl;
        flag=1;
        started=0;

        j=0;
        while(str[j]==' ')
        {
            j++;
        }

        while(str[j]!='\0')
        {
            if(started==0)
                {
                    start=str[j];
                    if(start>=65&&start<=90)
                        start=start+32;
                    started=1;
                }
            else if(str[j]==' ')
            {
                if(str[j+1]==' '){
                    j++;
                    continue;
                }

                if(str[j+1]!=start&&str[j+1]!=start-32&&str[j+1]!='\0')
                        flag=0;

            }

            j++;
        }

        if(flag==0)
        {
            printf("N\n");
        }
        else
        {
            printf("Y\n");
        }
        str[0]='-';
        str[1]='\0';

        scanf("%[^\n]s",str);
        start=getchar();
    }

    return 0;
}
