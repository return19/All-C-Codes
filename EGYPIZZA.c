/*#include<stdio.h>

int main()
{
    char str[10];
    int frn,one_four=0,one_two=0,thr_four=0,i,sum=0;
    int test;
    scanf("%d",&test);
    while(test--){
    scanf("%d",&frn);
    for(i=0;i<frn;i++)
    {
        scanf("%s",str);
        if(str[2]-'0'==4&&str[0]-'0'==1)
        {
            one_four++;
        }
        else if(str[2]-'0'==2)
        {
            one_two++;
        }
        else
        {
            thr_four++;
        }
    }

    if(one_two%2!=0)
    {
        if(one_four!=0)
        {
            one_four=one_four-2;
        }
        one_two=(one_two/2)+1;
    }
    else
    {
        one_two=one_two/2;
    }

    if(thr_four>=one_four)
        one_four=0;
    else
    {
        one_four=one_four-thr_four;
    }

    if(one_four>0)
    {
        if(one_four%4==0)
        {
            one_four=one_four/4;
        }
        else
        {
            one_four=(one_four/4)+1;
        }
    }
    //sum=sum+thr_four+(one_two)+one_four;
    if(one_four>0)
    {
        sum=sum+one_four;
    }
    sum=sum+thr_four+(one_two);
    printf("%d\n",sum+1);
}
    return 0;

}
*/
#include<stdio.h>

int main()
{
    char str[10];
    int frn,one_four=0,one_two=0,thr_four=0,i,sum=0;
    scanf("%d",&frn);
    for(i=0;i<frn;i++)
    {
        scanf("%s",str);
        if(str[2]-'0'==4&&str[0]-'0'==1)
        {
            one_four++;
        }
        else if(str[2]-'0'==2)
        {
            one_two++;
        }
        else
        {
            thr_four++;
        }
    }

    if(thr_four>=one_four)
        one_four=0;
    else
    {
        one_four=one_four-thr_four;
    }

    if(one_two%2!=0)
    {
        if(one_four!=0)
        {
            one_four=one_four-2;
        }
        one_two=(one_two/2)+1;
    }
    else
    {
        one_two=one_two/2;
    }
    if(one_four!=0)
    {
        if(one_four%4==0)
        {
            one_four=one_four/4;
        }
        else
        {
            one_four=one_four/4+1;
        }
    }
    //sum=sum+thr_four+(one_two)+one_four;
    if(one_four>0)
    {
        sum=sum+one_four;
    }
    sum=sum+thr_four+(one_two);
    printf("%d\n",sum+1);
    return 0;

}

















