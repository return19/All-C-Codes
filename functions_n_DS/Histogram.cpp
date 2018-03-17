// pass a vector and it will return max area histogram in it
//useful in max area rectangle in matrix of 0s and 1s
int max_histo(vector<int> v)
{
    int i,j;
    stack<int> s;
    int n=v.size();
    int idx,t;
    int max1=0;

    for(i=0;i<n;i++)
    {
       // cout<<v[i]<<" ";

        if(s.empty())
            s.push(i);
        else
        {
            if(v[i]>=v[s.top()])
                s.push(i);
            else
            {
                while(!s.empty()&&v[i]<v[s.top()])
                {
                    idx=s.top();
                    s.pop();


                     if(s.empty())
                    {
                        t=v[idx]*(i);
                        max1=max(max1,t);
                        break;
                    }

                    t=v[idx]*(i-s.top()-1);

                    max1=max(max1,t);


                }

                s.push(i);
            }
        }
    }

   // cout<<endl;

    int x;

    if(!s.empty())
    {


         while(!s.empty())
        {
            idx=s.top();
            s.pop();

            if(s.empty())
            {
                t=v[idx]*(n);
                max1=max(max1,t);
                return max1;
            }

            t=v[idx]*(n-s.top()-1);

            max1=max(max1,t);

        }
    }

    return max1;

}
