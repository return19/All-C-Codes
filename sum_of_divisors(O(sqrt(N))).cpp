# include <stdio.h>
# include <math.h>
# include <stdlib.h>

# define SIZE 200000

inline int readnum(void);
void count(int num);

int pft[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709};

unsigned long long int sum[SIZE];

int k = 0;

inline int readnum(void)
{
int num = 0;
char ch;
while((ch = getchar_unlocked()) != '\n')
{
    if(ch >=48 && ch <=57)
    {
        num = ch -'0' + 10*num;
    }
}
if(num ==0)
{
    return -1;
}
return num;
}

void count(int num)
{
    unsigned int i = 0;
    unsigned long long tmp =0,pfac =1;
    int flag = 0;
    tmp = num;
    sum[k] = 1;
    for(i=0;i<127;i++)
    {
        if((tmp % pft[i]) == 0)
        {
            flag =1;                // For Prime numbers not in pft table
            pfac =1;
            while(tmp % pft[i] == 0)
            {
                tmp =tmp /pft[i];
                pfac *= pft[i];
            }
            pfac *= pft[i];
            sum[k] *= (pfac-1)/(pft[i]-1);
        }
    }
    if(flag ==0)
    {
        sum[k] = 1;
        ++k;
        return;
    }
    if(tmp != 1)                        // For numbers with some prime factors in the pft table+some prime > 705
    {
        sum[k] *=((tmp*tmp) -1)/(tmp -1);
    }
    sum[k] -=num;
    ++k;
    return;
}

    int main(void)
    {
        int i=0,terms =0,num = 0;

        setvbuf(stdin,(char*)NULL,_IOFBF,0);
        scanf("%d",&terms);
        while(getchar_unlocked() != '\n');
        while(terms--)
        {
        num = readnum();
        if(num ==1)
        {
            continue;
        }
        if(num == -1)
        {
            perror("\n ERROR\n");
            return 0;
        }

        count(num);
            }
           i =0;
           while(i<k)
           {
        printf("%lld\n",sum[i]);
        ++i;
            }
            return 0;
    }
