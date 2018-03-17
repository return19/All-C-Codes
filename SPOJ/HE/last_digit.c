#include<stdio.h>

int arr[110],repeat;
void create_pat(int num)
{
    int repeat=0;
    int a=num;
    arr[repeat++]=a;
    num=(num*a)%10;
    while(num!=a)
    {
        arr[repeat++]=num;
        num=(num*a)%10;
    }
}
int main()
{
    int test,i;
    int a,b;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%d",&a);
        scanf("%d",&b);
        a=a%10;
        create_pat(a);
        b=b%repeat;
        printf("%d\n",arr[b-1]);
    }
    return 0;
}
