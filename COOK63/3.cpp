#include<bits/stdc++.h>
using namespace std;

char str[110][110];

string arr[1100];

void computeLPSArray(char *pat, int M, int *lps);

int KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    // create lps[] that will hold the longest prefix suffix values for pattern
    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;  // index for pat[]

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0;  // index for txt[]
    while (i < N)
    {
      if (pat[j] == txt[i])
      {
        j++;
        i++;
      }

      if (j == M)
      {
        return 1;
        j = lps[j-1];
      }

      // mismatch after j matches
      else if (i < N && pat[j] != txt[i])
      {
        // Do not match lps[0..lps[j-1]] characters,
        // they will match anyway
        if (j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }

    return 0;
    free(lps); // to avoid memory leak
}

void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0;  // lenght of the previous longest prefix suffix
    int i;

    lps[0] = 0; // lps[0] is always 0
    i = 1;

    // the loop calculates lps[i] for i = 1 to M-1
    while (i < M)
    {
       if (pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if (len != 0)
         {
           // This is tricky. Consider the example AAACAAAA and i = 7.
           len = lps[len-1];

           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}

char s[110];

int main()
{
    int test,t,i,j,k;

    int n;

    int l1,ml,mi;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d",&n);

        ml=INT_MAX;

        for(i=0;i<1000;i++)
            arr[i].resize(0);


        for(i=0;i<n;i++)
        {
            scanf("%s",str[i]);

            l1=strlen(str[i]);

            if(ml>l1)
            {
                ml=l1;
                mi=i;
            }
        }

        k=-1;

        for(i=0;i<ml;i++)
        {

            for(j=i;j<ml;j++)
            {
                ++k;
                for(int z=i;z<=j;z++)
                    arr[k].push_back(str[mi][z]);
            }
        }

        sort(arr,arr+k+1);

        /*for(i=0;i<=k;i++)
            cout<<arr[i]<<endl;*/

        int ans=INT_MIN;
        int idx;
        int c=0;

        for(i=0;i<=k;i++)
        {
            l1=arr[i].length();

            c=0;

            for(j=0;j<l1;j++)
                s[j]=arr[i][j];
            s[j]='\0';

            for(j=0;j<n;j++)
            {
                if(j!=mi)
                {
                    int f1=KMPSearch(s,str[j]);

                    if(f1==1)
                    {
                        c++;
                    }
                }
            }

            //cout<<arr[i]<<" "<<c<<endl;

            if(c==n-1)
            {
                if(ans<l1)
                {
                    ans=l1;
                    idx=i;
                }
            }
        }

        if(ans==INT_MIN)
            cout<<endl;
        else
            cout<<arr[idx]<<endl;

    }

    return 0;
}

