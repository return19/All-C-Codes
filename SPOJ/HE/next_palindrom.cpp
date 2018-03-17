#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char a[30],temp[30],temp2[30];
    int i,j,k,x,n,t,mid,flag=0,flag1=0;

    cin>>t;

    for(i=0;i<t;i++)
    {


        flag=0; flag1=0;
        cin>>a;
        n=strlen(a);
        strcpy(temp,a);
        if(n==1)
        {   a[0]++;
            cout<<a<<endl;
            continue;
        }

       for(j=0;j<n-1;j++)
       {
           if(a[j]!=a[j+1])
           {
               flag1=1;
               break;
           }
       }
       if(flag1==0)
       {
           temp2[0]='1';
           for(j=1;j<n;j++)
           {
               temp2[j]='0';

           }
           temp2[j]='1';
           temp2[j+1]=NULL;
           cout<<temp2<<endl;
           continue;
       }
        else
       {

        if(n%2==0)
        {    mid=n/2-1;
          for(j=0;j<n/2-1;j++)
          {
              a[n-j-1]=a[j];
          }
          if(a[mid]>a[mid+1])
          {
              a[mid+1]=a[mid];
          }
          else if(a[mid]<a[mid+1])
          {
              a[mid]++;
              a[mid+1]=a[mid];
          }
          else if(a[mid]==a[mid+1])
          {
              for(j=mid+2;j<n;j++)
              {
                  if(temp[j]<a[j])
                  {
                      flag=1;
                      break;
                  }
                  else if(temp[j]>a[j])
                  {
                      flag=0;
                      break;
                  }
 a[0]='1';
           for(j=1;j<n;j++)
           {
               a[j]='0';

           }
           a[j]='1';
           a[j+1]=NULL;
              }
              if(flag==0)
              {
                  if(a[mid]=='9'&&a[mid+1]=='9')
                  {
                      k=mid-1;
                      while(a[k]=='9'&&k>=0) a[0]='1';
           for(j=1;j<n;j++)
           {
               a[j]='0';

           }
           a[j]='1';
           a[j+1]=NULL;
                      {
                          k--;
                      }
                      a[k]++;
                      a[n-k-1]=a[k];
                      x=k+1;
                      while(x!=n-k-1)
                      {
                          a[x]='0';
                          x++;
                      }
                      a[x]=a[k];
                  }
                  else
                  {a[mid]++;
                  a[mid+1]=a[mid];
                  }
              }
          }
        }
        else
        {   mid=n/2;
            for(j=0;j<n/2;j++)
            {
                a[n-j-1]=a[j];
            }

            for(j=n/2+1;j<n;j++)
            {
                if(temp[j]<a[j])
                {
                    flag=1;
                    break;
                }
                else if(temp[j]>a[j])
                  {
                      flag=0;
                      break;
                  }
            }

            if(flag==0)
            {
                if(a[mid]=='9')
                {
                    j=mid-1;
                    while(a[j]=='9'&&j>=0)
                    {
                        j--;
                    }
                    a[j]++;


                    k=j+1;
                    while(k!=n-j-1)
                    {
                        a[k]='0';
                        k++;
                    }
                    a[k]=a[j];
                }
                else
                {
                    a[mid]++;
                }
            }
        }

    }
    cout<<a<<endl;
    }


    return 0;

}

